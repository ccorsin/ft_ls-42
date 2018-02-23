/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:45:43 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 14:52:50 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_power(int nb, int power)
{
	long n;

	n = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		n = n * ft_power(n, power - 1);
	return (n);
}
