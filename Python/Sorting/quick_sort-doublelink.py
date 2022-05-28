head = None


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


def last_node(node):
    while node.next != None:
        node = node.next
    return node


def partition(low, high):
    # set pivot as h element
    x = high.data
    i = low.prev
    j = low

    while j != high:
        if j.data <= x:
            # similar to i++ for array
            i = low if (i == None) else i.next
            temp = i.data
            i.data = j.data
            j.data = temp
        j = j.next

    i = low if (i == None) else i.next
    temp = i.data
    i.data = high.data
    high.data = temp
    return i


# a recursive implementation of QuickSort for linked list
