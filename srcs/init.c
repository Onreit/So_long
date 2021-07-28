/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:54:33 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/28 04:56:47 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*init_map(void)
{
	t_map	*nmap;

	nmap = (t_map *)malloc(sizeof(t_map));
	if (!nmap)
		return (NULL);
	nmap->tmp_map = NULL;
	nmap->nb_row = 0;
	nmap->nb_col = 0;
	nmap->l_map = 0;
	return (nmap);
}

t_player	*init_player(void)
{
	t_player	*nplay;

	nplay = (t_player *)malloc(sizeof(t_player));
	if (!nplay)
		return (NULL);
	nplay->posX = 0;
	nplay->posY = 0;
	nplay->dir = '0';
	return (nplay);
}

t_win	*init_win(void)
{
	t_win	*win;

	win = (t_win *)malloc(sizeof(t_win));
	if (!win)
		return (NULL);
	win->width = 1020;
	win->height = 720;
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	return (win);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->width = 0;
	data->height = 0;
	return (data);
}

void	init_game(t_game *gamer)
{
	gamer->map = init_map();
	gamer->player = init_player();
	gamer->win = init_win();
	gamer->data = init_data();
	gamer->floor = init_data();
	gamer->exit = init_data();
	gamer->col = init_data();
	gamer->text_player = init_data();
	gamer->wall = init_data();
	if (!gamer->map || !gamer->player || !gamer->win || !gamer->data
		|| !gamer->floor || !gamer->text_player || !gamer->col
		|| !gamer->exit)
		exit_failure("Malloc error\n", gamer);
	gamer->win->height = 0;
	gamer->win->width = 0;
	gamer->current_move = INT_MIN;
	gamer->collect = 0;
	gamer->check_exit = 0;
	gamer->map_started = 0;
	gamer->map_stopped = 0;
	gamer->x = 0;
	gamer->y = 0;
	gamer->size = 50;
	gamer->check_player = 0;
	gamer->movements = 0;
}
