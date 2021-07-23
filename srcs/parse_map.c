/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:37:32 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/23 06:22:31 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	dir(char c)
{
	if (c == 'P')
		return (1);
	return (0);
}

void	goal(char line, t_game *g, int current_line, int *row, int i)
{
	if (line == 'P')
	{	
		position(g->player, i, current_line);
		row[i] = 0;
	}
	else if (line == 'C')
	{
		g->collect += 1;
		row[i] = 2;
	}
	else if (line == 'E')
	{
		g->check_exit += 1;
		row[i] = 3;
}

void	handle_line2(char *line, t_game *g, int current_line, int *row)
{
	int	i;

	i = 0;
	while (i < g->map->nb_col)
	{
		while (line[i])
		{
			if (!ft_isdigit(line[i]))
			{
				goal(line[i], g, current_line, row, i);
				row[i] = 0;
			}
			else
			{
				row[i] = 0;
				if (ft_isdigit(line[i]))
					row[i] = line[i] - '0';
			}
			i++;
		}
		while (i < g->map->nb_col)
			row[i++] = 0;
	}
}

int	*handle_line(char *line, t_game *game, int current_line)
{
	int	*row;

	row = (int *)malloc(sizeof(int) * game->map->nb_col);
	if (!row)
		return (NULL);
	handle_line2(line, game, current_line, row);
	return (row);
}

void	ft_strjoin_fr(char **str, char *buf)
{
	char	*tmp;

	if (*str == NULL)
		*str = ft_strdup(buf);
	else if (**str == '\0')
	{
		free(*str);
		*str = ft_strdup(buf);
	}
	else
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(tmp, buf);
		free(tmp);
	}
}