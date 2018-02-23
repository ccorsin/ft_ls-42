/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:07:30 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 14:55:28 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr_rev(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;
	char	l;

	j = 0;
	l = c;
	str = (char *)s;
	while (str[j] != '\0')
		j++;
	if (l == '\0')
		return (str + j);
	i = j - 1;
	while (str[i] != c && i >= 0)
		i--;
	if (str[i] == l)
		return (str + i);
	else
		return (0);
}
