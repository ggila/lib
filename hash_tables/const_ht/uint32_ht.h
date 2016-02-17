#ifndef MACHO_HEADER_H
# define MACHO_HEADER_H

//# include <ft_printf.h>
# include <stdint.h>

/*
** hash_tab with {key, value} known at compile time:
** - fast access with key
** - make OO easy
** - no initialization if data not needed !
** - ultra easy API, just one fonction:
**      - t_value *cht_get(t_key *key);
**
** value is typically a struct containing data related to key.
**
**
** exenple: magic number in mach-ofile
** OS binary store a number at its first byte defining the kind of binary it is.
** We would like to define constant and behaviour for differents kind of binary.
**
**   - key:     
**   uint32_t
**   - value:
**   typedef struct    s_magic_val
**   {
**       const char    *const str
**       const char    *const architecture;
**   }                 t_magic_val;
**
** the following variable is instantiate in "magic.h"
** static t_magic    g_magic = {{{0xfeedface, {"MH_MAGIC", "32-bit"}},
**                             {0xcefaedfe, {"MH_CIGAM", "32-bit"}},
**                             {0xfeedfacf, {"MH_MAGIC_64", "64-bit"}},
**                             {0xcffaedfe, {"MH_CIGAM_64", "64-bit"}},
**                             {0xcafebabe, {"FAT_MAGIC", "fat"}},
**                             {0xbebafeca, {"FAT_CIGAM", "fat"}}},
**                             {0}};
** then you can do:
**   
*/

/*
** (uint32_t key, t_magic_val val}
*/

typedef struct	s_magic_val
{
	const char	*const str;
	const char	*const architecture;
}				t_magic_val;

/*
** magic node
*/

/*
** data
*/

typedef struct			s_magic_data
{
	uint32_t		key;
	t_magic_val		val;
}						t_magic_data;

/*
** htab
*/

# define DATA_MAGIC_SIZE 6
# define HT_MAGIC_SIZE (2 * DATA_MAGIC_SIZE)

typedef struct	s_magic
{
	t_magic_data	_data[DATA_MAGIC_SIZE];
	t_magic_val		*val[HT_MAGIC_SIZE];
}				t_magic;

static t_magic	g_magic = {{{0xfeedface, {"MH_MAGIC", "32-bit"}},
							{0xcefaedfe, {"MH_CIGAM", "32-bit"}},
							{0xfeedfacf, {"MH_MAGIC_64", "64-bit"}},
							{0xcffaedfe, {"MH_CIGAM_64", "64-bit"}},
							{0xcafebabe, {"FAT_MAGIC", "fat"}},
							{0xbebafeca, {"FAT_CIGAM", "fat"}}},
							{0}};

/*
** htab
*/

t_magic_val	*magic_get(uint32_t key);

#endif
