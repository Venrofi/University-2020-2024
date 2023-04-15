import socket
import random
import reedsolo

# Parametry serwera
SERVER_IP = '127.0.0.1'
SERVER_PORT = 5000
# SERVER_IP = input("Podaj adres serwera: ")
# SERVER_PORT = int(input("Podaj port serwera: "))
PROBABILITY_OF_ERROR = 0.1
BUFFER_SIZE = 512
CORRECTION_CODES_SIZE = 50

print("Szansa na wystąpienie błędu: {}%".format(PROBABILITY_OF_ERROR * 100))
print("Serwer nasłuchuje na {}:{}..".format(SERVER_IP, SERVER_PORT))

# Adresy klientów
client1_address = None
client2_address = None

# Kody korekcyjne Reed-Solomon
client_correction_codes = None
sum_of_errors = 0

# Inicjalizacja gniazda
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, BUFFER_SIZE)
server_socket.bind((SERVER_IP, SERVER_PORT))

# Inicjalizacja obiektu Reed-Solomon
rs = reedsolo.RSCodec(CORRECTION_CODES_SIZE)

while True:
    # Odbieranie wiadomości
    data, address = server_socket.recvfrom(BUFFER_SIZE)
    try:
        decoded_data = rs.decode(data)
        decoded_message = decoded_data[0].decode(encoding='utf-8', errors='ignore')
        client_correction_codes = decoded_data[1][-CORRECTION_CODES_SIZE:]
    except reedsolo.ReedSolomonError:
        print("Błąd: nie udało się zdekodować wiadomości..")
        continue

    # Sprawdzanie adresu i portu klienta wysyłającego wiadomość
    if not client1_address:
        client1_address = address
        print(f"Połączono z Klientem 1: {client1_address}")
    elif not client2_address and address != client1_address:
        client2_address = address
        print(f"Połączono Klientem 2: {client2_address}")
    elif address != client1_address and address != client2_address:
        print("Nieznany nadawca!")
        continue
    
    # Wybieranie adresata wiadomości
    if address == client1_address and client2_address:
        recipient_address = client2_address
        print(f"Wiadomość od Klienta 1: ", decoded_message)
    elif address == client2_address and client1_address:
        recipient_address = client1_address
        print(f"Wiadomość od Klienta 2: ", decoded_message)
    else:
        recipient_address = address

    # Zakłócanie wiadomości
    message = bytearray(decoded_message, 'utf-8')
    number_of_errors = 0
    for i in range(len(message)):
        if random.random() < PROBABILITY_OF_ERROR:
            print('Wystąpiły zakłócenia! Podmieniono bajt {} na pozycji {}'.format(message[i], i))
            message[i] = random.randint(32, 126)
            number_of_errors += 1

    sum_of_errors += number_of_errors
    
    # Wysyłanie wiadomości do adresata
    server_socket.sendto(bytes(message + client_correction_codes), recipient_address)
    print("Wysyłam wiadomość do {}: {}".format(recipient_address, bytes(message).decode(encoding='utf-8', errors='ignore')))
    print("Długość wiadomości: {} bajtów + {} bajtów kodów korekcyjnych. Wystąpiło {} błędów..\n".format(len(bytes(message)), len(bytes(client_correction_codes)), number_of_errors))
    print("\nŁączna liczba błędów w transmisji: {}\n".format(sum_of_errors))
    