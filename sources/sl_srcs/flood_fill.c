/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:15:27 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 10:15:27 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_test(t_data *data, char **tab, int x, int y)
{
	if (tab[x][y] == 'X' || tab[x][y] == '1')
		return ;
	if (tab[x][y] == 'C')
		data->items--;
	if (tab[x][y] == 'E')
		data->usable = 1;
	tab[x][y] = 'X';
	flood_test(data, tab, (x + 1), y);
	flood_test(data, tab, (x - 1), y);
	flood_test(data, tab, x, (y - 1));
	flood_test(data, tab, x, (y + 1));
}

int	flood_fill(t_data *data)
{
	int	c;

	c = data->items;
	flood_test(data, data->copy_map, data->play_y, data->play_x);
	if (data->usable == 1 && data->items == 0)
	{
		data->items = c;
		return (0);
	}
	return (ft_printf("Error\nMap can not be finished"));
}

void	print_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
	return ;
}

	// system("clear");
	// print_map(tab);
	// usleep(1000000);