#!/usr/bin/env python3
# Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures.
#
# Author: nsm(Nathan Santos Martins)
# 06/30/2019

from pprint import pprint

graph = dict()


class Node:
	visited = False
	letter = None
	connections = list()

	def __init__(self, letter):
		self.letter = letter


	def connect(self, node):
		self.connections.append(node)

	def __repr__(self):
		return "'{}' visited: {}".format(self.letter, self.visited)


# class Connection:
# 	node_1 = None
# 	node_2 = None


# 	def __init__(self, n1, n2):
# 		self.node_1 = n1
# 		self.node_2 = n2

# 	def __repr__(self):
# 		return "'{}' -- '{}'".format(self.node_1 self.node_2)



# nodes = list()

# for letter in list(map(chr, range(97, 103))):
# 	nodes.append(Node(letter.upper()))

# for node in nodes:
# 	graph[node.letter] = list()


a = Node("A")
b = Node("B")
c = Node("C")

d = Node("D")
e = Node("E")
f = Node("F")


a.connect(d)
a.connect(e)
a.connect(f)

b.connect(d)
b.connect(e)
b.connect(f)

c.connect(d)
c.connect(e)
c.connect(f)


def visit(node):
	
	# print("Visiting node: " + node.letter)

	for connection in node.connections:
		if connection.visited is False:
			print("Visiting: " + connection.letter)
			connection.visited = True

			for cc in connection.connections:
				visit(cc)






visit(a)







