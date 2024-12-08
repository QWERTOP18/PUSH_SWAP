def Rotate(arr):
    if len(arr) == 0:
        print("invalid array in r")
        exit()
    else:
        temp = arr.popleft()
        arr.append(temp)
        #print("rr")

def RRotate(arr):
    if len(arr) == 0:
        print("invalid array in rr")
        exit()
    else:
        temp = arr.pop()
        arr.appendleft(temp) 
        #print("RR")


def swap(arr):
    if len(arr) < 2:
        print("invalid array in sw")
        exit()
    else:
        arr[0], arr[1] = arr[1], arr[0]
        print("swap")

def pushA(A,B):
    if len(B) == 0:
        print("invalid array in pa")
        exit()
    else:
        A.appendleft(B.popleft())

def pushB(A,B):
    if len(A) == 0:
        print("invalid array in pb")
        exit()
    else:
        B.appendleft(A.popleft())
