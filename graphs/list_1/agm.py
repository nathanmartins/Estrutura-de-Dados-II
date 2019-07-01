#!/usr/bin/env python3

# !/usr/bin/env python3

import collections
import string
from pprint import pprint

alphabet = dict(enumerate(string.ascii_lowercase, 0))

visited = list()
agm = list()
prioridades = list()


def get_letter_list(d):
    l = list()
    for item in d:
        l.append(alphabet[item])

    return '->'.join(l)


def depth_first_search(graph, node):
    global visited
    global prioridades
    global agm

    if node not in visited:
        visited.append(node)
        print(visited)

        child = graph.get(node)

        for i, n in enumerate(child, 1):

            lightest = min(child)
            if lightest not in agm:
                agm.append(lightest)

            if n is not None and alphabet[i].upper() not in prioridades and n is not agm:
                prioridades.append(alphabet[i].upper())

        for node in prioridades:
            depth_first_search(graph, node)


if __name__ == '__main__':
    a = {
        "A": [1000, 3, 5, 2, 1000, 1000, 1000, 1, 1000, ],
        "B": [3, 1000, 5, 6, 4, 1000, 6, 6, ],
        "C": [5, 5, 1000, 1000, 1, 7, 9, 1, ],
        "D": [2, 6, 1000, 1000, 12, 1000, 1000, 14],
        "E": [1000, 4, 1, 12, 1000, 1000, 15, 1000, ],
        "F": [1000, 1000, 7, 1000, 1000, 1000, 1000, 9, ],
        "G": [1000, 6, 9, 1000, 15, 1000, 1000, 3, ],
        "H": [1, 1000, 6, 1000, 14, 1000, 9, 3, 1000, ],
    }

    depth_first_search(a, "A")
