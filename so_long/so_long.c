/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/12 15:27:28 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
}				t_mlx;

int key(int keyp, t_mlx *vars)
{
	if (keyp == 65307)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_loop_end(vars->mlx_ptr);
	}
	else
	{
		printf("%d\n", keyp);
		mlx_hook(vars->mlx_ptr, 7, (1L<<4), key, &vars);
	}
	return (0);
}

int main()
{
	t_mlx	vars;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 800, 600, "so_long");
	mlx_key_hook(vars.win_ptr, key, &vars);
	mlx_loop(vars.mlx_ptr);
	mlx_destroy_display(vars.mlx_ptr);
	return (0);
}