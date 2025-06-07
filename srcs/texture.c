/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:56:57 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/07 22:18:54 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_texture *get_wall_texture(t_game *game, float ray_x, float ray_y, float cos_a, float sin_a)
{
	int map_x = (int)(ray_x - cos_a) / WALL;
	int map_y = (int)(ray_y - sin_a) / WALL;

	if (map_y >= 0 && map_y < HEIGHT / WALL && map_x >= 0 && map_x < WIDTH / WALL)
	{
		if (fabs(cos_a) > fabs(sin_a))
			return (cos_a > 0) ? &game->west : &game->east;
		else
			return (sin_a > 0) ? &game->north : &game->south;
	}
	return (&game->north); // fallback
}

/**
 * @brief Renders a vertical wall strip using texture mapping.
 * @param game Pointer to the game struct.
 * @param x Column index to draw on.
 * @param start_y Starting vertical pixel position.
 * @param end_y Ending vertical pixel position.
 * @param height Height of the wall strip.
 * @param tex Texture to use.
 * @param tex_x Horizontal texture coordinate.
 */
void draw_textured_wall_strip(t_game *game, int i, int start_y, int end_y, int height, t_texture *tex, float tex_x)
{
	int y;
	int tex_y;
	int index;
	int color;

	y = start_y;
	while (y < end_y)
	{
		tex_y = (int)((float)(y - start_y) / height * tex->height);
		index = tex_y * tex->size_line + ((int)tex_x % tex->width) * (tex->bpp / 8);
		color = *(int *)(tex->data + index);
		put_pixel(i, y, color, game);
		y++;
	}
}

void project_wall_column(t_game *game, t_player *player, float ray_x, float ray_y, float cos_angle, float sin_angle, int x)
{
	float dist;
	t_texture *tex;
	float hit_x;
	float hit_y;
	float tex_x;

	dist = distance(player->x, player->y, ray_x, ray_y, game);
	tex = get_wall_texture(game, ray_x, ray_y, cos_angle, sin_angle);

	hit_x = fmod(ray_x, WALL);
	hit_y = fmod(ray_y, WALL);
	tex_x = (fabs(cos_angle) > fabs(sin_angle)) ? hit_y : hit_x;
	tex_x = (tex_x / WALL) * tex->width;

	render_3d(game, x, dist, tex, tex_x);
}