# https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29

class MyQueue:

    def __init__(self):
        self.stk=[]

    def push(self, x: int) -> None:
        self.stk.append(x)

    def pop(self) -> int:
        res=self.stk[0]
        del(self.stk[0])
        return res

    def peek(self) -> int:
        res=self.stk[0]
        return res

    def empty(self) -> bool:
        return len(self.stk)==0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()