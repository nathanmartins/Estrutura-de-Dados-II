#!/usr/bin/env python3

import collections
import string
from pprint import pprint

alphabet = dict(enumerate(string.ascii_lowercase, 0))

visited = []


def get_letter_list(d):
    l = list()
    for item in d:
        l.append(alphabet[item])

    return '->'.join(l)


def breadth_first_search(graph, root):
    visited, queue = set(), collections.deque([root])

    print("E({}), {}".format(alphabet[root], get_letter_list(queue)))

    while queue:

        vertex = queue.popleft()
        print("D({}), {}".format(alphabet[vertex], get_letter_list(queue)))

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)
                print("E({}), {}".format(alphabet[neighbour], get_letter_list(queue)))

        # pprint(queue)


def depth_first_search(graph, node):
    global visited
    if node not in visited:
        visited.append(node)
        print(get_letter_list(visited))
        for n in graph[node]:
            depth_first_search(graph, n)


def matrix_to_list(matrix):
    graph = {}
    for i, node in enumerate(matrix):
        adj = []
        for j, connected in enumerate(node):
            if connected:
                adj.append(j)
        graph[i] = adj
    return graph


if __name__ == '__main__':
    a = matrix_to_list([
        [0, 0, 0, 1, 1, 1, ],
        [0, 0, 0, 1, 1, 1, ],
        [0, 0, 0, 1, 1, 1, ],
        [1, 1, 1, 0, 0, 0, ],
        [1, 1, 1, 0, 0, 0, ],
        [1, 1, 1, 0, 0, 0, ]
    ])

    b = matrix_to_list([
        [0, 1, 0, 0, 1, 1, 0, 0, 0, 0, ],
        [1, 0, 1, 0, 0, 0, 1, 0, 0, 0, ],
        [0, 1, 0, 1, 0, 0, 0, 1, 0, 0, ],
        [0, 0, 1, 0, 1, 0, 0, 0, 1, 0, ],
        [1, 0, 0, 1, 0, 0, 0, 0, 0, 1, ],
        [1, 0, 0, 0, 0, 0, 0, 1, 1, 0, ],
        [0, 1, 0, 0, 0, 0, 0, 0, 1, 1, ],
        [0, 0, 1, 0, 0, 1, 0, 0, 0, 1, ],
        [0, 0, 0, 1, 0, 1, 1, 0, 0, 0, ],
        [0, 0, 0, 0, 1, 0, 1, 1, 0, 0, ],
    ])

    breadth_first_search(a, 0)
    # breadth_first_search(b, 0)

    # depth_first_search(a, 0)
    # depth_first_search(b, 0)
