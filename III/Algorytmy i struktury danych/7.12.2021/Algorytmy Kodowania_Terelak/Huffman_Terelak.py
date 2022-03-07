class Node():
	left_node = 0
	right_node = 0
	def __init__(self, left, right):
		self.left_node = left
		self.right_node = right
		return
	def openNode(self):
		return (self.left_node, self.right_node)

def huffman_tree(node, binary_code=""):
	if type(node) is str:
		return {node: binary_code}
	(left, right) = node.openNode()
	d = {}
	# Otwieraj węzły i przeszukuj dane. Jeśli element nie jest znakiem dopisz 0 lub 1 do kodu. Jeśli to znak wypisz zebrany kod binarny
	d.update(huffman_tree(left, binary_code + "1"))
	d.update(huffman_tree(right, binary_code + "0"))
	return d

freq = {} # Częstotliwość występowania znaku w tekście
text = input('Podaj tekst: ')
coded_text = ""

for char in text: # Zlicz ilość poszczególnych znaków
    if char in freq:
        freq[char] += 1
    else:
        freq[char] = 1

freq = sorted(freq.items(), key=lambda x: x[1], reverse=True) # Sortuj częstotliwości malejąco

while len(freq) >= 2:
	# Weź dwa znaki o najmniejszej częstotliwości i połącz węzłem, dodaj do listy i ponownie posortuj listę częstotliwości malejąco
	(char_1, freq_1) = freq[-1]
	(char_2, freq_2) = freq[-2]
	freq = freq[:-2] 
	freq.append((Node(char_1, char_2), freq_1 + freq_2))
	freq = sorted(freq, key=lambda x: x[1], reverse=True)

code = huffman_tree(freq[0][0])

for char in code.keys(): # Wyświetl kod dla danego znaku
	print(char,"->",code[char])
for char in text: # Każdy znak zamień na odpowiadający mu kod
	coded_text += code[char]

print("Zakodowany tekst:", coded_text)