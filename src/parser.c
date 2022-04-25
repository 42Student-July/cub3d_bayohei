#include "parser.h"





void parse_file(t_data *d, char *arg)
{
    char **parsed_cub;
    size_t map_start;

    map_start = 0;
    parsed_cub = get_file_lines(arg);
    if(!check_element(d, parsed_cub, &map_start))
        print_error(FILE_ERR);
    if(!get_map(parsed_cub, map_start, d))
        print_error(BAD_MAP);
    free_double_ptr(&parsed_cub);
    if(!dfs_map(d))
        print_error(BAD_MAP);
    //free_double_ptr_int(&d->map);
    // int i = 0;
    // int j;
    // while(d->map[i] != NULL)
    // {
    //     j =0;
    //     while(d->map[i][j] != END)
    //     {
    //         ft_putnbr_fd(d->map[i][j],1);
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    // }
    //if()
    //checkmap dfs memoka de tansaku   getmap

}