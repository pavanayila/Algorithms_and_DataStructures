class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

	def print_list(self):
		cur_node = self.head
		while cur_node:
			print(cur_node.data)
			cur_node = cur_node.next

	def append(self, data):
		new_node = Node(data)
		if self.head is None:
			self.head = new_node
			return
		last_node = self.head
		while last_node.next:
			last_node = last_node.next
		last_node.next = new_node

	def prepend(self, data):
		new_node = Node(data)
		new_node.next = self.head
		self.head = new_node

	def insert_after_node(self, prev_node, data):
		if not prev_node:
			print("Previous node is not in the list")
			return
		new_node = Node(data)
		new_node.next = prev_node.next
		prev_node.next = new_node

	def len_iterative(self):
		count = 0
		cur_node = self.head
		while cur_node:
			count = count + 1
			cur_node = cur_node.next
		return count

	def len_recursive(self, node):
		if node is None:
			return 0

		return 1 + self.len_recursive(node.next)


	


llist = LinkedList()
llist.append(1)
llist.append(2)
llist.append(3)
llist.append(4)
llist.append(5)
llist.append("A")
llist.print_list()
print("Length of the linked list using iterative approach")
print(llist.len_iterative())
print("Length of the linked list using recursive approach")
print(llist.len_recursive(llist.head))


"""
1
2
3
4
5
A
Length of the linked list using iterative approach
6
Length of the linked list using recursive approach
6
"""