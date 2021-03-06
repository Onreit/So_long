/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 03:43:49 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/28 08:03:38 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_info(char info)
{
	if (info == 'C' || info == 'P' || info == 'E')
		return (1);
	return (0);
}

int	ft_isrow(char *row)
{
	int	i;

	i = 0;
	if (row[0] == '\0')
		return (0);
	while (row[i])
	{
		if (!ft_isdigit(row[i]) && !ft_info(row[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isempty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n'
			&& line[i] != '\t' && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

void	check_info(t_game *g)
{
	if (g->check_player == 0)
		exit_failure("Need player in the map\n", g);
	if (g->collect == 0)
		exit_failure("Too few collectibles\n", g);
	if (g->check_exit == 0)
		exit_failure("Too few exit\n", g);
}

void	is_move(t_game *g)
{
	g->movements++;
	printf("Number of movements = %d\n", g->movements);
}
