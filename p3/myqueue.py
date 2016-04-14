"""Queue class"""


class QueueNode:

    def __init__(self, value=None, next=None):
        self.value = value
        self.next = next
        self.rank = 0


class MyQueue:

    def __init__(self):
        self.front = QueueNode()
        self.back = QueueNode()
        self.size = 0

    def __iter__(self):
        probe = self.front
        while probe is not None:
            yield probe.value
            probe = probe.next

    def is_empty(self):
        if self.size == 0:
            return True
        else:
            return False

    def add(self, val):
        temp = QueueNode(val)
        if self.is_empty():
            self.front = self.back = temp
            self.size += 1
            return
        self.back.next = temp
        self.back = temp
        self.size += 1

    def remove(self):
        if self.is_empty():
            raise KeyError("Queue is Empty!")
        self.size -= 1
        if self.front == self.back:
            return_node = self.front.value
            self.front = self.back = None
        else:
            return_node = self.front.value
            self.front = self.front.next
        return return_node

    def __str__(self):
        return "{" + ", ".join(map(str, self)) + "}"
