/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:40:52 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/28 04:57:57 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	game_init(t_game *g)
{
	g->win->mlx_ptr = mlx_init();
	g->win->win_ptr = mlx_new_window(g->win->mlx_ptr, g->win->width,
			g->win->height, "so_long");
	get_texture(g);
	g->data->img = mlx_new_image(g->win->mlx_ptr,
			g->win->width, g->win->height);
	g->data->addr = mlx_get_data_addr(g->data->img, &g->data->bits_per_pixel,
			&g->data->line_length, &g->data->endian);
}

void	game_loop(t_game *g)
{
	mlx_hook(g->win->win_ptr, 2, (1L << 0), key_pressed, g);
	mlx_hook(g->win->win_ptr, 3, (1L << 1), key_release, g);
	mlx_hook(g->win->win_ptr, 33, (1L << 17), exit_game, g);
	mlx_loop_hook(g->win->mlx_ptr, &main_loop, g);
	mlx_loop(g->win->mlx_ptr);
}

void	check_ext(char *file, char *ext)
{
	size_t	len_file;
	size_t	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(ext);
	while (len_file-- && len_ext-- && file[len_file] == ext[len_ext])
	{
		if (len_ext == 0)
			return ;
	}
	printf("Error\nWrong extension\n");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_game	*g;

	if (ac != 2)
	{
		printf("Error\nYou must to have two arguments\n");
		exit(EXIT_FAILURE);
	}
	check_ext(av[1], ".ber");
	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		return (0);
	init_game(g);
	read_map(av[1], g);
	game_init(g);
	game_loop(g);
	return (0);
}
