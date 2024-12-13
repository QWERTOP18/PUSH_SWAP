class t_list():
    def __init__(self):
        self.list = []
        self.head = 0
        self.size = 0
    
    def swap(self):
        if self.size < 2:
            print("invalid array in swap")
            return
        else:
            up_id = self.head
            down_id = (self.head + 1)%self.size
            self.list[up_id], self.list[down_id] = self.list[down_id], self.list[up_id]