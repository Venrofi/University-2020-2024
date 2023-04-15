import socket
import threading
import reedsolo
import random

# Ustawienie danych połączenia
SERVER_IP = '127.0.0.1'
SERVER_PORT = 5000
SERVER_ADDRESS = (SERVER_IP, SERVER_PORT)

BUFFER_SIZE = 512
CHUNK_SIZE = 128
CORRECTION_CODES_SIZE = 50

# Inicjalizacja gniazda
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
client_socket.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, BUFFER_SIZE)

# Inicjalizacja obiektu Reed-Solomon
rs = reedsolo.RSCodec(CORRECTION_CODES_SIZE)

# Wysyłanie wiadomości do serwera
def send_message():
    while True:
        message = input('>')
        if(len(message) > CHUNK_SIZE):
            print(f'Wiadomość jest zbyt długa.. (max {CHUNK_SIZE} bajtów). Dzielę na pakiety..')
            encoded_message = bytearray(message, 'utf-8')
            packet_number = 1
            for i in range(0, len(encoded_message), CHUNK_SIZE):
                encoded_message_with_ecc = rs.encode(encoded_message[i:i+CHUNK_SIZE])
                client_socket.sendto(encoded_message_with_ecc, SERVER_ADDRESS)

                print(f'Wysyłam pakiet {packet_number} o wielkości {len(encoded_message_with_ecc)} bajtów..')
                packet_number += 1
            continue

        encoded_message = message.encode('utf-8')
        encoded_message_with_ecc = rs.encode(encoded_message)
        client_socket.sendto(encoded_message_with_ecc, SERVER_ADDRESS)

# Odbieranie wiadomości od serwera
def receive_message():
    sum_of_errors = 0

    while True:
        data, server = client_socket.recvfrom(BUFFER_SIZE)
        try:
            decoded_data = rs.decode(data)
            decoded_message = decoded_data[0].decode(encoding='utf-8', errors='ignore')
            print(f'Otrzymana odpowiedź od {server}: {decoded_message}')
        except reedsolo.ReedSolomonError:
            print("Błąd: nie udało się zdekodować wiadomości..")
            print(f'Otrzymana (błędna) odpowiedź od {server}: {data[:-CORRECTION_CODES_SIZE].decode(encoding="utf-8", errors="ignore")}')
            sum_of_errors += 1

        print(f'\nŁączna liczba błędów: {sum_of_errors}\n')

# Połączenie z serwerem
start_message = 'Klient joins'
encoded_start_message = start_message.encode('utf-8')
encoded_start_message_with_ecc = rs.encode(encoded_start_message)

client_socket.sendto(encoded_start_message_with_ecc, SERVER_ADDRESS)
print('Połączono z serwerem..')

# Wiadomość testowa (50000 losowych znaków ASCII)
encoded_message = bytearray([random.randint(32, 126) for _ in range(50000)])
encoded_message = "Sieci bezprzewodowe: ".encode() + encoded_message

print(f'Wysyłam wiadomość o wielkości {len(encoded_message)} bajtów..')
if(len(encoded_message) > CHUNK_SIZE):
    print(f'Wiadomość jest zbyt długa.. (max {CHUNK_SIZE} bajtów). Dzielę na pakiety..')
    packet_number = 1
    for i in range(0, len(encoded_message), CHUNK_SIZE):
        encoded_message_with_ecc = rs.encode(encoded_message[i:i+CHUNK_SIZE])
        client_socket.sendto(encoded_message_with_ecc, SERVER_ADDRESS)

        print(f'Wysyłam pakiet #{packet_number} o wielkości {len(encoded_message_with_ecc)} bajtów..')
        packet_number += 1
else:
    encoded_message = rs.encode(encoded_message)
    client_socket.sendto(encoded_message, SERVER_ADDRESS)

# Uruchomienie wątków
send_thread = threading.Thread(target=send_message)
receive_thread = threading.Thread(target=receive_message)
send_thread.start()
receive_thread.start()