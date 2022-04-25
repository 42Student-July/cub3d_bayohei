#include "parser.h"
void coner_check(int h,int w,int **memo, bool *check)
{
    if(w < 1 || h < 1 || memo[h + 1] == NULL || memo[h][w + 1] == END)
        return ;
    if(memo[h][w] == OK && memo[h - 1][w] == WALL && memo[h][w - 1] == WALL) //hidariue
    {
        if(memo[h - 1][w - 1] != WALL)
            *check = false;
    }
    if(memo[h][w] == OK && memo[h - 1][w] == WALL && memo[h][w + 1] == WALL) //migiue
    {
        if(memo[h - 1][w + 1] != WALL)
            *check = false;
    }
    if(memo[h][w] == OK && memo[h + 1][w] == WALL && memo[h][w - 1] == WALL) //hidarisita
    {
    if(memo[h + 1][w - 1] != WALL)
            *check = false;
    }
    if(memo[h][w] == OK && memo[h + 1][w] == WALL && memo[h][w + 1] == WALL) //migisita
    {
        if(memo[h + 1][w + 1] != WALL)
            *check = false;
    }
}

void    dfs(t_data *d,int h, int w, int **memo, bool *check)
{
    if(*check == false || h < 0 || w < 0 || \
        memo[h] == NULL ||  memo[h][w] == END || \
        memo[h][w] == WHITESPASE || memo[h][w] == TAB)
    {
        *check = false;
        return ;
    }
    if(memo[h][w] == WALL || memo[h][w] == OK)
        return ;
    memo[h][w] = OK;
    coner_check(h, w, memo, check);
    dfs2(d, h, w, memo, check);
}

void    dfs2(t_data *d, int h, int w, int **memo, bool *check)
{
    if (memo[h + 1] != NULL && w <= (int)array_len(memo[h + 1]))
    {
        if(memo[h + 1][w] != OK)
            dfs(d , h + 1 , w, memo, check);
    }
    else
        *check = false;
    if ( h > 0 && w <= (int)array_len(memo[h - 1]))
    {
        if(memo[h - 1][w] != OK)
            dfs(d, h - 1 , w, memo, check);
    }
    else
        *check = false;
    if (memo[h][w + 1] != OK)
        dfs(d,h, w + 1, memo, check);
    if (memo[h][w - 1] != OK)
        dfs(d,h, w - 1, memo, check);
}

int **copy_map(t_data *d)
{
    size_t size;
    size_t i;
    size_t j;
    int **ret;
    ret = (int **)xmalloc(sizeof(int *) * (d->row + 1));
    i = 0;
    while(d->map[i] != NULL)
    {
        size = array_len(d->map[i]);
        ret[i] = (int *)xmalloc(sizeof(int) * (size + 1));
        ret[i][size] = END;
        j = 0;
        while(d->map[i][j] != END)
        {
            ret[i][j] = d->map[i][j];
            j++;
        }
        i++;
    }
    ret[d->row] = NULL; 
    return (ret);
}

bool dfs_map(t_data *d)
{
    bool check;
    int w;
    int h;
    int **map;
    map = copy_map(d);
    h = 0;
    check = true;
    //printf("h:%d w:%d",h,w);
    while(map[h] != NULL)
    {
        w = 0;
        while(map[h][w] != END)
        {
            if(map[h][w] == FLR || map[h][w] == SOUTH || map[h][w] == WEST \
            || map[h][w] == EAST || map[h][w] == NORTH)
                dfs(d, h, w, map, &check);
            if(!check)
                print_error(BAD_MAP);
            w++;
        }
        h++;
    }
    free_double_ptr_int(&map);
    return (true);
}