/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:24:20 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/04 17:31:53 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		**ft_addprecision(char **s, int k, t_flag *arg)
{
	char	*tmp;
	char	*pref;

	if (!(pref = ft_strzero(arg->pr - ft_strlen(*s) + 2 * k)))
		exit(0);
	if (!(tmp = ft_strsub(*s, k, (ft_strlen(*s) - k))))
		exit(0);
	if (!(*s = ft_strjoin(pref, tmp)))
		exit(0);
	if (k == 1)
		*s[0] = '-';
	free(tmp);
	free(pref);
	return (s);
}

char			**ft_precisionnb(long n, char **s, t_flag *arg)
{
	char	*tmp2;
	int		k;

	k = (n < 0 ? 1 : 0);
	if ((arg->pr == 0) && n == 0)
	{
		tmp2 = *s;
		if (!(*s = ft_strnew(1)))
			exit(0);
		free(tmp2);
		return (s);
	}
	if (arg->pr != 0)
	{
		if ((int)ft_strlen(*s) - k >= arg->pr)
			return (s);
		else
		{
			tmp2 = *s;
			ft_addprecision(s, k, arg);
			free(tmp2);
		}
	}
	return (s);
}

char			**ft_precisionchar(char **s, t_flag *arg, int max)
{
	char	*tmp;

	if (arg->pr == -1 || (arg->pr == 0 && (arg->co == 37 || max != -1)))
		return (s);
	else if (arg->pr == 0)
	{
		tmp = *s;
		if (!(*s = ft_strnew(1)))
			exit(0);
		free(tmp);
		return (s);
	}
	else
	{
		tmp = *s;
		if (!(*s = ft_strsub(*s, 0, arg->pr)))
			exit(0);
		free(tmp);
		return (s);
	}
}
