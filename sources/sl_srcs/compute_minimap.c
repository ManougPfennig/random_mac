/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:03:54 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/29 16:00:33 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_minimap(t_data *data, int i, int y)
{
	char	**tab;
	int		ysize;
	int		xsize;

	ysize = ft_tablen(data->map);
	xsize = ft_strlen(data->map[0]);
	if (xsize > 16)
		xsize = 16;
	if (ysize > 12)
		ysize = 12;
	tab = malloc((ysize + 1) * sizeof(char *));
	if (tab == NULL)
		ft_malloc_error(data, NULL, tab);
	while (++y < ysize)
	{
		tab[i] = ft_calloc((xsize + 1), sizeof(char));
		if (!tab[i])
			ft_malloc_error(data, NULL, tab);
		i++;
	}
	tab[ysize] = NULL;
	return (tab);
}

char	**compute_minimap(t_data *data, int x, int y, int mix)
{
	int		miy;
	char	**tab;

	tab = make_minimap(data, 0, -1);
	y = data->play_y - 5;
	if (y < 0)
		y = 0;
	miy = 0;
	while (data->map[y] && miy < 11)
	{
		mix = 0;
		x = data->play_x - 7;
		if (x < 0)
			x = 0;
		while (data->map[y][x] && mix < 15)
		{
			tab[miy][mix] = data->map[y][x];
			x++;
			mix++;
		}
		y++;
		miy++;
	}
	return (tab);
}
