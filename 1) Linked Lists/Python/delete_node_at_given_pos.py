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

	def delete_node(self, key):
		cur_node = self.head

		if cur_node and cur_node.data == key:
			self.head = cur_node.next
			cur_node = None
			return
		prev = None
		while cur_node and cur_node.data != key:
			prev = cur_node
			cur_node = cur_node.next
		if cur_node is None:
			return
		prev.next = cur_node.next
		cur_node = None

	def delete_node_at_pos(self, pos):
		cur_node = self.head

		if pos == 0:
			self.head = cur_node.next
			cur_node = None
			return

		prev = None
		count = 0
		while cur_node and count != pos:
			prev = cur_node
			cur_node = cur_node.next
			count = count + 1

		if cur_node is None:
			return
		prev.next = cur_node.next
		cur_node = None


llist = LinkedList()
llist.append(1)
llist.append(2)
llist.append(3)
llist.append(4)
llist.append(5)
llist.append("A")
llist.print_list()
print("After deleting the node data at given position")
llist.delete_node_at_pos(2)
llist.print_list()

"""
1
2
3
4
5
A
After deleting the node data at given position
1
2
4
5
A
"""