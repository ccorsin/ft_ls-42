/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:45:12 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 14:36:54 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_testneg(int n)
{
	int		k;

	k = 0;
	if (n < 0)
		k = 1;
	return (k);
}

static char		*ft_exception(int n)
{
	char	*nbr;
	int		i;

	i = 10;
	if (!(nbr = (char *)malloc(sizeof(char) * (12))))
		exit(0);
	nbr[0] = '-';
	nbr[1] = '2';
	nbr[11] = '\0';
	n = 147483648;
	while (i > 1)
	{
		nbr[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (nbr);
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	int		k;

	i = 1;
	if (n == -2147483648)
		return (ft_exception(n));
	k = ft_testneg(n);
	if (k == 1)
		n = n * -1;
	while (ft_power(10, i) - 1 < n)
		i++;
	if (!(nbr = (char *)malloc(sizeof(char) * (i + 1 + k))))
		exit(0);
	nbr[i + k] = '\0';
	if (k == 0)
		i--;
	while (i > 0)
	{
		nbr[i--] = n % 10 + 48;
		n = n / 10;
	}
	nbr[0] = (k == 1 ? '-' : (n % 10 + 48));
	return (nbr);
}
