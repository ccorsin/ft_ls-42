/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalgint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:15:30 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/05 12:15:42 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_testneg(long int n)
{
	int		k;

	k = 0;
	if (n < 0)
		k = 1;
	return (k);
}

static int		ft_count(long int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_exception(long int n)
{
	char	*nbr;
	int		i;

	i = 19;
	if (!(nbr = (char *)malloc(sizeof(char) * (21))))
		exit(0);
	nbr[0] = '-';
	nbr[1] = '9';
	nbr[20] = '\0';
	n = 223372036854775808;
	while (i > 1)
	{
		nbr[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (nbr);
}

char			*ft_itoalgint(long int n)
{
	char	*nbr;
	int		i;
	int		k;

	i = 1;
	if (n == LONG_MIN)
		return (ft_exception(n));
	k = ft_testneg(n);
	if (k == 1)
		n = n * -1;
	i = ft_count(n);
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
