/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:28:04 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 17:41:58 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_strnull(void)
{
	char	*s;

	if (!(s = ft_strnew(6)))
		exit(0);
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	return (s);
}

static void		ft_putspace(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

int				ft_putc(int c, t_flag *arg, int max)
{
	char	*s;
	int		len;
	int		k;

	k = (c == 0 ? 1 : 0);
	if (!(s = ft_strnew(1)))
		exit(0);
	if (c != 0)
		s[0] = c;
	ft_precisionchar(&s, arg, max);
	if (arg->ch != 0 && (c != 0 || (c == 0 && arg->at[2] != 1)))
		ft_champchar(&s, arg, k);
	k = (arg->ch != 0 ? arg->ch : 1);
	if (c == 0)
	{
		ft_putstrtot(s);
		if (arg->at[2] == 1)
			ft_putspace(arg->ch - ft_strlen(s) - 1);
	}
	else
		ft_putstr(s);
	len = (c == 0 ? k : (int)ft_strlen(s));
	free(s);
	return (len);
}

int				ft_puts(char *str, t_flag *arg, int max)
{
	char	*s;
	int		len;

	if (str != NULL)
	{
		if (!(s = ft_strdup(str)))
			exit(0);
	}
	else
		s = ft_strnull();
	ft_precisionchar(&s, arg, max);
	if (arg->ch != 0)
		ft_champchar(&s, arg, 0);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int				ft_putp(void *p, t_flag *arg)
{
	int		len;
	long	n;
	int		k;

	n = (long)p;
	k = 0;
	arg->at[0] = 1;
	len = ft_ulintbase(n, arg) + k;
	return (len);
}
