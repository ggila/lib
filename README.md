# Symbolic table implementation in C

## STRUCT

## API
* t\_st	\*st\_new(void);

* void	st\_put(t\_st \*simtab, char \*key, void \*val);  
* void	\*st\_get(t\_st \*simtab, char \*key);  
* void	st\_delete(t\_st \*simtab);

* char	st\_contains(t\_st \*simtab, char \*key);
* char	st\_isempty(t\_st \*simtab);

## Conventions
* Values are not _NULL_
* st\_get() returns null if key not present
* st\_put() overwrite old value

## Hash functions
* ...
* ...

## Compare key (char\*) functions
* ft\_strequ(const char \*s1, const char \*s2);
* ...

# Lib func
* ...
* ...


