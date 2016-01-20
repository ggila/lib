# Symbolic table implementation in C


## Several implementation :
![alt-text] (img/Summary.png "Implementation overview")

## API
``` c
t_st	*st_new(void);

void	st_put(t_st *simtab, char *key, void *val);  
void	*st_get(t_st *simtab, char *key);  
void	st_delete(t_st *simtab);

char	st_contains(t_st *simtab, char *key);
char	st_isempty(t_st *simtab);
```

## Conventions
* Values are not _NULL_
* ```st_get()``` returns null if key not present
* ```st_put()``` overwrite old value


## Compare key (char\*) functions
```c ft_strequ(const char *s1, const char *s2);```


<sub>ggilaber@student.42.fr