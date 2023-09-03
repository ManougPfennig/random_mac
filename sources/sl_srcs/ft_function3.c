/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:15:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 10:15:58 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_string_map(int fd)
{
	int		ret;
	char	*buffer;
	char	*str;

	ret = 1;
	str = NULL;
	while (ret > 0)
	{
		buffer = ft_calloc(2, sizeof(char));
		if (!buffer)
			return (NULL);
		ret = read(fd, buffer, 1);
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

void	ft_free(char *str, char *str2)
{
	if (str != NULL)
		free(str);
	if (str2 != NULL)
		free(str2);
	str = NULL;
	str2 = NULL;
	return ;
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
