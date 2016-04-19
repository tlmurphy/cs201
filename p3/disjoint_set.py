"""Disjoint Set Class"""


class Vertex:

    def __init__(self, data, parent=None, rank=0):
        self.data = data
        self.parent = parent
        self.rank = rank

    def __str__(self):
        return str(self.data)


class DisjointSet:

    def __init__(self):
        self.sets_list = {}

    def get_vertex(self, data):
        return self.sets_list[data]

    def makeSet(self, data):
        x = Vertex(data)
        x.parent = x
        self.sets_list[x.data] = x

    def find_repr(self, data):
        return self.findSet(self.sets_list[data]).data

    def findSet(self, n):
        if n.parent != n:
            n.parent = self.findSet(n.parent)
        return n.parent

    def link(self, x, y):
        if x.rank > y.rank:
            y.parent = x
        else:
            x.parent = y
            if x.rank == y.rank:
                y.rank += 1

    def union(self, data1, data2):
        x = self.sets_list[data1]
        y = self.sets_list[data2]
        self.link(self.findSet(x), self.findSet(y))

