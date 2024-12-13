from collections import deque
from random import shuffle
from process import *

N = 100
A = deque([i for i in range(N)])
B = deque()
total = 0

shuffle(A)

# aはAに入ってる値
def count(a, B):
    diff = 100000000
    up_id = -1
    diff1 = 100000000
    down_id = -1

    for i in range(len(B)):
        if B[i] > a and B[i] - a < diff:
            diff = B[i] - a
            up_id = i
        if B[i] < a and a - B[i] < diff1:
            diff1 = a - B[i]
            down_id = i

    if up_id == -1:
        return down_id
    elif down_id == -1:
        return up_id + 1
    else:
        return down_id


def find_index(A, B):
    global total
    mn = 10000000000
    ind_A = -1
    ind_B = -1
    ct_rr = 0

    for ct_A in range(len(A)):
        temp_ct = 0
        ct_B = count(A[ct_A], B)

        if ct_B == len(B) - 1:
            ct_B == 0

        if ct_A * 2 > len(A):
            ct_A -= len(A)

        if ct_B * 2 > len(B):
            ct_B -= len(B)

        if ct_A >= 0 and ct_B >= 0:
            temp_ct = max(ct_A, ct_B)
        elif (ct_A >= 0 and ct_B < 0) or (ct_A < 0 and ct_B >= 0):
            temp_ct = abs(ct_A - ct_B)
        else:
            temp_ct = max(abs(ct_A), abs(ct_B))

        if temp_ct < mn:
            mn = temp_ct
            ind_A = ct_A
            ind_B = ct_B

    if ind_A >= 0 and ind_B >= 0:
        ct_rr = min(ind_A, ind_B)
        ind_A -= ct_rr
        ind_B -= ct_rr

    if ind_A < 0 and ind_B < 0:
        ct_rr = max(ind_A, ind_B)
        ind_A -= ct_rr
        ind_B -= ct_rr

    if ct_rr >= 0:
        for i in range(ct_rr):
            Rotate(A)
            Rotate(B)
            total += 1
    else:
        for i in range(-ct_rr):
            RRotate(A)
            RRotate(B)
            total += 1

    if ind_A > 0:
        for i in range(ind_A):
            Rotate(A)
            total += 1
    else:
        for i in range(-ind_A):
            RRotate(A)
            total += 1

    if ind_B > 0:
        for i in range(ind_B):
            Rotate(B)
            total += 1
    else:
        for i in range(-ind_B):
            RRotate(B)
            total += 1

    pushB(A, B)
    total += 1


def solve():
    global total
    pushB(A, B)
    pushB(A, B)
    total += 2

    while(len(A) > 0):
        find_index(A, B)

    while(len(B) > 0):
        pushA(A, B)
        total += 1

    while(A[0] != 0):
        Rotate(A)
        total += 1
    print(total)
    return(total)


solve()
# test_n = 10
# ans = 0
# for i in range(test_n):
#     total = 0
#     ans += solve()
# print (ans / test_n)
