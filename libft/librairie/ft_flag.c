/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:21:01 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/11 18:06:38 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_flag		*ft_fillattribut(const char *s, int i, int n, t_flag *arg)
{
	int		j;

	j = 0;
	if (!(arg->at = (int*)malloc(sizeof(int) * 5)))
		exit(0);
	while (j < 5)
	{
		arg->at[j] = 0;
		j++;
	}
	while (i < n)
	{
		if (s[i] == '#')
			arg->at[0] = 1;
		if (s[i] == '0' && (s[i - 1] < 48 || s[i - 1] > 57) && s[i - 1] != '.')
			arg->at[1] = 1;
		if (s[i] == '-')
			arg->at[2] = 1;
		if (s[i] == '+')
			arg->at[3] = 1;
		if (s[i] == ' ')
			arg->at[4] = 1;
		i++;
	}
	return (arg);
}

static int			ft_fillchamp(const char *s, int i, int n)
{
	char	nb[10];
	int		j;
	int		k;

	k = 0;
	while (i < n)
	{
		if (s[i] == '.' && (s[i + 1] > 47 && s[i + 1] < 58))
		{
			i++;
			while (s[i] > 47 && s[i] < 58)
				i++;
		}
		j = i;
		if ((s[i] > 48 && s[i] < 58))
		{
			while (s[j] > 47 && s[j] < 58)
				nb[k++] = s[j++];
			nb[k] = '\0';
			return (ft_atoi(nb));
		}
		i++;
	}
	return (0);
}

static int			ft_fillprecision(const char *s, int i, int n)
{
	char	nb[10];
	int		j;
	int		k;

	k = 0;
	while (i < n)
	{
		if (s[i] == '.' && s[i + 1] > 47 && s[i + 1] < 58)
		{
			j = i + 1;
			while (s[j] > 47 && s[j] < 58)
			{
				nb[k] = s[j];
				k++;
				j++;
			}
			nb[k] = '\0';
			return (ft_atoi(nb));
		}
		if (s[i] == '.' && (s[i + 1] < 48 || s[i + 1] > 57))
			return (0);
		i++;
	}
	return (-1);
}

static int			ft_filllongueur(const char *s, int i, int n)
{
	int		lg;

	lg = 0;
	while (i < n)
	{
		if (s[i] == 'l' && s[i + 1] == 'l')
			lg = 4;
		else if (s[i] == 'l' && s[i - 1] != 'l' && s[i + 1] != 'l')
			lg = 3;
		else if (s[i] == 'h' && s[i + 1] == 'h' && lg < 1)
			lg = 1;
		else if (s[i] == 'h' && s[i - 1] != 'h' && s[i + 1] != 'h' && lg < 2)
			lg = 2;
		else if (s[i] == 'j')
			lg = 5;
		else if (s[i] == 'z')
			lg = 6;
		i++;
	}
	return (lg);
}

t_flag				*ft_flag(const char *s, int i, t_flag *arg, int max)
{
	int		j;
	int		n;

	j = i;
	while ((max == -1 && (s[j] != 's' && s[j] != 'S' && s[j] != 'p' \
			&& s[j] != 'd' && s[j] != 'D' && s[j] != 'i' && s[j] != 'o' \
			&& s[j] != 'O' && s[j] != 'u' && s[j] != 'U' && s[j] != 'x' \
			&& s[j] != 'X' && s[j] != 'c' && s[j] != 'C' && s[j] != '\0' \
			&& s[j] != '%')) || (max != -1 && j < max))
		j++;
	n = j;
	arg = ft_fillattribut(s, i, n, arg);
	arg->ch = ft_fillchamp(s, i, n);
	arg->pr = ft_fillprecision(s, i, n);
	arg->lg = ft_filllongueur(s, i, n);
	arg->co = s[j];
	arg->max = max;
	if (arg->co == 'U' || arg->co == 'O' || arg->co == 'D' || arg->co == 'C'
			|| arg->co == 'S')
	{
		arg->lg = 3;
		arg->co = arg->co + 32;
	}
	return (arg);
}
