"""
Use a stack data structure to convert integer values to their corresponding binary representation.
Example : 242
242 / 2 = 121 -> 0
121 / 2 = 60  -> 1
60 / 2  = 30  -> 0
30 / 2  = 15  -> 0
15 / 2  = 7   -> 1
7 / 2 = 3     -> 1
3 / 2 = 1     -> 1
1 / 2 = 0	  -> 1
"""

class Stack():

    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return self.items == []

    def get_stack(self):
        return self.items


def div_by_2(dec_num):
    if dec_num == 0:
        return 0
    s = Stack()

    while dec_num > 0:
        remainder = dec_num % 2
        s.push(remainder)
        dec_num = dec_num // 2

    bin_num = ""
    while not s.is_empty():
        bin_num += str(s.pop())

    return bin_num


print(div_by_2(242))

# 11110010