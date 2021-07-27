/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:22:38 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/23 05:22:44 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	puterror(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
}

void	exit_failure(char *error, t_game *g)
{
	puterror(error);
	exit_game(g);
}

void	clear_game(t_game *g)
{
	int	i;

	i = 0;
	free(g->player);
	if (g->map->tmp_map)
		free(g->map->tmp_map);
	if (g->map->l_map)
	{	
		while (i < g->map->nb_row)
			free(g->map->l_map[i++]);
		free(g->map->l_map);
	}
	free(g->map);
	clear_image(g);
	if (g->win->win_ptr)
		mlx_destroy_window(g->win->mlx_ptr, g->win->win_ptr);
	mlx_destroy_display(g->win->mlx_ptr);
	free(g->win->mlx_ptr);
	free(g->win);
	free(g);
}

int	exit_game(t_game *g)
{
	clear_game(g);
	exit(EXIT_SUCCESS);
	return (0);
}
