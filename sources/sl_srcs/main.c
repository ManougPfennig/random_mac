/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:16:14 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/02 19:20:40 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_data *data)
{
	data->items = 0;
	data->play_x = 0;
	data->play_y = 0;
	data->width = 0;
	data->height = 0;
	data->usable = 0;
	data->moves = 0;
	data->victory = 0;
	data->map = NULL;
	data->copy_map = NULL;
	data->level = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	start();
	init_struct(&data);
	if (arg_parsing(ac, av, &data))
	{
		ft_free_tab(data.map, data.copy_map);
		exit(EXIT_SUCCESS);
	}
	start_mlx(&data);
	create_window(&data, "so_long");
	create_image(&data);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	data.moves = 0;
	set_imgs(&data);
	put_map(&data);
	mlx_hook(data.win, 2, 1L << 0, key_pressed, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, deal_key, &data);
	mlx_hook(data.win, 17, 0, ft_destroy_windows, &data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_loop(data.mlx);
	ft_free_tab(data.map, data.copy_map);
	exit(EXIT_SUCCESS);
}
