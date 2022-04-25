#include "parser.h"

size_t double_ptr_size(char **str)
{
    size_t i;
    i = 0;
    while(str[i] != NULL)
        i++;
    return (i);
}

bool is_spaces(char *str)
{
    size_t i;
    i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
            i++;
        else
            return (false);
    }
    return (true);
}
size_t array_len(int *arr)
{
    size_t i;
    i = 0;
    while(arr[i] != END)
        i++;
    return (i);
}