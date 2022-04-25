#include "parser.h"

void *xmalloc(size_t size)
{
    void *ret;

    ret = malloc(size);
    if(ret == NULL)
        print_error(MALLOC_ERR);
    return (ret);
}

char *ft_xstrdup(char *str)
{
    char *s;
    s = ft_strdup(str);
    if(s == NULL)
        print_error(MALLOC_ERR);
    return (s);
}