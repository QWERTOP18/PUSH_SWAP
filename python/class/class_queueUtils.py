
class QueueUtils:
    @staticmethod
    def rotate(queue):
        if len(queue) < 1:
            print("error: rotate")
        else:
            queue.appendleft(queue.pop())
    
    @staticmethod
    def reverse_rotate(queue):
        if len(queue) < 1:
            print("error: reverseRotate")
        else:
            queue.append(queue.popleft())
    
    @staticmethod
    def swap(queue):
        if len(queue) < 2:
            print("error: swap")
        else:
            queue[0], queue[1] = queue[1], queue[0]
    
    @staticmethod
    def push(source, target):
        if len(source) < 1:
            print("error: push")
        else:
            target.appendleft(source.popleft())
