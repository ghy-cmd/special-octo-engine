
import random
class RandomizedSet:
    def __init__(self):
        self.vec=[]
        self.hash={}
    
    def insert(self, val: int) -> bool:
        if val in self.vec:
            return False
        n=len(self.vec)
        self.hash[val]=n
        self.vec.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.vec:
            return False
        self.vec[self.hash[val]]=self.vec[-1]
        self.hash[self.vec[-1]]=self.hash[val]
        self.vec.pop()
        del self.hash[val]
        return True
    
    def getRandom(self) -> int:
        if len(self.vec)==1:
            return self.vec[0]
        else:
            return random.choice(self.vec)

if __name__=="__main__":
    obj = RandomizedSet()
    param_1 = obj.insert(1)
    param_1 = obj.insert(2)
    param_2 = obj.remove(1)
    param_3 = obj.getRandom()