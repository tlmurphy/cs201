import myqueue
"""Red Black Tree Class"""


class TreeNode:

    def __init__(self, value, parent, id):
        self.value = value
        self.LC = None
        self.RC = None
        self.parent = parent
        self.id = id
        self.black = False
        self.red = False

    def uncle(self):
        if self.parent.is_left_child():
            return self.grandparent().RC
        else:
            return self.grandparent().LC

    def grandparent(self):
        return self.parent.parent

    def sibling(self):
        if self.is_left_child():
            return self.parent.RC
        else:
            return self.parent.LC

    def set_left_child(self, n):
        self.LC = n
        if self.LC is not None:
            self.LC.id = 1

    def set_right_child(self, n):
        self.RC = n
        if self.RC is not None:
            self.RC.id = 2

    def set_black(self):
        self.black = True
        self.red = False

    def set_red(self):
        self.red = True
        self.black = False

    def is_red(self): return self.red

    def is_black(self): return self.black

    def is_root(self):
        return self.id == 0

    def is_left_child(self):
        return self.id == 1

    def is_right_child(self):
        return self.id == 2

    def is_leaf(self):
        return self.LC is None and self.RC is None

    def is_linear(self):
        return ((self.parent.is_right_child() and self.is_right_child())
                or (self.parent.is_left_child() and self.is_left_child()))

    def __str__(self):
        return str(self.value)


class RBT:

    def __init__(self):
        self.size = 0
        self.root = None

    def __contains__(self, item):
        probe = self.root
        while probe is not None:
            if item == probe.value:
                return True
            elif item > probe.value:
                probe = probe.RC
            else:
                probe = probe.LC
        return False

    def __str__(self):
        return self.level_order()

    def set_root(self, n):
        self.root = n
        self.root.id = 0

    def insert(self, edge):
        probe = self.root
        if self.size == 0:
            new_node = TreeNode(edge, None, 0)
            self.root = new_node
            self.size += 1
            self.root.set_black()
            return
        while probe is not None:
            if edge.weight > probe.value.weight:
                if probe.RC is None:
                    new_node = TreeNode(edge, probe, 2)
                    probe.set_right_child(new_node)
                    self.size += 1
                    new_node.set_red()
                    self.insert_fix_up(new_node)
                    return
                else:
                    probe = probe.RC
            else:
                if probe.LC is None:
                    new_node = TreeNode(edge, probe, 1)
                    probe.set_left_child(new_node)
                    self.size += 1
                    new_node.set_red()
                    self.insert_fix_up(new_node)
                    return
                else:
                    probe = probe.LC

    def insert_fix_up(self, n):
        while True:
            if n.is_root():
                break
            if n.parent.is_black():
                break
            if n.uncle() is not None and n.uncle().is_red():
                n.parent.set_black()
                n.uncle().set_black()
                n.grandparent().set_red()
                n = n.grandparent()
            else:
                if not n.is_linear():
                    temp_node = n
                    temp_parent = n.parent
                    self.rotate(n)
                    n = temp_parent
                    n.parent = temp_node
                n.parent.set_black()
                if n.grandparent() is not None:
                    n.grandparent().set_red()
                self.rotate(n.parent)
                break
        self.root.set_black()

    def rotate(self, n):
        if n.is_left_child():
            self.right(n)
        else:
            self.left(n)

    def left(self, n):
        p = n.parent
        p.set_right_child(n.LC)
        if n.LC is not None:
            n.LC.parent = p
        n.parent = p.parent
        n.set_left_child(p)
        if p.parent is None:
            self.set_root(n)
        else:
            if p == p.parent.LC:
                p.parent.set_left_child(n)
            else:
                p.parent.set_right_child(n)
        n.set_left_child(p)
        p.parent = n

    def right(self, n):
        p = n.parent
        p.set_left_child(n.RC)
        if n.RC is not None:
            n.RC.parent = p
        n.parent = p.parent
        n.set_right_child(p)
        if p.parent is None:
            self.set_root(n)
        else:
            if p == p.parent.RC:
                p.parent.set_right_child(n)
            else:
                p.parent.set_left_child(n)
        n.set_right_child(p)
        p.parent = n

    def level_order(self):
        if self.size == 0:
            return "This tree is empty"
        current_level = myqueue.MyQueue()
        next_level = myqueue.MyQueue()
        builder = ""
        builder_help = ""
        current_level.add(self.root)
        level = 1
        while not current_level.is_empty():
            temp = current_level.remove()
            builder_help = builder_help + str(temp) + " "
            if temp.LC is not None:
                next_level.add(temp.LC)
            if temp.RC is not None:
                next_level.add(temp.RC)
            if current_level.is_empty():
                builder = builder + str(level) + ": " + builder_help + "\n"
                builder_help = ""
                level += 1
                current_level = next_level
                next_level = myqueue.MyQueue()
        return builder




