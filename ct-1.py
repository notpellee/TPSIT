import random
import time

n = 300000
l = [random.uniform(0., 1.) for _ in range(n)]


start_time = time.time()

maxnum = l[0]
for elem in l:
    if(elem > maxnum):
        maxnum = elem

end_time = time.time()
print(f"massimo = {maxnum}")


print(f"durata dell algoritmo: {end_time-start_time}")