/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/13 16:56:21 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width = 1281;
int	height = 721;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
}				t_mlx;

typedef struct s_image
{
	int x;
	int y;
	char *pixel;
	void *image;
	int *size_line;
	int *bits_p;
	int *endian;
}				t_image;

int key_press(int key, t_mlx *vars)
{
	if (key == 65307)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	printf("%d\n", key);
	return (0);
}

int main()
{
	t_mlx	vars;
	t_image im;
	
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, width, height, "so_long");
	mlx_key_hook(vars.win_ptr, key_press, &vars);
	
	im.image = mlx_xpm_file_to_image(vars.mlx_ptr, "test.xpm", &im.x, &im.y);
	im.pixel = mlx_get_data_addr(im.image, im.bits_p, im.size_line, im.endian);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, im.image, 0, 0);
	
	mlx_loop(vars.mlx_ptr);
	return (0);
}