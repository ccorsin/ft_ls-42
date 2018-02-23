/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:38:51 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 14:50:57 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;

	if (!(tab = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_memset(tab, 0, size);
	return (tab);
}
