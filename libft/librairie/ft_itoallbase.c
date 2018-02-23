/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoallbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:16:28 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/05 12:16:36 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_count(unsigned long long n, long len)
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

char			*ft_itoallbase(unsigned long long n, const char *base)
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
