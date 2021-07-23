/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:11:51 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/23 05:27:41 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_pressed(int key, t_game *game)
{
	if (key == W || key == A || key == S || key == D || key == 65307)
		game->current_move = key;
	return (1);
}

int	key_release(int key, t_game *game)
{
	if (key == W || key == A || key == S || key == D)
		game->current_move = INT_MIN;
	return (1);
}

int		collision(t_game *g)
{
	int tmp_y;
	int tmp_x;

	tmp_y = g->player->posY;
	tmp_x = g->player->posX;
	if (g->current_move == W)
		tmp_y -= 1;
	if (g->current_move == S)
		tmp_y += 1;
	if (g->current_move == A)
		tmp_x -= 1;
	if (g->current_move == D)
		tmp_x += 1;
	return (g->map->l_map[(int)tmp_y][(int)tmp_x] == 1);
}

void	move(t_game *g)
{
	if (g->current_move == W && !collision(g))
		g->player->posY -= 1;
	if (g->current_move == S && !collision(g))
		g->player->posY += 1;
	if (g->current_move == A && !collision(g))
		g->player->posX -= 1;
	if (g->current_move == D && !collision(g))
		g->player->posX += 1;
	if (g->map->l_map[g->player->posY][g->player->posX] == 2)
	{
		g->map->l_map[g->player->posY][g->player->posX] = 0;
		g->collect--;
	}
	if (g->map->l_map[g->player->posY][g->player->posX] == 3
		&& g->collect == 0)
	{
		printf("Game Over");
		exit_game(g);
	}
}

int	main_loop(t_game *g)
{
	move(g);
	mini_map(g);
	mlx_clear_window(g->win->mlx_ptr, g->win->win_ptr);
	return (0);
}