/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaulgint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:16:53 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/05 12:17:06 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_itoaulgint(unsigned long int n)
{
	char			*nbr;
	int				i;
	unsigned long	nb;

	i = (n == 0 ? 1 : 0);
	nb = n;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	if (!(nbr = (char *)malloc(sizeof(char) * (i))))
		exit(0);
	nbr[i] = '\0';
	while (i--)
	{
		nbr[i] = n % 10 + 48;
		n = n / 10;
	}
	return (nbr);
}
