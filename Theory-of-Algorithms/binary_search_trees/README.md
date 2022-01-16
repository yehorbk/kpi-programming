# Binary Search Trees
Transform an input binary tree into a binary search tree. Search for amount of
consecutive nodes in a tree. Binary search trees are binary trees that have the
following property: for each node X, the elements in the left subtree will be
less than X, and the elements in the right subtree are greater than X.

## Variant of task
1. Convert an input binary tree into a binary search tree.
On input comes binary tree with a fixed structure (links between nodes, their 
parent, and descendants). You need to overwrite the values ​​of the tree nodes so 
that they corresponded to the following:
a) their new values ​​were taken only from the set present in the input tree;
b) the internal structure of the tree (the links between the parent node and the 
descendant node) was maintained.
2. Searching amounts of consecutive nodes in the tree.
Then, as the input tree is transformed into the binary search tree, the following 
task must be solved. The number S is given in addition. In the binary tree 
search for all monotone paths (which are not necessarily coming from the 
root, but all coming straight down), which sum is equal the number S.
