# binary tree

## binary tree

*Binary Tree*
* empty or node with links to left and right binary trees

*Complete Tree*
* perfectly balanced, except for bottom level

property of complete binary tree:  
Height of tree eith N nodes is lg N

# binary heap

*Binary Heap*
Array representation of a heap complete binary tree

*Heap-ordered binary tree*
* Keys in nodes
* Parent's key no smaller than children's key

*Array representation*
* Indics start at 1
* Take nodes in level order
* _No explicit links needed !_
* Should use resizing array

*Proposition*
* Largest key is a[1]
* Can use array indices to move through tree:
 * Parent of node at k is at k / 2
 * Children ...

*Scenario*
* childs become larger thsn parent (swim)
 * exchange key
 * repeat for parent until heap order restored
* insert
 * add node at end, swim it up
 * cost: at most 1 + lg N compares
* parent become larger than parent (sink)
 * exchange key with larger child
 * repeat for parent until heap order restored
* delete max
 * exchange root with node at the end, sink it
 * cost: at most 2 lg N compare

# heapsort

*Basic plan*
* create max heap with all N keys
 * use bottom-up method
 * cost: < 2N compares and exchanges
* repeatedly remove the maximum key
 * leave in array, instead of nulling out
 * cost < 2N lg N compares and exchanges

*Signifiance* In place sorting algo with N log N worst case
 * mergesort, no, linear extra space
 * quicksort, no, quadratic time in worst case
 * heapsort, *yes*
*but*
 * inner loop longer than quicksort's
 * makes poor use of cache memory
 * Not stable
