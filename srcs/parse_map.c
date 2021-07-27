/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:37:32 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/27 21:05:10 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	dir(char c)
{
	if (c == 'P')
		return (1);
	return (0);
}

void	goal(char line, t_game *g, int *row, int current_line)
{
	if (line == 'P')
	{	
		position(g->player, g->x, current_line);
		row[g->x] = 0;
	}
	else if (line == 'C')
	{
		g->collect += 1;
		row[g->x] = 2;
	}
	else if (line == 'E')
	{
		g->check_exit += 1;
		row[g->x] = 3;
	}
}

void	handle_line2(char *line, t_game *g, int current_line, int *row)
{
	g->x = 0;
	while (g->x < g->map->nb_col)
	{
		while (line[g->x])
		{
			if (!ft_isdigit(line[g->x]))
				goal(line[g->x], g, row, current_line);
			else
			{
				row[g->x] = 0;
				if (ft_isdigit(line[g->x]))
					row[g->x] = line[g->x] - '0';
			}
			g->x++;
		}
		while (i < g->map->nb_col)
			row[g->x++] = 0;
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
