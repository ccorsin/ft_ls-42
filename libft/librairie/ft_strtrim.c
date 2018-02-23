/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:53:24 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 15:02:40 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_sizetrim(char const *s)
{
	int		n;
	int		i;

	n = ft_strlen(s);
	i = 0;
	while (s[n - 1] == ' ' || s[n - 1] == '\t' || s[n - 1] == '\n')
		n--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		n--;
		i++;
	}
	if (n <= 0)
		n = 0;
	return (n);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	n = ft_sizetrim(s);
	if (!(str = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = i;
	i = 0;
	while (i < n)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
