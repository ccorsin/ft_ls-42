/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:43:14 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/11 18:36:32 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_check(const char *s, int i)
{
	int		n;

	n = i;
	while (s[i] != 's' && s[i] != 'S' && s[i] != 'p' && s[i] != 'd'
			&& s[i] != 'D' && s[i] != 'i' && s[i] != 'o' && s[i] != 'O'
			&& s[i] != 'u' && s[i] != 'U' && s[i] != 'x' && s[i] != 'X'
			&& s[i] != 'c' && s[i] != 'C' && s[i] != '\0' && s[i] != '%')
	{
		if (s[i] != ' ' && s[i] != '#' && s[i] != '+' && s[i] != '.'
		&& s[i] != '-' && (s[i] < 48 || s[i] > 57) && s[i] != 'l' && s[i] != 'h'
		&& s[i] != 'z' && s[i] != 'j' && s[i] != '*')
			return (i);
		else
			i++;
	}
	return (-1);
}

static int		ft_jump(const char *s, int i)
{
	int		j;

	j = 0;
	while (s[i] != 's' && s[i] != 'S' && s[i] != 'p' && s[i] != 'd'
			&& s[i] != 'D' && s[i] != 'i' && s[i] != 'o' && s[i] != 'O'
			&& s[i] != 'u' && s[i] != 'U' && s[i] != 'x' && s[i] != 'X'
			&& s[i] != 'c' && s[i] != 'C' && s[i] != '\0' && s[i] != '%')
	{
		i++;
		j++;
	}
	return (j);
}

static t_flag	*ft_initarg(void)
{
	t_flag	*arg;

	if (!(arg = (t_flag*)malloc(sizeof(t_flag))))
		exit(0);
	ft_bzero(arg, sizeof(t_flag));
	return (arg);
}

static int		ft_findarg(const char *format, int i, va_list ap)
{
	t_flag	*arg;
	int		max;
	int		len;

	len = 0;
	while (i < (int)ft_strlen(format))
	{
		if (format[i] == 37 && format[i + 1] != '\0')
		{
			max = ft_check(format, ++i);
			arg = ft_flag(format, i, ft_initarg(), max);
			ft_check_star(arg, ap, i, format);
			len = len + ft_conversion(arg, ap, max);
			i = ((max == -1) ? i + ft_jump(format, i) + 1 : max + 1);
			ft_free(arg);
		}
		else if (format[i] != '\0' && format[i] != 37)
		{
			ft_putchar(format[i++]);
			len++;
		}
		else if (format[i] == 37 && format[i + 1] == '\0')
			i++;
	}
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;
	int		i;

	if (format == NULL)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	i = 0;
	va_start(ap, format);
	len = ft_findarg(format, i, ap);
	va_end(ap);
	return (len);
}
