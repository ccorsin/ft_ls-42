/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:14:36 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 15:01:51 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		**size_table(char const *s, char c)
{
	int		i;
	size_t	j;
	int		k;
	char	**tab;

	j = 0;
	k = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (s[j] == c)
		j++;
	while (s[j] != '\0' && j < ft_strlen(s))
	{
		i = 0;
		while (s[j] != c && s[j++] != '\0')
			i++;
		if (!(tab[k++] = (char*)malloc(sizeof(char) * (i + 2))))
			return (NULL);
		while (s[j + 1] == c)
			j++;
		j++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	j;
	int		k;

	if (s == 0)
		return (0);
	if (!(tab = size_table(s, c)))
		return (NULL);
	j = 0;
	k = 0;
	while (s[j] == c)
		j++;
	while (s[j] != '\0' && j < ft_strlen(s))
	{
		i = 0;
		while (s[j] != c && s[j] != '\0')
			tab[k][i++] = s[j++];
		tab[k++][i] = '\0';
		while (s[j + 1] == c)
			j++;
		j++;
	}
	tab[k] = 0;
	return (tab);
}
