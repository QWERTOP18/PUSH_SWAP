from collections import deque
from process import *


print("<-----output------->")
N = int(input())

A = deque(map(int,input().split()))
B = deque(map(int,input().split()))

for i in range(N):
    try:
        query = input()
    except (e) as e:
        print("invalid query")

    
    if query == "ra":
        Rotate(A)
    elif query == "rra":
        RRotate(A)
    elif query == "rb":
        Rotate(B)
    elif query == "rrb":
        RRotate(B)
    elif query == "pa":
        pushA(A,B)
    elif query == "pb":
        pushB(A,B)
    elif query == "rr":
        Rotate(A)
        Rotate(B)
    elif query == "rrr":
        RRotate(A)
        RRotate(B)

print(*A)
print(*B)
