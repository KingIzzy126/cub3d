/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:00:59 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/11 13:56:23 by ismailalash      ###   ########.fr       */
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
    load_textures(game);
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

void load_textures(t_game *game)
{
    game->textures[0].img = mlx_xpm_file_to_image(game->mlx,
            "textures/hexagonwall.xpm", &game->textures[0].width,
            &game->textures[0].height);
    game->textures[0].data = mlx_get_data_addr(game->textures[0].img,
            &game->textures[0].bpp, &game->textures[0].size_line,
            &game->textures[0].endian);
    game->textures[1].img = mlx_xpm_file_to_image(game->mlx,
            "textures/blackhexagon.xpm", &game->textures[1].width,
            &game->textures[1].height);
    game->textures[1].data = mlx_get_data_addr(game->textures[1].img,
            &game->textures[1].bpp, &game->textures[1].size_line,
            &game->textures[1].endian);
    game->textures[2].img = mlx_xpm_file_to_image(game->mlx,
            "textures/spaceship.xpm", &game->textures[2].width,
            &game->textures[2].height);
    game->textures[2].data = mlx_get_data_addr(game->textures[2].img,
            &game->textures[2].bpp, &game->textures[2].size_line,
            &game->textures[2].endian);
    game->textures[3].img = mlx_xpm_file_to_image(game->mlx,
            "textures/spaceshipdark.xpm", &game->textures[3].width,
            &game->textures[3].height);
    game->textures[3].data = mlx_get_data_addr(game->textures[3].img,
            &game->textures[3].bpp, &game->textures[3].size_line,
            &game->textures[3].endian);
}
