from collections import deque
from random import shuffle
from class_queueUtils import QueueUtils

N = 500

def print_func(func):
    def wrapper(self, *args, **kwargs):
        print(f"{func.__name__}")
        return func(self, *args, **kwargs)
    return wrapper

class QUEUE:
    def __init__(self, *args):
        self.queueA = deque()
        self.queueB = deque()
        if args:
            for i in args:
                self.queueA.append(int(i))
        else:
            rand = [i for i in range(1, N+1)]
            shuffle(rand)
            self.queueA.extend(rand)
        self.size = len(self.queueA)

    def find_insert_position(self, a_index) -> int:
        a = self.queueA[a_index]
        B = self.B
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

    def find_pop_position(self)->tuple[int,int,int]:
        A = self.queueA
        B = self.queueB
        mn = 10000000000# 回転の最小回数
        ind_A = -1#bにpushする最適なAのindex
        ind_B = -1
        ind_AB = 0

        for ct_A in range(len(A)):

            temp_rr= 0

            ct_B = self.find_insert_position(ct_A)

            if ct_A * 2 > len(A):
                ct_A -= len(A)

            if ct_B * 2 > len(B):
                ct_B -= len(B)

            if ct_A * ct_B > 0:
                temp_rr = max(ct_A,ct_B) if ct_A > 0 else min(ct_B,ct_A)
            else:
                temp_rr = 0

            # if ct_A >= 0 and ct_B >= 0:
            #     temp_ct = max(ct_A,ct_B)
            # elif (ct_A>= 0 and ct_B < 0) or (ct_A < 0 and ct_B >= 0):
            #     temp_ct = abs(ct_A - ct_B)  # +,- or -,+ だったら足し算
            # else:
            #     temp_ct = max(abs(ct_A),abs(ct_B))

            if abs(ct_A)+abs(ct_B)-abs(temp_rr) < mn:
                mn = abs(ct_A)+abs(ct_B)-abs(temp_rr)
                ind_A = ct_A
                ind_B = ct_B
                ind_AB = temp_rr
        return ind_A, ind_B, ind_AB


    @print_func
    def ra(self): 
        QueueUtils.rotate(self.queueA)
        
    @print_func
    def rra(self): 
        QueueUtils.reverse_rotate(self.queueA)
        
    @print_func
    def sa(self): 
        QueueUtils.swap(self.queueA)
        
    @print_func
    def pa(self): 
        QueueUtils.push(self.queueB, self.queueA)
        
    @print_func
    def rb(self): 
        QueueUtils.rotate(self.queueB)
        
    @print_func
    def rrb(self): 
        QueueUtils.reverse_rotate(self.queueB)
        
    @print_func
    def sb(self): 
        QueueUtils.swap(self.queueB)
        
    @print_func
    def pb(self): 
        QueueUtils.push(self.queueA, self.queueB)
        
    @print_func
    def rr(self):
        QueueUtils.rotate(self.queueA)
        QueueUtils.rotate(self.queueB)
        
    @print_func
    def rrr(self):
        QueueUtils.reverse_rotate(self.queueA)
        QueueUtils.reverse_rotate(self.queueB)
        
    @print_func
    def ss(self):
        QueueUtils.swap(self.queueA)
        QueueUtils.swap(self.queueB)
