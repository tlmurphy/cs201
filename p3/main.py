import myqueue
import disjoint_set
import edge
import sys
import red_black_tree
import vertex


def read_token(fp, c):
    token = ""
    while not c.isspace() and c != "":
        token += c
        c = fp.read(1)
    return token


def make_edges(path, edges, edge_dict, dis_set):
    temp_list = []
    with open(path, 'r') as f:
        c = f.read(1)
        token = read_token(f, c)
        while c != "":
            if token != "":
                if token == ";":
                    v1 = int(temp_list[0])
                    v2 = int(temp_list[1])
                    if len(temp_list) == 2:  # No weight
                        new_edge = edge.Edge(v1, v2)
                    else:
                        new_edge = edge.Edge(v1, v2, int(temp_list[2]))

                    if (v1, v2) not in edge_dict and (v2, v1) not in edge_dict:
                        edges.append(new_edge)
                        edge_dict[v1, v2] = new_edge.weight

                    if v1 not in dis_set.sets_list:
                        dis_set.makeSet(v1)
                    if v2 not in dis_set.sets_list:
                        dis_set.makeSet(v2)

                    temp_list = []
                else:
                    temp_list.append(token)
            c = f.read(1)
            token = read_token(f, c)

if __name__ == '__main__':

    root = None

    if len(sys.argv) > 2:
        if sys.argv[1] == '-r':
            path = sys.argv[3]
            root = int(sys.argv[2])
        else:
            path = sys.argv[1]
            root = int(sys.argv[3])
    else:
        path = sys.argv[1]

    ftab = open(path, 'r')

    i = 0

    file = ftab.read()
    a_str = ' '.join(file.split()).split()
    for i in a_str:
        pass


    ftab.close()

    # queue = myqueue.MyQueue()
    # edge_list = []
    # dis_set = disjoint_set.DisjointSet()
    # rbt = red_black_tree.RBT()
    # edge_dict = {}
    # make_edges(path, edge_list, edge_dict, dis_set)
    # edge_list = sorted(edge_list, key=lambda edge: edge.weight)
    # final_edge_list = []
    #
    # for e in edge_list:
    #     root_set = dis_set.findSet(dis_set.get_vertex(int(root)))
    #     root1 = dis_set.findSet(dis_set.get_vertex(e.v1))
    #     root2 = dis_set.findSet(dis_set.get_vertex(e.v2))
    #     if root1 != root2:
    #         final_edge_list.append(e)
    #         dis_set.union(e.v1, e.v2)
    #
    # print("0: " + str(root) + ";")
    # level = 1
    # level_str = str(level) + ": "
    # level_list = []
    # next_level = {}
    #
    # weight = 0
    # unreachable = 0
    # for e in final_edge_list:
    #     level_list.append(e)
    #     if e.v1 == root:
    #         level_str = level_str + str(dis_set.sets_list[e.v2]) + "(" + str(root) + ")" + str(e.weight) + "; "
    #         next_level[e.v2] = None
    #         level_list.pop()
    #         weight += e.weight
    #     elif e.v2 == root:
    #         level_str = level_str + str(dis_set.sets_list[e.v1]) + "(" + str(root) + ")" + str(e.weight) + "; "
    #         next_level[e.v1] = None
    #         level_list.pop()
    #         weight += e.weight
    #
    # level += 1
    # print(level_str)
    #
    # while True:
    #     level_str = str(level) + ": "
    #     another_list = []
    #     next_next_level = {}
    #     for e in level_list:
    #         if e.v1 in next_level:
    #             level_str = level_str + str(dis_set.sets_list[e.v2]) + "(" + str(e.v1) + ")" + str(e.weight) + "; "
    #             next_next_level[e.v2] = None
    #             weight += e.weight
    #         elif e.v2 in next_level:
    #             level_str = level_str + str(dis_set.sets_list[e.v1]) + "(" + str(e.v2) + ")" + str(e.weight) + "; "
    #             next_next_level[e.v1] = None
    #             weight += e.weight
    #         else:
    #             another_list.append(e)
    #     if level_list == another_list:
    #         for i in level_list:
    #             unreachable += 2
    #         break
    #     level += 1
    #     level_list = another_list
    #     next_level = next_next_level
    #     print(level_str)
    # print("weight: " + str(weight))
    # print("unreachable: " + str(unreachable))
