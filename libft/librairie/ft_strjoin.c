/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:55:38 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 14:58:00 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	n;
	char	*str;

	n = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	if (s1 && s2)
	{
		if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		i = 0;
		while (s1[i])
			str[j++] = s1[i++];
		i = 0;
		while (s2[i])
			str[j++] = s2[i++];
		str[j] = '\0';
		return (str);
	}
	else
		return (0);
}
