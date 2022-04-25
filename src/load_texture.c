#include "parser.h"
void set_texture(t_img **img,char *path)
{
    int h;
    int w;
    (void)h,(void)w;
    //*img = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
    //if(img == NULL)
    //   print_error(MLX_ERR);
    //img-> h = h;
    //img -> w =w;
    (void)img;
    (void)path;

}

bool load_texture(t_data *d, char *line, int tex)
{
    char *str;
    char **sp;

    sp = split_and_check_size(line, 2, ' ');
    str = del_newline(sp[1]);
    if(!check_exist(str))
        print_error(BAD_ELEMENT_ERR);
    set_texture(&d->tex_path[tex], str);
    free_double_ptr(&sp);
    free(str);
    return (true);
}
