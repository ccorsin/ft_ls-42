/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:48:30 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/01 11:45:25 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_lex_up(char *s, char *t)
{
	if (ft_strcmp(s, t) > 0)
		return (0);
	else
		return (1);
}

int		ft_lex_down(char *s, char *t)
{
	if (ft_strcmp(s, t) < 0)
		return (0);
	else
		return (1);
}

int		ft_time_up(time_t t, time_t m)
{
	if (t < m)
		return (0);
	else if (t == m)
		return (2);
	else
		return (1);
}

int		ft_time_down(time_t t, time_t m)
{
	if (t > m)
		return (0);
	else if (t == m)
		return (2);
	else
		return (1);
}
