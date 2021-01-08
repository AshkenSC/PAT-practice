# 198
'''
1 3 4 5 2


'''

from typing import List

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = [[], []]
        self.current = 0


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q[self.current].append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.q[self.current]) > 1:
            self.q[1 - self.current].append(self.q[self.current].pop(0))
        top = self.q[self.current].pop(0)
        self.current = 1 - self.current
        return top


    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.q[self.current]) > 1:
            self.q[1 - self.current].append(self.q[self.current].pop(0))
        top = self.q[self.current].pop(0)
        self.q[1 - self.current].append(top)
        self.current = 1 - self.current
        return top



    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.q[self.current]) < 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

#sol = Solution()
obj = MyStack()
obj.push(1)
obj.push(2)
a = obj.top()
b = obj.pop()
c = obj.empty()