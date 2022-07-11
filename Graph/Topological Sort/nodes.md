### Introduction
---------
__Topolgical ordering:__ A __topological ordering__ is an ordering of the nodes in a directed graph where for each directed edge from node __A__ to node __B__, node __A__ appears before node __B__ in the ordering.     Topological orderings are not __unique__.

__Topological sort__ algorithm can find a topological ordering in __O(V+E)__ time.
Only Directed Acyclic Graphs can have a valid topological ordering. __Tarjan's Strongly Connected Component__ algorithm can be used to figure out if a graph is acyclic or not.

#### Topological Sort Algorithm
--------

* Pick an unvisited node
* Beginning with the selected node, do a DFS, exploring only unvisited nodes.
* On the recursive callback of the DFS, add the curret node to the topological ordering in reverse order






#### Resources:
--------
Topological Sort Algorithm | Graph Theory by WilliamFiset <https://youtu.be/eL-KzMXSXXI>
