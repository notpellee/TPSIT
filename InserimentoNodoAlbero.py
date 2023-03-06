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
        
        
def main():

    lista_key = list(range(0,40,5))

    random.shuffle(lista_key)
    print(lista_key)
    
    albero = Node(lista_key[0])

    for key in lista_key[1:]:
        albero.insertNode(key)
    
    albero.printTree()

if __name__=="__main__":
    main()
