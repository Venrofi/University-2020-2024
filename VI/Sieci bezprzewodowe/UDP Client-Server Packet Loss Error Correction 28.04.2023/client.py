import socket
import threading
import random
import time

# Ustawienie danych połączenia
SERVER_IP = '127.0.0.1'
SERVER_PORT = 5000
SERVER_ADDRESS = (SERVER_IP, SERVER_PORT)

BUFFER_SIZE = 2048
CHUNK_SIZE = 512

# Czas oczekiwania na potwierdzenie [s]
ACK_TIMEOUT = 2
# Liczba retransmisji w przypadku braku potwierdzenia
MAX_RETRIES = 5

# Lista pakietów oczekujących na potwierdzenie
waiting_for_ack = []
# Numer sekwencyjny ostatnio wysłanego pakietu
seq_num = 0
# Utracone pakiety
lost_packets = 0

# Inicjalizacja gniazda
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
client_socket.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, BUFFER_SIZE)
client_socket.settimeout(ACK_TIMEOUT)

# Wysyłanie wiadomości do serwera
def send_message():
    TEST_MESSAGE = False
    global seq_num
    global waiting_for_ack
    global lost_packets

    while True:
        message = input('>')

        if(message == 'test'):
            TEST_MESSAGE = True
            # Wiadomość testowa (50000 losowych znaków ASCII)
            message = bytearray([random.randint(32, 126) for _ in range(50000)])
            message = "Sieci bezprzewodowe: ".encode() + message
            print(f'Wysyłam wiadomość o wielkości {len(message)} bajtów..')
            encoded_message = message

        if(TEST_MESSAGE == False):
            encoded_message = bytearray(message, 'utf-8')

        # Podział wiadomości na pakiety
        packets = [encoded_message[i:i+CHUNK_SIZE] for i in range(0, len(encoded_message), CHUNK_SIZE)]
        packet_number = 1

        start_time = time.time()

        # Wysyłanie pakietów i oczekiwanie na potwierdzenia
        for packet in packets:
            retries = 0
            ack_received = False
            while retries < MAX_RETRIES and ack_received == False:
                try:
                    # Dodanie pakietu do listy oczekujących na potwierdzenie
                    waiting_for_ack.append(seq_num)
                    # Wysłanie pakietu
                    client_socket.sendto(packet + seq_num.to_bytes(4, byteorder='big'), SERVER_ADDRESS)
                    print(f'Wysłano pakiet {packet_number} o wielkości {len(packet)} bajtów..')
                    # Oczekiwanie na potwierdzenie
                    while True:
                        data, server = client_socket.recvfrom(BUFFER_SIZE)
                        ack_num = int.from_bytes(data, byteorder='big')
                        # Usunięcie z listy oczekujących na potwierdzenie
                        if ack_num in waiting_for_ack:
                            waiting_for_ack.remove(ack_num)
                            print(f'Odebrano potwierdzenie o numerze sekwencyjnym {ack_num}')
                            ack_received = True
                            break
                except socket.timeout:
                    retries += 1
                    print(f'Czekam na potwierdzenie pakietu {packet_number} ({retries}/{MAX_RETRIES})..')
                    if retries == MAX_RETRIES:
                        # Usunięcie z listy oczekujących na potwierdzenie
                        if seq_num in waiting_for_ack:
                            waiting_for_ack.remove(seq_num)
                        print(f'Nie udało się odebrać potwierdzenia dla pakietu {packet_number} ({MAX_RETRIES} prób)')
                        break
            
            if ack_received: seq_num += 1
            else: 
                lost_packets += 1
                print(f'\nLiczba utraconych pakietów: {lost_packets}..\n')
            packet_number += 1
            waiting_for_ack = []

        end_time = time.time()

        print(f'\nCzas transmisji: {round(end_time - start_time, 2)} s')
        print(f'Liczba utraconych pakietów: {lost_packets}\n')
        TEST_MESSAGE = False

# Odbieranie wiadomości od serwera
def receive_message():
    while True:
        try:
            data, server = client_socket.recvfrom(BUFFER_SIZE)
            if data:
                ack_num = int.from_bytes(data[-4:], byteorder='big')
                print(f'\nOtrzymana odpowiedź od {server}: {data[:-4].decode(encoding="utf-8", errors="ignore")}, {ack_num}')
                # Wysłanie potwierdzenia
                if(ack_num < BUFFER_SIZE):
                    print(f'Wysyłam potwierdzenie o numerze sekwencyjnym {ack_num}..')
                    client_socket.sendto(ack_num.to_bytes(4, byteorder='big'), server)
        except socket.timeout:
            pass


# Połączenie z serwerem
start_message = 'Klient joins... '
encoded_start_message = start_message.encode('utf-8')
client_socket.sendto(encoded_start_message, SERVER_ADDRESS)
print('Połączono z serwerem..')

# Uruchomienie wątków
send_thread = threading.Thread(target=send_message)
receive_thread = threading.Thread(target=receive_message)
send_thread.start()
receive_thread.start()