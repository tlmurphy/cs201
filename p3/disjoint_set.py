"""Disjoint Set Class"""


class SetNode:

    def __init__(self, val, parent=None):
        self.val = val
        self.parent = parent
        self.rank = 0


class DisjointSet:

    def __init__(self):
        self.head = None

    def makeSet(self, x):
        x.parent = x
        x.rank = 0

    def findSet(self, n):
        if n.parent != n:
            n.parent = self.findSet(n.parent)
        return n.parent

    def same_set(self, s1, s2):
        return self.findSet(s1) == self.findSet(s2)

    def link(self, x, y):
        if x.rank > y.rank:
            y.parent = x
        else:
            x.parent = y
            if x.rank == y.rank:
                y.rank += 1

    def union(self, x, y):
        self.link(self.findSet(x), self.findSet(y))

    def __str__(self):
        return "{" + ", ".join(map(str, self)) + "}"
