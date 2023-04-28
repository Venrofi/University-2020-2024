import socket
import random
import time

# Parametry serwera
SERVER_IP = '127.0.0.1'
SERVER_PORT = 5000
# SERVER_IP = input("Podaj adres serwera: ")
# SERVER_PORT = int(input("Podaj port serwera: "))
PROBABILITY_OF_ERROR = 0.1
BUFFER_SIZE = 2048

print("Szansa na wystąpienie błędu: {}%".format(PROBABILITY_OF_ERROR * 100))
print("Serwer nasłuchuje na {}:{}..".format(SERVER_IP, SERVER_PORT))

# Adresy klientów
client1_address = None
client2_address = None

# Liczba błędów transmisji
sum_of_errors = 0
# Liczba transmisji
number_of_transmissions = 0

# Inicjalizacja gniazda
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, BUFFER_SIZE)
server_socket.bind((SERVER_IP, SERVER_PORT))

while True:
    # Odbieranie wiadomości
    message, address = server_socket.recvfrom(BUFFER_SIZE)
    
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
        print(f"Wiadomość od Klienta 1: ", message[:-4])
    elif address == client2_address and client1_address:
        recipient_address = client1_address
        print(f"Wiadomość od Klienta 2: ", message[:-4])
    else:
        recipient_address = address

    # Usuwanie pakietów przekraczających 1500 bajtów
    if(len(message) > 1500):
        print("Pakiet przekracza 1500 bajtów i nie zostanie dostarczony..\n")
        continue

    # Gubienie pakietów
    if random.random() < PROBABILITY_OF_ERROR:
        sum_of_errors += 1
        print('Wystąpiły zakłócenia! Pakiet nie został wysłany..')
        print("\nŁączna liczba błędów w transmisji: {}\n".format(sum_of_errors))
        continue

    # Opóźnienie wysłania pakietu
    delay_time = len(message) * 0.001 # 1ms * liczba bajtów
    time.sleep(delay_time)

    # Wysyłanie wiadomości do adresata
    server_socket.sendto(message, recipient_address)
    number_of_transmissions += 1
    print("Wysyłam wiadomość do {}: {}".format(recipient_address, message))
    print("Długość wiadomości: {} bajtów..".format(len(message)))
    print("\nŁączna liczba transmisji: {}".format(number_of_transmissions))
    print("Łączna liczba błędów w transmisji: {}\n".format(sum_of_errors))
    