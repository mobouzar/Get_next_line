# Get_next_line

The goal is to make a function which reads a single line from a file descriptor, assuming it isn't being tampered with in between calls to the function.

It must fit in one source file and one header. Mine works with multiple file descriptors. It also has no memory leaks.

# Compiling

`make` -C libft/

`gcc` your C project `libft/libft.a` `get_next_line.c`

# Usage

```c
#include "get_next_line.h"
char *line;

// To get a single line
get_next_line(fd, &line);
ft_putstr(line);
...
ft_strdel(&line); // You should free after you're done using your line

// To read a whole file
while (get_next_line(fd, &line))
{
	// process the line here, here we'll just output it
	ft_putstr(line);
	
	// free the line to avoid leaking memory
	ft_strdel(&line);
}

// GNL will automatically free appropriately whenever it reaches EOF.
```
