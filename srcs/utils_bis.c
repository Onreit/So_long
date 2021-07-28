/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 00:58:54 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/28 05:13:38 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_line(char **strs, int i, t_game *g)
{
	if (strs[0][i] != '1' || strs[g->map->nb_row - 1][i] != '1')
		return (0);
	return (1);
}

int	check_col(char **strs, int i, t_game *g)
{
	if (strs[i][0] != '1' || strs[i][g->map->nb_col - 1] != '1')
		return (0);
	return (1);
}

void	is_rect(t_game *g)
{
	char		**split_map;
	int			i;

	split_map = ft_split(g->map->tmp_map, '\n');
	i = 0;
	while (i < g->map->nb_row)
	{
		if (!check_col(split_map, i, g))
		{
			free_split(split_map);
			exit_failure("The map is not a rectangle\n", g);
		}
		i++;
	}
	i = 0;
	while (i < g->map->nb_col)
	{
		if (!check_line(split_map, i, g))
		{
			free_split(split_map);
			exit_failure("The map is not a rectangle\n", g);
		}
		i++;
	}
	free_split(split_map);
}

void	is_end(t_game *g)
{
	if (g->map->l_map[(int)g->player->posY][(int)g->player->posX] == 2)
	{
		g->map->l_map[(int)g->player->posY][(int)g->player->posX] = 0;
		g->collect--;
	}
	if (g->map->l_map[(int)g->player->posY][(int)g->player->posX] == 3
		&& g->collect == 0)
		exit_game(g);
}