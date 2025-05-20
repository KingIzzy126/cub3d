/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:00:59 by ismailalash       #+#    #+#             */
/*   Updated: 2025/05/20 18:01:38 by ismailalash      ###   ########.fr       */
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
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
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