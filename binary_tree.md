# binary tree

## binary tree

**Binary Tree**:  
empty or node with links to left and right binary trees

**Complete Tree**:  
perfectly balanced, except for bottom level

property of complete binary tree:  
Height of tree eith N nodes is lg N

# binary heap

**Binary Heap**:  
binary tree with two constraints:

* Complete binary tree (_shape property_)
* Parent's key no smaller (or no bigger) than children's key (heap property)

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

## heapsort

**Basic plan**:

* create max heap with all N keys
 * use bottom-up method
 * cost: < 2N compares and exchanges
* repeatedly remove the maximum key
 * leave in array, instead of nulling out
 * cost < 2N lg N compares and exchanges

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

**Get**  
straight-forward implementation

```
Value	get_val(Node root, Key key)  
{  
	Pseucode
	
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
_We assume here that count of subtree bot present in node_  

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
*Cost*: 1 + lg N, depends on the way how keys come in, best case when the tree is compltetely balanced

**property**: if N distinct keys are inserted in random order, the _expected height_ of tree is ~ 4,311 ln N, _worst heught_ is N

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

Problem: lead ton non-symmetric bst