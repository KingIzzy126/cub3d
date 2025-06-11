/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:53:43 by ismailalash       #+#    #+#             */
/*   Updated: 2025/06/11 13:08:01 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_player *player, int speed, float cos_a, float sin_a)
{
	float new_x;
	float new_y;
	float player_size;

	player_size = COLLISION_BUFFER;
	if (player->key_up)
	{
		new_x = player->x + speed * cos_a;
		new_y = player->y + speed * sin_a;
		if (!is_colliding(new_x, player->y, player->game, player_size))
			player->x = new_x;
		if (!is_colliding(player->x, new_y, player->game, player_size))
			player->y = new_y;
	}
}

void	move_down(t_player *player, int speed, float cos_a, float sin_a)
{
	float new_x;
	float new_y;
	float player_size;

	player_size = COLLISION_BUFFER;
	if (player->key_down)
	{
		new_x = player->x - speed * cos_a;
		new_y = player->y - speed * sin_a;
		if (!is_colliding(new_x, player->y, player->game, player_size))
			player->x = new_x;
		if (!is_colliding(player->x, new_y, player->game, player_size))
			player->y = new_y;
	}
}

void	move_left(t_player *player, int speed, float cos_a, float sin_a)
{
	float new_x;
	float new_y;
	float player_size;

	player_size = COLLISION_BUFFER;
	if (player->key_left)
	{
		new_x = player->x + speed * sin_a;
		new_y = player->y - speed * cos_a;
		if (!is_colliding(new_x, player->y, player->game, player_size))
			player->x = new_x;
		if (!is_colliding(player->x, new_y, player->game, player_size))
			player->y = new_y;
	}
}

void	move_right(t_player *player, int speed, float cos_a, float sin_a)
{
	float new_x;
	float new_y;
	float player_size;

	player_size = COLLISION_BUFFER;
	if (player->key_right)
	{
		new_x = player->x - speed * sin_a;
		new_y = player->y + speed * cos_a;
		if (!is_colliding(new_x, player->y, player->game, player_size))
			player->x = new_x;
		if (!is_colliding(player->x, new_y, player->game, player_size))
			player->y = new_y;
	}
}