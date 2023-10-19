import random

num = int(input("How much: "))
std = int(input("Standard: "))
rag = int(input("Range: "))

print(num,end='\n')
for i in range(num):
    print(random.randint(std-rag,std+rag),end=' ')