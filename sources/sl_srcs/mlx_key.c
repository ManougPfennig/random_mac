/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:56:15 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/02 18:59:33 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_data *data)
{
	if (data->victory)
	{
		if (data->level < 6)
			data->victory = 0;
		else
			data->victory = 1;
		if (data->level == 0)
			check_map("map/level0.ber", data);
		if (data->level == 1)
			check_map("map/level1.ber", data);
		if (data->level == 2)
			check_map("map/level2.ber", data);
		if (data->level == 3)
			check_map("map/level3.ber", data);
		if (data->level == 4)
			check_map("map/level4.ber", data);
		if (data->level == 5)
			check_map("map/level5.ber", data);
		if (data->level >= 6)
			sprite_to_win(data, 'X', 0, 0);
		data->level++;
	}
	else if (key == W_KEY)
		move_player(data, 0, -1);
	else if (key == A_KEY)
		move_player(data, -1, 0);
	else if (key == S_KEY)
		move_player(data, 0, 1);
	else if (key == D_KEY)
		move_player(data, 1, 0);
	if (key == ESC_KEY)
	{
		mlx_destroy_window(data->mlx, data->win);
		ft_free_tab(data->map, data->copy_map);
		print_error("Exiting...\n");
	}
	return (0);
}

int	key_release(int key, t_data *data)
{
	(void)key;
	(void)data;
	return (0);
}

int	deal_key(t_data *data)
{
	(void)data;
	return (0);
}
