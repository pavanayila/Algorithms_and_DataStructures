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

llist = LinkedList()
llist.append(1)
llist.append(2)
llist.append(3)
llist.append(4)
llist.append(5)
llist.append("A")
llist.print_list()
print("Head node contains data")
print(llist.head.data)
print("data that contains after head node")
print(llist.head.next.data)
print("After inserting the node the linked list is")
llist.insert_after_node(llist.head.next, "E")
llist.print_list()

"""
1
2
3
4
5
A
Head node contains data
1
data that contains after head node
2
After inserting the node the linked list is
1
2
E
3
4
5
A
"""