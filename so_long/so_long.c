/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/11 13:13:25 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
    void    *mlx_ptr;
    void    *mlx_win;
	void	*img;
	int x;
	int y;
    
    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 800, 600, "so_long");
	img = mlx_xpm_file_to_image(mlx_ptr, "./test.xpm", &x, &y);
    mlx_loop(mlx_ptr);
    return (0);
}