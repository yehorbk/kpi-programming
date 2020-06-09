# Greedy Algorithms
Implementation of the greedy algorithm for the traveling salesman task.
Greedy algorithms allow you to quickly find the solution for most tasks. How
ever, the solution they often get is not optimal. Thus, not all tasks are 
guaranteed the existence of a correct greedy algorithm, that is, one that will 
find the optimal solution of the tasks.

## Variant of task
In this task, you need to propose a greedy algorithm for the task of a salesman.
The task of the salesman is formulated for a complete graph. For a weighted 
complete graph G with n vertices, the distances between all pairs of vertices 
(i, j) are given. You need to find the shortest route that runs through all vertices 
of the graph and enters each vertex only once.
In this work, we consider a symmetric variant of the problem when the 
distance from city i to city j is equal to the distance from j to i 
(distance between (i, j) and (j, i) is equal). The task of the salesman belongs to 
the NP-complete tasks and there is no optimal algorithm that would work in 
polynomial time. Therefore, heuristic algorithms are often used to solve it, 
including greedy algorithms.
You need to come up with the idea of ​​a greedy algorithm and test it for 
multiple variants of task.
