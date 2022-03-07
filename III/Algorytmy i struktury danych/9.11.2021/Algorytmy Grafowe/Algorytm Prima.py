import sys


class Prim:
    def __init__(self, G):
        self.G = G  # Graf z wagami
        self.V = len(self.G) # Wierzchołki
        self.size = len(self.G)
        self.visited = [False] * self.size
        self.num_of_visited = 0
        self.visited[0] = True
        self.pred = [0] * self.size 
        self.k = [0] * self.size # Koszt / waga połączenia
        self.k_sum = 0

    def algorithm(self):
        while (self.num_of_visited < self.V - 1): # Wykonuj dopóki nie odwiedzisz wszystkich wierzchołków
            actual_k = sys.maxsize
            actual_element = 0
            next_element = 0
            for i in range(self.V):
                if (self.visited[i]):
                    for j in range(self.V):
                        if (not self.visited[j] and self.G[i][j]):
                            if (actual_k > self.G[i][j]):
                                actual_element = i
                                next_element = j
                                actual_k = self.G[i][j]
            self.pred[next_element] = actual_element
            self.k[next_element] = actual_k
            print("{0} => {1} : {2}".format(actual_element + 1, next_element + 1, self.k[next_element]))
            self.visited[next_element] = True
            self.num_of_visited += 1
            self.k_sum += self.k[next_element]
        print("  V  ║ Pred ║  K")
        print("═════╬══════╬═════")
        for i in range(self.V):
            print("  {0}  ║   {1}  ║  {2}".format(str(i + 1), str(self.pred[i] + 1), str(self.k[i])))
        print("sum(k) = " + str(self.k_sum))


# neighbourhood matrix
prim = Prim([[0, 3, 0, 3, 5],
                 [3, 0, 5, 1, 0],
                 [0, 5, 0, 2, 0],
                 [3, 1, 2, 0, 1],
                 [5, 0, 0, 1, 0]])
prim.algorithm()


