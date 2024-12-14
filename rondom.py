import random
n = int(input())
A = [i for i in range(1,n+1)]
random.shuffle(A)
print(*A)