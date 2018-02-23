/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champ2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:24:32 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/05 13:24:36 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char			**ft_champchar(char **s, t_flag *arg, int k)
{
	char	*tmp;
	char	*tmp2;
	char	*pref;

	if (ft_strlen(*s) - k < arg->ch || ft_strlen(*s) == 0)
	{
		if (arg->at[1] == 1 && arg->at[2] != 1)
		{
			if (!(pref = ft_strzero(arg->ch - ft_strlen(*s) - k)))
				exit(0);
		}
		else
		{
			if (!(pref = ft_strspace(arg->ch - ft_strlen(*s) - k)))
				exit(0);
		}
		if (!(tmp = ft_strdup(*s)))
			exit(0);
		tmp2 = *s;
		ft_addchamp(s, tmp, pref, arg);
		free(tmp2);
		return (s);
	}
	else
		return (s);
}

char			**ft_champwchar(char **s, t_flag *arg, int k)
{
	char	*tmp;
	char	*tmp2;
	char	*pref;

	if (k < (int)arg->ch)
	{
		if (arg->at[1] == 1 && arg->at[2] != 1)
		{
			if (!(pref = ft_strzero(arg->ch - ft_strlen(*s) - k)))
				exit(0);
		}
		else
		{
			if (!(pref = ft_strspace(arg->ch - ft_strlen(*s) - k)))
				exit(0);
		}
		if (!(tmp = ft_strdup(*s)))
			exit(0);
		tmp2 = *s;
		ft_addchamp(s, tmp, pref, arg);
		free(tmp2);
		return (s);
	}
	else
		return (s);
}
