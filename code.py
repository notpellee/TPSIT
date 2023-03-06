import queue
coda=queue.Queue()
#enqueue -> put
#dequeue -> get
coda.put(3)
coda.put(5)
coda.put(19)
print(coda.get()) #elimina la testa
print(coda.queue) #stampa la coda rimanente