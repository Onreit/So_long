/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:11:51 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/28 02:45:10 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_pressed(int key, t_game *game)
{
	if (key == W || key == A || key == S || key == D || key == 65307)
	{	
		game->current_move = key;
		if (key != 65307)
			printf("current move = %d\n", key);
	}
	return (1);
}

int	key_release(int key, t_game *game)
{
	if (key == W || key == A || key == S || key == D)
		game->current_move = INT_MIN;
	return (1);
}

int	collision(int key, t_game *g)
{
	int	tmp_y;
	int	tmp_x;

	tmp_y = g->player->posY;
	tmp_x = g->player->posX;
	if (key == W)
		tmp_y -= 1;
	if (key == S)
		tmp_y += 1;
	if (key == A)
		tmp_x -= 1;
	if (key == D)
		tmp_x += 1;
	if (g->collect == 0)
		return (g->map->l_map[(int)tmp_y][(int)tmp_x] == 1);
	return (g->map->l_map[(int)tmp_y][(int)tmp_x] == 1
			|| g->map->l_map[(int)tmp_y][(int)tmp_x] == 3);
}

void	move(int key, t_game *g)
{
	if (key == W && !collision(key, g))
		g->player->posY -= 1;
	else if (key == S && !collision(key, g))
		g->player->posY += 1;
	else if (key == A && !collision(key, g))
		g->player->posX -= 1;
	else if (key == D && !collision(key, g))
		g->player->posX += 1;
	if (g->map->l_map[(int)g->player->posY][(int)g->player->posX] == 2)
	{
		g->map->l_map[(int)g->player->posY][(int)g->player->posX] = 0;
		g->collect--;
	}
	if (g->map->l_map[(int)g->player->posY][(int)g->player->posX] == 3
		&& g->collect == 0)
	{
		printf("Game Over");
		exit_game(g);
	}
}

int	main_loop(t_game *g)
{
	if (g->current_move == W || g->current_move == A || g->current_move == S
		|| g->current_move == D)
		move(g->current_move, g);
	if (g->current_move == 65307)
		exit_game(g);
	mlx_clear_window(g->win->mlx_ptr, g->win->win_ptr);
	mini_map(g);
	mlx_put_image_to_window(g->win->mlx_ptr, g->win->win_ptr,
		g->data->img, 0, 0);
	return (0);
}
