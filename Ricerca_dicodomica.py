import random

class Node():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
    
    def insertNode(self, key):
        if self.key is not None:
            if key > self.key:
                if self.right is None:
                    self.right = Node(key)
                else:
                    self.right.insertNode(key)
            else:
                if key < self.key:
                    if self.left is None:
                        self.left = Node(key)
                    else:
                        self.left.insertNode(key)
        else:
            self.key = key

    def printTree(self, level = 0):
        if self.left is not None:
            self.left.printTree(level+1)
        print(f"Livello : {level}, key: {self.key}")
    
        if self.right is not None:
            self.right.printTree(level+1)

    def ricercaDicotomica(self, key):
            
            if key > self.key:
                if self.right is None:
                    return f"Nodo {key} non trovato"
                return self.right.ricercaDicotomica(key)
            elif key < self.key:
                if self.left is None:
                    return f"Nodo {key} non trovato"
                return self.left.ricercaDicotomica(key)
            else:
                return f"Nodo {key} trovato"
            


            
    def alberoDicotomico(listaNodi):
        pass
        
        
            

                         
def main():

    lista_key = list(range(0,40,5))

    random.shuffle(lista_key)
    print(lista_key)
    
    albero = Node(lista_key[0])

    for key in lista_key[1:]:
        albero.insertNode(key)
    
    albero.printTree()

    print(albero.ricercaDicotomica(5))

    

    lista_ordinata = lista_key.sort()
    albero1 = Node(int(len(lista_ordinata) / 2))



    albero.alberoDicotomico(lista_ordinata)

if __name__=="__main__":
    main()