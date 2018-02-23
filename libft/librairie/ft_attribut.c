/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:24:01 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/05 13:24:05 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_printhtg(char *s, t_flag *arg)
{
	char	*tmp;
	char	*pref;

	if (arg->co == 'x' || arg->co == 'p')
	{
		if (!(pref = ft_strzero(2)))
			exit(0);
		pref[1] = 'x';
	}
	if (arg->co == 'X')
	{
		if (!(pref = ft_strzero(2)))
			exit(0);
		pref[1] = 'X';
	}
	tmp = s;
	if (!(s = ft_strjoin(pref, tmp)))
		exit(0);
	free(tmp);
	free(pref);
	return (s);
}

static char		*ft_printhtg2(long n, char *s, t_flag *arg)
{
	char	*tmp;
	char	*pref;

	if ((n == 0 && arg->pr == 0) || (n != 0 && (arg->pr == 0 || arg->pr == -1)))
	{
		if (!(pref = ft_strzero(1)))
			exit(0);
		tmp = s;
		if (!(s = ft_strjoin(pref, tmp)))
			exit(0);
		free(tmp);
		free(pref);
	}
	return (s);
}

char			*ft_printplus(char *s)
{
	char	*tmp;
	char	*pref;

	if (s[0] != '-')
	{
		if (!(pref = ft_strzero(1)))
			exit(0);
		pref[0] = '+';
		tmp = s;
		if (!(s = ft_strjoin(pref, tmp)))
			exit(0);
		free(tmp);
		free(pref);
	}
	return (s);
}

static char		*ft_printsp(char *s)
{
	char	*tmp;
	char	*pref;

	if (s[0] != '-')
	{
		tmp = s;
		if (!(pref = ft_strspace(1)))
			exit(0);
		if (!(s = ft_strjoin(pref, tmp)))
			exit(0);
		free(tmp);
		free(pref);
	}
	return (s);
}

char			**ft_attribut(long n, char **s, t_flag *arg)
{
	char	*tmp;

	tmp = *s;
	if (arg->at[0] == 1 && (arg->co == 'o' || arg->co == 'x' || arg->co == 'X'
		|| arg->co == 'p'))
	{
		if (((n != 0 && (arg->co == 'x' || arg->co == 'X')) || arg->co == 'p')
		&& (arg->ch == 0 || arg->at[1] == 0 || arg->pr != -1
		|| arg->at[2] == 1 || (arg->at[1] == 1 && arg->co == 'p' && n != 0)))
			*s = ft_printhtg(tmp, arg);
		else if (arg->co == 'o')
			*s = ft_printhtg2(n, tmp, arg);
	}
	if (arg->at[3] == 1 && (arg->at[1] != 1 || (arg->at[1] == 1 && (arg->ch == 0
		|| (n == 0 && arg->pr != -1))) || arg->at[2] == 1) && (arg->co == 'd'
		|| arg->co == 'i'))
		*s = ft_printplus(tmp);
	if (arg->at[4] == 1 && arg->at[3] != 1 && (arg->at[1] != 1
		|| (arg->at[1] == 1 && arg->ch == 0)) && arg->co != 'u'
		&& arg->co != 'o' && arg->co != 'x' && arg->co != 'X' && arg->co != 'p')
		*s = ft_printsp(tmp);
	return (s);
}
