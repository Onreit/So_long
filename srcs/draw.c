/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 05:04:32 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/27 23:08:07 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_elem(t_game *g, t_map *map)
{
	if (map->l_map[g->y][g->x] == 0)
		draw_texture(g, g->floor);
	else if (map->l_map[g->y][g->x] == 1)
		draw_texture(g, g->wall);
	else if (map->l_map[g->y][g->x] == 2)
		draw_texture(g, g->col);
	else
		draw_texture(g, g->exit);
}

void	mini_map(t_game *g)
{
	g->y = 0;
	while (g->y < g->map->nb_row)
	{
		g->x = 0;
		while (g->x < g->map->nb_col)
		{
			draw_elem(g, g->map);
			g->x++;
		}
		g->y++;
	}
	g->y = g->player->posY;
	g->x = g->player->posX;
	draw_texture(g, g->text_player);
}
