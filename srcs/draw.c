/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 05:04:32 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/23 05:23:15 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_player(t_game *game)
{
	int	count_y;
	int	count_x;

	count_y = (int)((game->win->height / game->map->nb_row)
			* (game->player->posY));
	while (count_y < (game->win->height / game->map->nb_row)
			* (game->player->posY))
	{
		count_x = (int)((game->win->width / game->map->nb_col)
			* (game->player->posX)); 
		while (count_x < (game->win->width / game->map->nb_col)
			* (game->player->posX))
		{
			my_mlx_pixel_put(game->data, count_x, count_y, /*0x00FF00*/ 0x0);
			count_x++;
		}
		count_y++;
	}
}

void	draw_map(t_game *g, int count_x, int count_y, int x, int y)
{
	while (count_x < ((g->win->width / g->map->nb_col) * (x + 1)))
		{
			if (count_y == (g->win->height / g->map->nb_row) * y
				|| count_x == (g->win->width / g->map->nb_col) * x)
				my_mlx_pixel_put(g->data, count_x, count_y, 0x0);
			else if (g->map->l_map[y][x] == 0 
				&& count_x != (g->win->width / g->map->nb_col) * (x + 1))
				my_mlx_pixel_put(g->data, count_x, count_y, 0xFFFFFF);
			else if (g->map->l_map[y][x] == 1)
				my_mlx_pixel_put(g->data, count_x, count_y, 0x0000FF);
			else if (g->map->l_map[y][x] == 2)
				my_mlx_pixel_put(g->data, count_x, count_y, 0x000FFF);
			else if (g->map->l_map[y][x] == 3)
				my_mlx_pixel_put(g->data, count_x, count_y, 0x00FFF0);
			count_x++;
		}
}

void	mini_map_bis(t_game *g, int x, int y)
{
	int	count_x;
	int	count_y;

	count_y = (g->win->height / g->map->nb_row) * y;
	while (count_y < ((g->win->height / g->map->nb_row) * (y + 1)))
	{
		count_x = (g->win->width / g->map->nb_col) * x;
		draw_map(g, count_x, count_y, x, y);
		count_y++;
	}
}

void	mini_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map->nb_row)
	{
		x = 0;
		while (x < g->map->nb_col)
		{
			mini_map_bis(g, x, y);
			x++;
		}
		y++;
	}
	draw_player(g);
	mlx_put_image_to_window(g->win->mlx_ptr, g->win->win_ptr, g->data->img, 0, 0);
}