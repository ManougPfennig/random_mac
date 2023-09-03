/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecp_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:25:10 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/07 18:38:22 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ecp_values(int e, int c, int p)
{
	if (e != 1 || p != 1)
		return (ft_printf("Error\nInvalid amount of Exit or Starting position"));
	if (c < 1)
		return (ft_printf("Error\nMap must have at least one item"));
	return (0);
}

int	is_ecp(char sign)
{
	if (sign != 'E' && sign != 'C' && sign != 'P' \
			&& sign != '0' && sign != '1')
		return (0);
	return (1);
}
