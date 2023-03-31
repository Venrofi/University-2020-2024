import socket
import threading

# Ustawienie danych połączenia
# SERVER_IP = input("Podaj adres serwera: ")
# SERVER_PORT = int(input("Podaj port serwera: "))
SERVER_ADDRESS = ('127.0.0.1', 5000)

# Inicjalizacja gniazda
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Wysyłanie wiadomości do serwera
def send_message():
    while True:
        message = input('>')
        client_socket.sendto(message.encode('utf-8'), SERVER_ADDRESS)

# Odbieranie wiadomości od serwera
def receive_message():
    while True:
        data, server = client_socket.recvfrom(2048)
        print(f'Otrzymana odpowiedź od {server}: {data.decode("utf-8")}')

# Połączenie z serwerem
client_socket.sendto('Klient joins'.encode('utf-8'), SERVER_ADDRESS)
print('Połączono z serwerem..')

# Uruchomienie wątków
send_thread = threading.Thread(target=send_message)
receive_thread = threading.Thread(target=receive_message)
send_thread.start()
receive_thread.start()
