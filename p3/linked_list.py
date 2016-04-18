"""Linked List Class for root list"""


class Node:

    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node


class LinkedList:

    def __init__(self, head=None):
        self.head = head

    def __iter__(self):
        probe = self.head
        while probe is not None:
            yield probe.data
            probe = probe.next_node

    def insert(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def __str__(self):
        return "{" + ", ".join(map(str, self)) + "}"
