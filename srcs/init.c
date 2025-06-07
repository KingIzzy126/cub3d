/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:00:59 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/07 22:02:23 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_game(t_game *game)
{
    init_player(&game->player);
    game->player.game = game;
    game->map = get_map();
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Halo Infinite");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    game->ceiling_color = (0 << 16) | (0 << 8) | 0;        // Black: RGB(0, 0, 128)
    game->floor_color = (0 << 16) | (0 << 8) | 128;        // Navy dark blue: RGB(46, 8, 84) 
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    load_texture(game, &game->north, "./textures/wall1.xpm");
    load_texture(game, &game->south, "./textures/wall2.xpm");
    load_texture(game, &game->west, "./textures/wall3.xpm");
    load_texture(game, &game->east, "./textures/wall4.xpm");

}

char **get_map(void)
{
    char **map;
    
    map = malloc(sizeof(char *) * 13);
    map[0] = "111111111111111111";
    map[1] = "100010000000000001";
    map[2] = "100010000000010001";
    map[3] = "100000000000000001";
    map[4] = "100000001110000001";
    map[5] = "100000001110000001";
    map[6] = "100000001110000001";
    map[7] = "100000100000100001";
    map[8] = "101000000000000101";
    map[9] = "100000100000100001";
    map[10] = "100000000000000001";
    map[11] = "111111111111111111";
    map[12] = NULL;
    return (map);
}

void	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
	{
		printf("Failed to load texture: %s\n", path);
		exit(1);
	}
	tex->data = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &tex->endian);
    if (!tex->data)
        printf("Texture loaded but no data for: %s\n", path);
}

