from collections import deque
##ランダムなアタウイを生成
from process import *
from random import shuffle
N = int(input())
A = deque([i for i in range(N)])
B = deque()
total = 0

shuffle(A)
#
# A = deque([10,0,6,4,8,5,7])
# B = deque()


print("<-----output------->")
print(*A)
print(*B)

# print(A)
# swap(A)
# print(A)
# pushB(A)
# print(A,B)


#aはAに入ってる値
def count(a,B):
    #aに一番近い数を二つ見つける
    diff = 100000000
    #up_id aの次に大きい数のindex
    up_id = -1
    diff1 = 100000000
    #down_id aの次に小さい数のindex
    down_id = -1

    for i in range(len(B)):
        if B[i] > a and B[i] - a < diff:
            diff = B[i] - a
            up_id = i
        if B[i] < a and a - B[i] < diff1:
            diff1 = a - B[i]
            down_id = i
    #print(f"{up_id=}, {down_id=}\n")
    if up_id == -1:
        return down_id
    elif down_id == -1:
        return up_id+1
    else:
        return down_id




"""
ct_A A を正回転させる回数
ct_B を正回転させる回数


"""
def find_index(A,B):
    global total
    mn = 10000000000# 回転の最小回数
    ind_A = -1#bにpushする最適なAのindex
    ind_B = -1
    ct_rr = 0

    for ct_A in range(len(A)):

        temp_ct = 0

        ct_B = count(A[ct_A],B)

        #最後に入れたいとき
        if ct_B == len(B)-1:
            ct_B == 0
        
        #Aを逆回転させたほうがいい場合
        if ct_A * 2 > len(A):
            ct_A -= len(A)

        if ct_B * 2 > len(B):
            ct_B -= len(B)

        if ct_A >= 0 and ct_B >= 0:
            temp_ct = max(ct_A,ct_B)
        elif (ct_A>= 0 and ct_B < 0) or (ct_A < 0 and ct_B >= 0):
            temp_ct = abs(ct_A - ct_B)  # +,- or -,+ だったら足し算
        else:
            temp_ct = max(abs(ct_A),abs(ct_B))

        if temp_ct < mn:
            mn = temp_ct
            ind_A = ct_A
            ind_B= ct_B


    if ind_A >= 0 and ind_B >= 0:
        ct_rr = min(ind_A ,ind_B)
        ind_A -= ct_rr
        ind_B -= ct_rr
    
    if ind_A < 0 and ind_B < 0:
        ct_rr = max(ind_A ,ind_B)
        ind_A -= ct_rr
        ind_B -= ct_rr

    if ct_rr >= 0:
        for i in range(ct_rr):
            Rotate(A)
            Rotate(B)
            print("rr")
            total += 1
    else:
        for i in range(-ct_rr):
            RRotate(A)
            RRotate(B)
            print("rrr")
            total += 1

    if ind_A > 0:
        for i in range(ind_A):
            Rotate(A)
            print("ra")
            total += 1
    else:
        for i in range(-ind_A):
            RRotate(A)
            print("rra")
            total += 1
    if ind_B> 0:
        for i in range(ind_B):
            Rotate(B)
            print("rb")
            total += 1
    else:
        for i in range(-ind_B):
            RRotate(B)
            print("rrb")
            total += 1
    
    pushB(A,B)
    print("pb")
    total += 1
    # print(A,B) 

def solve():
    global total
    pushB(A,B)
    pushB(A,B)
    print("pb")
    print("pb")
    total += 2

    while(len(A) > 0):
        find_index(A,B)
    while(len(B) >0):
        pushA(A,B)
        print("pa")
        total += 1
    # print()
    # print(A,B)
    while(A[0] != 0):
        Rotate(A)
        print("ra")
        total += 1
    # print(A,B)

    print()
    print(f"{total = }")
    
    

solve()


