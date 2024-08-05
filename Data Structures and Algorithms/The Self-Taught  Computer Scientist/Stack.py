# A stack is an example of a last- in, first- out (LIFO) data structure.
# Stacks have two primary operations: pushing (adding) and popping (removing)
### Stacks can be bounded or unbounded. A bounded stack is a stack that limits how many items you
### can add to it, while an unbounded stack is a stack that does not limit how many elements you can
### add to it.
class Stack:
    def __init__(self):
        self.items = []

    def push(self, data):
        self.items.append(data)

    def pop(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

    def is_empty(self):
        return (self.items == [])

    def peek(self):
        return self.items[-1]


stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)

for i in range(3):
    print(stack.pop())


def check_parentheses(a_string):
    stack = []
    for c in a_string:
        if c == "(":
            stack.append(c)
        if c == ")":
            if len(stack) == 0:
                return False
            else:
                stack.pop()
    return len(stack) == 0

a_string = "(())"
print(f"Result: {check_parentheses(a_string)}")
