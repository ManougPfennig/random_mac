/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:15:50 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 10:15:50 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		length;
	char	*dest;

	i = 0;
	j = 0;
	length = 0;
	while (s1 != NULL && s1[i++])
		length++;
	while (s2 != NULL && s2[j++])
		length++;
	i = 0;
	j = 0;
	dest = malloc((length + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[length] = '\0';
	while (s1 != NULL && s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i])
		dest[j++] = s2[i++];
	ft_free(s1, s2);
	return (dest);
}
