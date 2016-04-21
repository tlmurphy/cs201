""" Edge class used to keep track of vertiex connections
    and edge weight. """


class Edge:

    def __init__(self, v1, v2, weight=1):
        self.v1 = v1
        self.v2 = v2
        self.weight = weight

    def __eq__(self, other):
        return self.v1 == other.v1 and self.v2 == other.v2

    def __gt__(self, other):
        return self.weight > other.weight or self.weight == other.weight

    def __lt__(self, other):
        return self.weight < other.weight

    def __str__(self):
        return "{" + str(self.v1) + " " + str(self.v2) + " " + str(self.weight) + "}"
