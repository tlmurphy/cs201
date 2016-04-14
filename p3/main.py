import myqueue
import disjoint_set
import edge
import sys
import red_black_tree


def read_token(fp, c):
    token = ""
    while not c.isspace() and c != "":
        token += c
        c = fp.read(1)
    return token


def make_edges(path, edges, D):
    temp_list = []
    with open(path, 'r') as f:
        c = f.read(1)
        token = read_token(f, c)
        while c != "":
            if token != "":
                if ";" in token:
                    token = token.replace(";", "")
                    if token != "":
                        temp_list.append(token)
                    if len(temp_list) == 2:  # No weight
                        new_edge = edge.Edge(int(temp_list[0]), int(temp_list[1]))
                    else:
                        new_edge = edge.Edge(int(temp_list[0]), int(temp_list[1]), int(temp_list[2]))
                    if (new_edge.v1, new_edge.v2) not in D:
                        edges.append(new_edge)
                        D[new_edge.v1, new_edge.v2] = new_edge.weight
                    temp_list = []
                else:
                    temp_list.append(token)
            c = f.read(1)
            token = read_token(f, c)

if __name__ == '__main__':
    edge_list = []
    rbt = red_black_tree.RBT()
    D = {}
    make_edges(sys.argv[1], edge_list, D)
    edge_list = sorted(edge_list, key=lambda edge: edge.weight)
