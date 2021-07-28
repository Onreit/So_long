/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:31:28 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/27 23:22:48 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_texture(t_game *g, t_data *text, char *line)
{
	text->img = mlx_xpm_file_to_image(g->win->mlx_ptr, line,
			&text->width, &text->height);
	if (!text->img)
		exit_failure("Impossible to load texture\n", g);
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_length, &text->endian);
}

void	get_texture(t_game *g)
{
	set_texture(g, g->col, "./texture/sprite_3.xpm");
	set_texture(g, g->floor, "./texture/floor_1.xpm");
	set_texture(g, g->text_player, "./texture/dauphin.xpm");
	set_texture(g, g->exit, "./texture/pillar.xpm");
	set_texture(g, g->wall, "./texture/wall_1.xpm");
}
