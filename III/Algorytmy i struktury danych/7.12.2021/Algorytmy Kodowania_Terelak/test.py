import sys

def shannon_fano(sequence, binary_code):
	if len(sequence) == 1: # Dziel sekwencję do momentu gdy zostanie w niej tylko jeden element
		return [(sequence[0][0],binary_code)]
	min_dif = sys.maxsize
	split = 0
	for i in range(1,len(sequence)):
		sum_left = sum([y for (x,y) in freq[:i]])
		sum_right = sum([y for (x,y) in freq[i:]])
		if sum_left-sum_right < min_dif: # Znajdź najlepszy punkt podziału sekwencji
			min_dif = abs(sum_left-sum_right)
			split = i
	return shannon_fano(sequence[:split],binary_code+"0")+shannon_fano(sequence[split:],binary_code+"1")

freq = {} # Częstotliwość występowania znaku w tekście
text = input('Podaj tekst: ')
coded_text = ""

for char in text: # Zlicz ilość poszczególnych znaków
	if char in freq:
		freq[char] += 1
	else:
		freq[char] = 1

freq = sorted(freq.items(), key=lambda x: x[1], reverse=True) # Sortuj częstotliwości malejąco
code = dict(shannon_fano(freq,""))

for char in code: # Wyświetl kod dla danego znaku
	print(char,"->", code[char])
for char in text: # Każdy znak zamień na odpowiadający mu kod
	coded_text += code[char]

print("Zakodowany tekst:", coded_text)