import socket
import random

# Parametry serwera
# SERVER_IP = input("Podaj adres serwera: ")
# SERVER_PORT = int(input("Podaj port serwera: "))
SERVER_IP = '127.0.0.1'
SERVER_PORT = 5000
PROBABILITY_OF_ERROR = 0.1
BUFFER_SIZE = 2048

print("Szansa na wystąpienie błędu: {}%".format(PROBABILITY_OF_ERROR * 100))
print("Serwer nasłuchuje na {}:{}..".format(SERVER_IP, SERVER_PORT))

# Adresy klientów
client1_address = None
client2_address = None

# Inicjalizacja gniazda
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
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
        print(f"Wiadomość od Klienta 1: ", message.decode())
    elif address == client2_address and client1_address:
        recipient_address = client1_address
        print(f"Wiadomość od Klienta 2: ", message.decode())
    else:
        recipient_address = address

    # Zakłócanie wiadomości
    message = bytearray(message.decode(), 'utf-8')
    for i in range(len(message)):
        if random.random() < PROBABILITY_OF_ERROR:
            print('Wystąpiły zakłócenia! Podmieniono bajt {} na pozycji {}'.format(message[i], i))
            message[i] = random.randint(32, 126)

    # Wysyłanie wiadomości do adresata
    server_socket.sendto(bytes(message), recipient_address)
    print("Wysyłam wiadomość do {}: {}\n".format(recipient_address, bytes(message).decode()))
    