# Hash tables

SAve items in a key-indexed table (index is a function of the key)

**Hash function**: Method for computing array index from key

**Issues**:
* Computing hash function
* Equallity test
* Collision resolution

**Classic space-time tradeoff**:
* No space limitation: trivial hash function with key as index
* No time limitation: trivial collosionresolution with sequential search
* Space and time limitations (aka real world): hashing

## Hash Functions

**Idealistic goal**: scramble the keys uniformly to produce a table index
* Efficiently computable
* Each table index **equally likely** for each key

**Requirement**:  x = y -> f\_hash(x) = f\_hash(y)
**Highly desirable**: x != y -> f\_hash(x) != f\_hash(y)

```

class exemple

	string who
	date when

	int hashfunc()
		int hash = 17
		hash = 31 * hash + who.hashfunc();
		hash = 31 * hash + when.hashfunc()
		return hash

// 31: typically a small prime number
```

*Standard* recipe for user-defined types:
* Combine each significant field using the 31x+ y rule
* if field is a primitive type, use wrapper type hashcode()
* if field is null, return 0
* if field is a reference, use hashcode()
* if field is an array, apply to each entry

Basic rule: Need to use the whole key to compute hash code

**Hash code** return an int (between -2<sup>31</sup> and 2<sup>31</sup>)  
**Hash function** return an int between 0 and M-1 (for use as array index)  
M is typically a prime or e number of 2

```
int hash(key)
{return key.hashcode() % M;}
```
Bug: negative value

```
int hash(key)
{return abs(key.hashcode()) % M;}
```
Bug: 1-in-billion bug

```
int hash(key)
{return (key.hashcode() & 0x7fffffff) % M;}
```
OK

## Collision

Two disincts keys hashing to same index

### Separate chaining

### Linear probing
When a new collides, find next empty slot, and put it here

* Hash: Map key to integer i between 0 and M-1
* Insert: Put at table index i if free; if not, try i+1, i+2, etc...
* Search: search table index i, if occupied but not match, try i+1, i+2, etc

**Note**: Array size M must be greater than number of key-value paired

Proposition: Under uniform hashing assumption, the average number of probes in a linear probing hash table of size M that contains N = a*M key is:
* search hit: ~ 0.5 (1 + 1/(1-a))
* search miss/insert: ~ 0.5 (1 + 1/(1-a)<sup>2</sup>)

**Parameters**:
* M too large: too many empty array entries
* M too small: search time blows up
* Typical choice: a = N/M ~ 0.5

### Separate chaining VS Linear probing

**Separate chaining**:
* Easier to implement delete
* Performance degrades gracefully
* Clustering less sensitive to poorly-design hash function

**Linear probing**:
* Less wasted space
* Better cache performance

### Variant

* Two probe hashing
* Double hashing
* Cuckoo hashing

## Hash tables VS BST

**Hash tables**:
* Simpler to code
* No effective alternative for unordered keys
* Faster for simple keys (a few arithmetic ops versus log N compares)

**BST**:
* Stronger performance guarantee
* Support for ordered ST operations

## Applications

* Set
* Dictionnary client
* Indexing client
* Sparse vectors
