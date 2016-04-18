"""Vertex class (node for disjoint set)"""


class Vertex:

    def __init__(self, data, parent=None, rank=0):
        self.data = data
        self.parent = parent
        self.rank = rank

    def __str__(self):
        return "{" + str(self.data) + ": " + str(self.parent.data) + "}"