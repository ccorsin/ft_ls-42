/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:54:10 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 14:52:40 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*bb;
	unsigned char	cc;

	bb = b;
	cc = c;
	while (n > 0)
	{
		*bb++ = cc;
		n--;
	}
	return (b);
}
