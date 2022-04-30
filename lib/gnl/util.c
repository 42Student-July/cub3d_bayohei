#include "get_next_line.h"

void	*xmalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		print_error(MALLOC_ERR);
	return (ret);
}