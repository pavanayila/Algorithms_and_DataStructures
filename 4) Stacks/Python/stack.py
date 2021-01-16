class Stack():

	def __init__(self):
		self.items = []

	def push(self, item):
		self.items.append(item)

	def pop(self):
		return self.items.pop()

	def get_stack(self):
		return self.items

s = Stack()
s.push("A")
s.push(1)
print(s.get_stack())
s.push("B")
print(s.get_stack())
s.pop()
print(s.get_stack())

"""
['A', 1]
['A', 1, 'B']
['A', 1]
"""