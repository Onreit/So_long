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

i

int	key_pressed(int key, t_game *game)
{
	if (key == W || key == A || key == S || key == D || key == 65307)
		game->current_move = key;
	if (key == 65361 || key == 65363)
		game->current_rot = key;
	return (1);
}

int	key_release(int key, t_game *game)
{
	if (key == W || key == A || key == S || key == D)
		game->current_move = INT_MIN;
	if (key == 65361 || key == 65363)
		game->current_rot = INT_MIN;
	return (1);
}

int		collision(int key, t_game *game)
{
	float tmp_y;
	float tmp_x;

	tmp_y = game->player->posY;
	tmp_x = game->player->posX;
	if (key == W)
		tmp_y -= 1;
	if (key == S)
		tmp_y += 1;
	if (key == A)
		tmp_x -= 1;
	if (key == D)
		tmp_x += 1;
	return (game->map->l_map[(int)tmp_y][(int)tmp_x] == 1);
}

void	move(int key, t_game *g)
{
	if (key == W && !collision(key, g))
		g->player->posY -= 1;
	if (key == S && !collision(key, g))
		g->player->posY += 1;
	if (key == A && !collision(key, g))
		g->player->posX -= 1;
	if (key == D && !collision(key, g))
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
	mini_map(g)
	mlx_clear_window(g->win->mlx_ptr, g->win->win_ptr);
	return (0);
}