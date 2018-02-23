/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:24:18 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/05 13:24:20 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_prefzero(long n, char **s, int k, t_flag *arg)
{
	char	*pref;

	if (!(pref = ft_strzero(arg->ch - ft_strlen(*s) + k)))
		exit(0);
	if (arg->at[3] == 1 && (arg->co == 'd' || arg->co == 'i'))
		pref[0] = (n < 0 ? '-' : '+');
	else if (arg->at[4] == 1 && (arg->co == 'd' || arg->co == 'i'))
		pref[0] = 32;
	if (n < 0)
		pref[0] = '-';
	if ((((arg->co == 'x' || arg->co == 'X') && n != 0) || arg->co == 'p')
		&& arg->at[0] == 1)
	{
		pref[0] = 48;
		pref[1] = ((arg->co == 'x' || arg->co == 'p') ? 'x' : 'X');
	}
	return (pref);
}

static char		*ft_pref(long n, char **s, int k, t_flag *arg)
{
	char	*pref;

	if (arg->at[1] == 1 && arg->at[2] != 1 && arg->pr == -1)
	{
		if (!(pref = ft_prefzero(n, s, k, arg)))
			exit(0);
	}
	else
	{
		if (!(pref = ft_strspace(arg->ch - ft_strlen(*s))))
			exit(0);
		k = 0;
		if (arg->at[3] == 1 && arg->at[1] == 1 && arg->at[2] != 1 && n > 0
			&& (arg->co == 'd' || arg->co == 'i'))
			pref[ft_strlen(pref) - 1] = '+';
	}
	return (pref);
}

static char		*ft_tmp(char **s, int k, t_flag *arg)
{
	char *tmp;

	if (arg->at[1] != 1 || arg->at[2] == 1 || arg->pr != -1)
		k = 0;
	if (!(tmp = ft_strsub(*s, k, (ft_strlen(*s) - k))))
		exit(0);
	return (tmp);
}

static char		**ft_addchamp(char **s, char *tmp, char *pref, t_flag *arg)
{
	if (arg->at[2] == 1)
	{
		if (!(*s = ft_strjoin(tmp, pref)))
			exit(0);
	}
	else
	{
		if (!(*s = ft_strjoin(pref, tmp)))
			exit(0);
	}
	free(tmp);
	free(pref);
	return (s);
}

char			**ft_champ(long n, char **s, t_flag *arg)
{
	char	*tmp;
	char	*tmp2;
	char	*pref;
	int		k;
	int		l;

	k = (n < 0 ? 1 : 0);
	l = ((arg->co == 'x' || arg->co == 'X') && arg->at[1] == 1 ? 2 : 0);
	if (ft_strlen(*s) + l < arg->ch)
	{
		pref = ft_pref(n, s, k, arg);
		tmp = ft_tmp(s, k, arg);
		l = ft_strlen(tmp);
		tmp2 = *s;
		ft_addchamp(s, tmp, pref, arg);
		free(tmp2);
		return (s);
	}
	else if (arg->at[3] == 1 && n > 0 && arg->at[1] == 1)
	{
		tmp = *s;
		*s = ft_printplus(tmp);
	}
	return (s);
}
