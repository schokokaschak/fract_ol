/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:02:30 by akashets          #+#    #+#             */
/*   Updated: 2023/02/23 14:02:35 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	burning_set(double x, double y, t_data *mlx)
{
	int		i;
	int		k;
	double	zx;
	double	zy;
	double	tmp;

	zx = 0;
	zy = 0;
	i = 1;
	k = mlx->iteration;
	while (i < k)
	{
		tmp = zx;
		zx = ((zx * zx) - (zy * zy)) - x;
		zy = fabs(2 * tmp * zy) - y;
		if ((zx * zx) + (zy * zy) > 4)
		{
			my_mlx_pixel_put(mlx, mlx->loopx, mlx->loopy, \
					get_color((double)((i + 1 - \
			log(log2(zx * zx + zy * zy))) / 2) / k, mlx->color));
			return (0);
		}
		i++;
	}
	return (0);
}

int	burning(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, SIZEX, SIZEY);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
			&mlx->line_length, &mlx->endian);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			burning_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	ft_how_to_use(mlx);
	return (0);
}

void	start_burning(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Fract'ol - Burning Ship");
	mlx.xmin = -2;
	mlx.xmax = 2.5;
	mlx.ymin = -1.5;
	mlx.ymax = 2.5;
	mlx.color = 0;
	mlx.fractol = 3;
	mlx.iteration = 70;
	burning(&mlx);
	mlx_key_hook(mlx.win, keys, &mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, &mlx);
	mlx_mouse_hook(mlx.win, zoom, &mlx);
	mlx_loop(mlx.mlx);
}
