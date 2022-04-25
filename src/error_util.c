#include "parser.h"
void free_double_ptr(char ***str)
{
    size_t i;
    i = 0;
    while((*str)[i] != NULL)
    {
        free((*str)[i]);
        (*str)[i] = NULL;
        i++;
    }
    free(*str);
    *str = NULL;
}
void free_double_ptr_int(int ***index)
{
    size_t i;
    i = 0;
    while((*index)[i] != NULL)
    {
        free((*index)[i]);
        (*index)[i] = NULL;
        i++;
    }
    free(*index);
    *index = NULL;
}
void free_null(char **str)
{
    free(*str);
    *str = NULL;
}
void print_error(char *err)
{
    printf("Error\n");
    printf("%s\n",err);
    exit(EXIT_FAILURE);
}