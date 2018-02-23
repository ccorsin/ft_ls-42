/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:57:13 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 15:05:14 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_count(unsigned int n, int len)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / len;
		i++;
	}
	return (i);
}

char			*ft_itoabase(unsigned int n, const char *base)
{
	char	*nbr;
	int		i;
	int		len;

	len = (int)ft_strlen(base);
	i = ft_count(n, len);
	if (!(nbr = ft_strnew(i)))
		exit(0);
	while (i--)
	{
		nbr[i] = base[n % len];
		n = n / len;
	}
	return (nbr);
}
