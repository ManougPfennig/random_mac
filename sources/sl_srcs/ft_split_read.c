/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:16:07 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/07 18:53:12 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_sep(char c, char charset)
{
	if (charset == c)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_word_number(char *str, char charset, char charset2)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		if (ft_sep(str[i], charset) == 1 || ft_sep(str[i], charset2) == 1)
			i++;
		if (ft_sep(str[i], charset) == 1 || ft_sep(str[i], charset2) == 1 || \
		str[0] == '\n' || str[0] == '\r')
			print_error("Error\nPlease use a rectangular map");
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((ft_sep(str[i + 1], charset) == 1 || ft_sep(str[i + 1], \
		charset2) == 1) && (ft_sep(str[i], charset) == 0 && \
		ft_sep(str[i], charset2) == 0))
			number++;
		i++;
	}
	return (number);
}

char	*ft_copy_word(char *dest, char *str, char charset, char charset2)
{
	int	i;

	i = 0;
	while (ft_sep(str[i], charset) == 0 && ft_sep(str[i], charset2) == 0)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_fill_tab(char **split, char *str, char charset, char charset2)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_sep(str[i], charset) == 1 || ft_sep(str[i], charset2) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_sep(str[i + j], charset) == 0 && ft_sep(str[i + j], \
			charset2) == 0)
				j++;
			split[count] = (char *)malloc(sizeof(char) * (j + 1));
			ft_copy_word(split[count], str + i, charset, charset2);
			i = i + j;
			count++;
		}
	}
}

char	**ft_split_read(char *str)
{
	int		tab_len;
	char	**tab;
	int		fd;
	char	*string;

	if (!str)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCannot read specified file");
		exit(EXIT_FAILURE);
	}
	string = get_string_map(fd);
	tab_len = ft_word_number(string, '\n', '\r');
	tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	if (!tab)
		return (NULL);
	tab[tab_len] = NULL;
	ft_fill_tab(tab, string, '\n', '\r');
	ft_free(string, NULL);
	close (fd);
	return (tab);
}
