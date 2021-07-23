/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:09:21 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/23 06:30:14 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_map(int **map, int nb_row, int nb_col)
{
	int	x;
	int	y;

	y = 0;
	while (y < nb_row)
	{
		x = 0;
		while (x < nb_col)
		{
			ft_putnbr(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}

void	free_image(t_game *g, t_data *t)
{
	if (t->path)
		free(t->path);
	if (t->img)
		mlx_destroy_image(g->win->mlx_ptr, t->img);
	free(t);
}

void	clear_image(t_game *g)
{
	free_image(g, g->data);
}
