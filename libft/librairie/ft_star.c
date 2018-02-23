/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:39:22 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/12 09:53:21 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_free(t_flag *arg)
{
	free(arg->at);
	free(arg);
}

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int		ft_check_lg(const char *s, int i, int n)
{
	while (i < n)
	{
		if (s[i] == '*' && s[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_check_pr(const char *s, int i, int n)
{
	while (i < n)
	{
		if (s[i] == '.' && s[i + 1] == '*')
			return (1);
		i++;
	}
	return (0);
}

void			ft_check_star(t_flag *arg, va_list ap, int i, const char *s)
{
	int		j;
	int		n;
	int		l;
	int		p;

	j = i;
	while ((arg->max == -1 && (s[j] != 's' && s[j] != 'S' && s[j] != 'p' \
			&& s[j] != 'd' && s[j] != 'D' && s[j] != 'i' && s[j] != 'o' \
			&& s[j] != 'O' && s[j] != 'u' && s[j] != 'U' && s[j] != 'x' \
			&& s[j] != 'X' && s[j] != 'c' && s[j] != 'C' && s[j] != '\0' \
			&& s[j] != '%')) || (arg->max != -1 && j < arg->max))
		j++;
	n = j;
	l = ft_check_lg(s, i, n);
	p = ft_check_pr(s, i, n);
	if (l == 1)
	{
		n = va_arg(ap, int);
		if (n < 0)
			arg->at[2] = 1;
		arg->ch = ft_abs(n);
	}
	if (p == 1)
		arg->pr = ft_abs(va_arg(ap, int));
}
