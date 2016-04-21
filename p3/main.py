""" Main file for Kruskal Project.
    Read in a file containg edges and weights.
    Build disjoint set, sort edges, then union sets
    if they are separate. Once minimum spanning tree is
    found, print a MST based upon a given root, with the tree's total
    weight and number of unreachable vertices. """

import disjoint_set
import edge
import sys


def read_tokens(path):
    with open(path, 'r') as f:
        file_str = f.read()
        token_list = ' '.join(file_str.split()).split()
    return token_list


def make_edges(tokens, edges, edge_dict, dis_set):
    temp_list = []
    for token in tokens:
        if token == ";":
            v1 = int(temp_list[0])
            v2 = int(temp_list[1])
            if len(temp_list) == 2:  # No weight, use default of 1
                new_edge = edge.Edge(v1, v2)
            else:
                new_edge = edge.Edge(v1, v2, int(temp_list[2]))  # Weight is given

            if (v1, v2) not in edge_dict and (v2, v1) not in edge_dict:  # No duplicate edges
                edges.append(new_edge)
                edge_dict[v1, v2] = None

            if v1 not in dis_set.sets_list:
                dis_set.makeSet(v1)
            if v2 not in dis_set.sets_list:
                dis_set.makeSet(v2)
            temp_list = []
        else:
            temp_list.append(token)


def minimum_spanning_tree(dis_set):  # Kruskal's Algorithm
    edge_list = []
    final_edge_list = []
    edge_dict = {}
    make_edges(token_list, edge_list, edge_dict, dis_set)
    edge_list = sorted(edge_list, key=lambda edge: edge.weight)

    for e in edge_list:
        root1 = dis_set.findSet(dis_set.get_vertex(e.v1))
        root2 = dis_set.findSet(dis_set.get_vertex(e.v2))
        if root1 != root2:
            final_edge_list.append(e)
            dis_set.union(e.v1, e.v2)

    return final_edge_list


def print_tree(dis_set, edges):
    print("0: " + str(root) + "; ")

    level = 1
    next_level = {root: None}
    weight = 0
    unreachable = 0
    unreachable_vertices = {}
    while True:
        level_str = str(level) + ": "
        temp_list = []
        next_next_level = {}
        for e in edges:
            if e.v1 in next_level:
                level_str = level_str + str(dis_set.sets_list[e.v2]) + "(" + str(e.v1) + ")" + str(e.weight) + "; "
                next_next_level[e.v2] = None
                weight += e.weight
            elif e.v2 in next_level:
                level_str = level_str + str(dis_set.sets_list[e.v1]) + "(" + str(e.v2) + ")" + str(e.weight) + "; "
                next_next_level[e.v1] = None
                weight += e.weight
            else:
                temp_list.append(e)
        if len(edges) == len(temp_list):  # the edges list keeps shrinking, so stop when temp and edges are equal
            for e in edges:
                unreachable_vertices[e.v1] = None
                unreachable_vertices[e.v2] = None
            unreachable = len(unreachable_vertices)
            break
        level += 1
        edges = temp_list
        next_level = next_next_level
        print(level_str)
    print("weight: " + str(weight))
    print("unreachable: " + str(unreachable))


if __name__ == '__main__':

    given_root = False
    root = 0

    if len(sys.argv) > 2:
        given_root = True
        if sys.argv[1] == '-r':
            path = sys.argv[3]
            root = int(sys.argv[2])
        else:
            path = sys.argv[1]
            root = int(sys.argv[3])
    else:
        path = sys.argv[1]

    token_list = read_tokens(path)
    if not token_list:
        print("weight: 0")
        print("unreachable: 0")
        sys.exit()

    if given_root is False:
        root = int(token_list[0])

    dis_set = disjoint_set.DisjointSet()
    final_edge_list = minimum_spanning_tree(dis_set)
    print_tree(dis_set, final_edge_list)
