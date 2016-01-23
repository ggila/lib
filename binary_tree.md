
# binary tree

Index:

* binary tree
* binary heap
* binary search tree
* balance search tree
* red black bst

## binary tree

![alt-text] (img/binary_tree.png "Binary tree")

**Binary Tree**: empty or node with links to left and right binary trees

**Complete Tree**: perfectly balanced, except for bottom level

property of complete binary tree:  
Height of tree eith N nodes is lg N

## binary heap

**Binary Heap**:  
binary tree with two constraints:

* Complete binary tree _(shape property)_
* Parent's key no smaller (or no bigger) than children's key _(heap property)_

**Array representation**:

* Indics start at 1
* Take nodes in level order
* _No explicit links needed !_
* Should use resizing array

**Proposition**:  

* Largest key is a[1]
* Can use array indices to move through tree:
 * Parent of node at k is at k / 2
 * Children ...

**Scenario**:  

* childs become larger than parent (swim)
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

## heapsort

**Basic plan**:

* create max heap with all N keys
 * use bottom-up method
 * cost: < 2N compares and exchanges
* repeatedly remove the maximum key
 * leave in array, instead of nulling out
 * cost < 2N lg N compares and exchanges

[Heapsort Video](https://www.youtube.com/watch?v=_bkow6IykGM "Heapsort")

**Signifiance**:  
In place sorting algo with N log N worst case:

 * mergesort, no, linear extra space
 * quicksort, no, quadratic time in worst case
 * heapsort, *yes*  

**_but_**

 * inner loop longer than quicksort's
 * makes poor use of cache memory
 * Not stable


# Binary search tree

**Definition**:  
A BST is a binary tree in symmetric order

**Symmetric order**:  
Each node has a key, every node's key is:

* Larger than all keys in left subtree
* Smaller than all keys in right subtree

**A node:**

* Key
* Value
* reference to left subtree
* reference to right subtree
* (total of nodes in subtree)

The total of nodes in subtree can help to implement some ordered function such as betwen_value(a, b), but it has to be updated at insertion and deletion.

**Get**  
straight-forward implementation

```
				Pseucode

Value	get_val(Node root, Key key)  
{  
	
	Node x = root;  
	while (x != null) 
	{
		int cmp =  compare(key, x.key)
		if (cmp < 0)
			x = x.left;
		else if (cmp > 0)
			x = x.right;
		else
			return x.val
	}
	return null;
}
```
*Cost*: 1 + lg N 

**Put**  
_(We assume here that count of subtree not present in node)_  

* key in tree: reset value
* Key not in tree: add new node

```
				Pseucode
	
	Node rec_put(Node x, Key key, Value val)
	{
		if (x = null)
			return new_node(key, val);
		int cmp =  compare(key, x.key)
		if (cmp < 0)
			x.left = rec_put(x.left, key, val);
		else if (cmp > 0)
			x.right = rec_put(x.right, key, val);
		else
			x.val = val;
		return x;
	}
	
	void put_node(Node root, Key key, Value val)
	{
		root = rec_put(root, key, val);
	}
```
*we could have used an as efficient and simplier, not recursive algo, but we'll use this one for rb-bst*

**Cost**: 1 + lg N, depends on the way how keys come in, best case when the tree is compltetely balanced

**property**: if N distinct keys are inserted in random order, the _expected height_ of tree is ~ 4,311 ln N, _worst height_ is N

depp deeper: see correspondance between quicksort and bst
see 9.4-9.55

**Subtree counts**
Add in each node the total of nodes in subtree

**Make iterable:**

* traverse left subtree
* enqueue key
* traverse right subtree

**Ordered operation:**  
all ordered operation (min/max, floor/ceilling, rank, ...) cost the height of BST

**Deletion**  
let tombstone is oftenly used but we can do better

Hibbard deletion:  
to delete a node with key _k_, search for node _t_ containing key _k_

* Case 0 children:
 * delete _t_ by setting parent link to _null_
* Case 1 children:
 * delete _t_ by replacing parent link
* Case 2 children:
 * find successor _x_ of _t_ 
 * Delete the minimum in _t_'s right subtree
 * put _x_ in _t_'s spot

**Problem**: lead ton non-symmetric bst

# 2-3 Search Tree

Allow 1 or 2 keys per node, node are either:

* 2-node: 1 key, 2 child
* 3-node: 2 keys, 3 child (one less, one between, one greater: **symmetric order**)

[Insertion in 2-3 is some kind of magic] (https://www.youtube.com/watch?v=coRJrcIYbF4)

**Perfect blance**: every path from root to null link has same length  

**Tree height**:  

* worstcase: lg N (all 2-node)
* bestcase: 0.631 lg N (all 3-node)
* between 12 and 20 for a million nodes
* between 18 and 30 for a billion nodes

Guarantee **logarithmic** time ! **But**, cumbersome implementation:

* Maintaining multiple node type is cumbersome
* Need multiple compares to move down tree
* Need to move back up the tree to split 4-nodes
* Large number cases for splitting

# Red-Black BST

* represent 2-3 tree as a BST
* use internal left leaning links as glue for 3 nodes

equivalent definition:

* No node has 2 red links connected to it
* Every path from root to null link has the same number of black links (2-3 ST are perfectly balanced)
* Red link leans left

**Observation**:  
Search is the same as for elementary BST but runs faster because of better balance

Each node is pointed to by precisely one link -> can encode color of links in node

**Basic operations**:

* rotate left (orient a (temporarily) right-leaning red link to lean left) (considere what happening when insertinging 'C' to rb bst containing only 'A')
* rotate right
* color flip (recolor to split a (temporary) 4-node)

**Basic strategy**: maintin 1-1 correspondence with 2-3 trees by applying elementary red-blak BST operations

**Insertion**

* case 0: insert in 1 node tree
![alt-text] (img/RB_Tree_insert-1-nodes.png "Insert into a tree with exactly 1 nodes")

* case 1: insert in 2 nodes tree 
![alt-text] (img/RB_Tree_insert-2-nodes.png "Insert into a tree with exactly 2 nodes")

* case 2: insert in 3 nodes tree
 * Do standard BST insert; color new link red
 * Rotate to balance the 4-node (if needed)
 * Flip colors to pass red link up one level
 * Rotate to make lean left (if needed)
 * Repeat case 1 or case 2 up the tree (if needed)
![alt-text] (img/RB_Tree_insert-3-nodes.png "Insert into a tree with exactly 2 nodes")

* Recursive code handle all those case:
 * right child red, left child black: rotate left
 * left child and left-left grandchild red: rotate right
 * Both children red: flip colors  
![alt-text] (img/recursive_rb.png "Recursive insertion")

We can upgraded code from bst:

```
	Pseucode
	
	Node rec_put(Node h, Key key, Value val)
	{
		if (h = null)
			return new_node(key, val, RED);                  <   modified
		int cmp =  compare(key, h.key)
		if (cmp < 0)
			h.left = rec_put(h.left, key, val);
		else if (cmp > 0)
			h.right = rec_put(h.right, key, val);
		else
			h.val = val;
		
		if (isRed(h.right) && !isRed(h.left))              - 
			h = rotateLeft(h);                              |
		if (isRed(h.left) && !isRed(h.left.left))           |   added
			h = rotateRihgt(h);                             |
		if (isRed(h.right) && !isRed(h.right))              |
			h = rotateLeft(h);                             -
			
		return h;
	}
	
	void put_node(Node root, Key key, Value val)
	{
		root = rec_put(root, key, val);
	}
```

<sub>ggilaber@student.42.fr