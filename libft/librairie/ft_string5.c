/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:28:04 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 17:45:33 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_wsize(int c)
{
	if (c > 1114111 || c < 0 || c == 55296 || c == 56066 || c == 57343
			|| c == 49150)
		return (-1);
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else if (c <= 1114111)
		return (4);
	else
		return (0);
}

static int		ft_wsizetot(wchar_t *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len = len + ft_wsize(str[i]);
		if (ft_wsize(str[i]) == -1)
			return (-1);
		i++;
	}
	return (len);
}

static int		ft_sublen(wchar_t *str, t_flag *arg)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (arg->pr == -1)
		return (-1);
	if (arg->pr == 0)
		return (0);
	while (str[i] && len <= (arg->pr - ft_wsize(str[i])))
	{
		len = len + ft_wsize(str[i]);
		i++;
	}
	return (len);
}

int				ft_putwc(int c, t_flag *arg, int max)
{
	char	*s;
	int		len;
	int		k;

	k = (c == 0 ? 1 : ft_wsize(c));
	if (!(s = ft_strnew(1)))
		exit(0);
	ft_precisionchar(&s, arg, max);
	if (arg->ch != 0)
		ft_champwchar(&s, arg, k);
	k = (arg->ch != 0 ? arg->ch : 1);
	if (arg->at[2] != 1)
		ft_putstr(s);
	if (ft_wsize(c) != -1)
		ft_putwchar(c);
	if (arg->at[2] == 1)
		ft_putstr(s);
	len = (c == 0 ? k : (int)ft_strlen(s) + ft_wsize(c));
	if (ft_wsize(c) == -1)
		len = -1;
	free(s);
	return (len);
}

int				ft_putws(wchar_t *str, t_flag *arg)
{
	char	*s;
	int		len;
	int		p;

	if (str != NULL)
	{
		if (!(s = ft_strnew(1)))
			exit(0);
		if ((len = ft_wsizetot(str)) == -1)
			return (-1);
		p = (arg->pr == -1 ? len : ft_sublen(str, arg));
		if (arg->ch != 0)
			ft_champwchar(&s, arg, p);
		if (arg->at[2] != 1)
			ft_putstr(s);
		(arg->pr == -1 ? ft_putwstr(str) : ft_putwstrsub(str, p));
		if (arg->at[2] == 1)
			ft_putstr(s);
		len = (int)ft_strlen(s) + p;
		free(s);
	}
	else
		len = ft_puts(NULL, arg, -1);
	return (len);
}
