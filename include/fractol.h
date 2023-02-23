/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:46:02 by akashets          #+#    #+#             */
/*   Updated: 2023/02/23 10:56:50 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define SIZEX 900
# define SIZEY 900
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"
# include <math.h>

typedef struct s_data
{
	int		iteration;
	void	*mlx;
	void	*img;
	char	*img_addr;
	void	*win;
	double	ymin;
	double	xmax;
	double	ymax;
	double	juliax;
	double	xmin;
	double	juliay;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		loopx;
	int		loopy;
	double	color;
	int		fractol;
	char	kernel;
}		t_data;

int		get_color(long double i, int c);
void	my_mlx_pixel_put(t_data *mlx, int y, int x, int color);
int		create_trgb(int t, int r, int g, int b);
void	ft_run(t_data *mlx, int flag);
void	start_mandelbrot(void);
int		mandelbrot(t_data *mlx);
int		mandelbrot_set(double x, double y, t_data *mlx);
void	start_julia(void);
int		julia(t_data *mlx);
int		julia_set(double x, double y, t_data *mlx);
void	start_burning(void);
int		burning(t_data *mlx);
int		burning_set(double x, double y, t_data *mlx);
int		keys(int keycode, t_data *vars);
int		zoom(int keycode, int x, int y, t_data *mlx);
int		ft_strcmp(char *s1, char *s2);
int		ft_exit(t_data *mlx);
void	ft_how_to_use(t_data *mlx);

#endif
