/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:47:28 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/07 18:58:04 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_victory(t_data *data)
{
	ft_printf("Congratulations !\n");
	ft_printf("-> You finished in %i moves.\n", ++data->moves);
	data->victory = 1;
}

int	ft_destroy_windows(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Exiting...\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_tab(char **tab, char **tab2)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	i = 0;
	while (tab2 && tab2[i])
	{
		free(tab2[i]);
		i++;
	}
	if (tab2)
		free(tab2);
	tab = NULL;
	tab2 = NULL;
	return ;
}

void	ft_malloc_error(t_data *data, char *str, char **tab)
{
	ft_free_tab(data->map, data->copy_map);
	ft_free_tab(tab, NULL);
	ft_free(str, NULL);
	ft_printf("Malloc error, program interrupted\n");
	exit(EXIT_FAILURE);
}

void	print_error(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
