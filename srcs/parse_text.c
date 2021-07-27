/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:31:28 by tjalo             #+#    #+#             */
/*   Updated: 2021/07/27 20:37:49 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_texture(t_game *g)
{
	g->floor->path = ft_strdup("./texture/floor_1.xpm");
	g->wall->path = ft_strdup("./texture/wall_1.xpm");
	g->col->path = ft_strdup("./texture/sprite_3.xpm");
	g->exit->path = ft_strdup("./texture/pillar.xpm");
	g->text_player->path = ft_strdup("./texture/dauphin.xpm");
}

void	set_texture(t_game *g, t_data *text)
{
	text->img = mlx_xpm_file_to_image(g->win->mlx_ptr, text->path,
			&text->width, &text->height);
	if (!text->img)
		exit_failure("Impossible to load texture\n", g);
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_length, &text->endian);
}

void	get_texture(t_game *g)
{
	set_texture(g, g->col);
	set_texture(g, g->floor);
	set_texture(g, g->text_player);
	set_texture(g, g->exit);
	set_texture(g, g->wall);
}
