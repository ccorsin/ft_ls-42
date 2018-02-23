/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:57:35 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 10:18:36 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_champ_file(t_max *chp, t_env *env)
{
	int				i;
	struct stat		st;
	int				n;

	i = 0;
	n = 0;
	while (i < env->np)
	{
		if (env->file[i] != 0)
		{
			if (lstat(env->file[i], &st) == -1)
				exit(1);
			ft_fill_chp(chp, st);
		}
		i++;
	}
}

void			ft_print_size(struct stat st, t_max *chp)
{
	if (S_ISBLK(st.st_mode) == 0 && S_ISCHR(st.st_mode) == 0)
		ft_printf("%*d ", chp->s, st.st_size);
	else
		ft_printf(" %*d, %*d ", chp->mj, major(st.st_rdev), chp->mn,
				minor(st.st_rdev));
}

int				lg_n(int n)
{
	int		i;

	i = 0;
	if (n < 10)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int				lg_s(char *s)
{
	int		n;

	n = 0;
	if (s != NULL)
		n = ft_strlen(s);
	return (n);
}

void			ft_print_uid(struct stat st, t_max *chp, t_env *env)
{
	struct passwd	*guid;
	struct group	*grid;
	char			*s;
	char			*t;

	guid = NULL;
	grid = NULL;
	s = NULL;
	t = NULL;
	if (getpwuid(st.st_uid) != NULL)
	{
		guid = getpwuid(st.st_uid);
		s = guid->pw_name;
	}
	if (getgrgid(st.st_gid) != NULL)
	{
		grid = getgrgid(st.st_gid);
		t = grid->gr_name;
	}
	if (env->g == 0)
		(s != NULL ? ft_printf("%-*s  ", chp->u, s) : ft_printf("%-*d  ",
			chp->u, st.st_uid));
	(t != NULL ? ft_printf("%-*s  ", chp->g, t) : ft_printf("%-*d  ", chp->g,
			st.st_gid));
}
