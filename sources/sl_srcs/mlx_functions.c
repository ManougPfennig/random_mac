/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:16:19 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 10:16:19 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_xpm_to_img(t_data *data, char *path)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(data->mlx, path, &data->width, &data->height);
	if (!ptr)
		print_error("Error\nSprite not found\nTry executing game from within \
it's directory");
	return (ptr);
}

void	set_imgs(t_data *data)
{
	data->img_0 = ft_xpm_to_img(data, "./img/floor.xpm");
	data->img_1 = ft_xpm_to_img(data, "./img/wall.xpm");
	data->img_b = ft_xpm_to_img(data, "./img/broken.xpm");
	data->img_c = ft_xpm_to_img(data, "./img/house.xpm");
	data->img_e = ft_xpm_to_img(data, "./img/exit.xpm");
	data->img_p = ft_xpm_to_img(data, "./img/player.xpm");
	data->img_end = ft_xpm_to_img(data, "./img/end.xpm");
}

void	start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("Error:\nCould not mlx_init -> Program interrupted\n");
		ft_free_tab(data->map, data->copy_map);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	create_window(t_data *data, char *name)
{
	if (ft_strlen(data->map[0]) < 15 && ft_tablen(data->map) < 11)
	{
		data->img_x = ft_strlen(data->map[0]) * 64;
		data->img_y = ft_tablen(data->map) * 64;
	}
	else
	{
		data->img_x = 15 * 64;
		data->img_y = 11 * 64;
	}
	data->win = mlx_new_window(data->mlx, data->img_x, data->img_y, name);
	if (data->win == NULL)
	{
		ft_printf("Error:\nCould not mlx_new_window -> Program interrupted\n");
		ft_free_tab(data->map, data->copy_map);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	create_image(t_data *data)
{
	data->height = 64;
	data->width = 64;
	if (data->img == NULL)
		data->img = mlx_new_image(data->mlx, 700, 700);
	if (data->img == NULL)
	{
		ft_printf("Error:\nCould not mlx_new_image -> Program interrupted\n");
		ft_free_tab(data->map, data->copy_map);
		exit(EXIT_FAILURE);
	}
	return ;
}
