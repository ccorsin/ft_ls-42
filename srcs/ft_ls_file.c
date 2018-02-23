/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:19:22 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 13:06:04 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_perror(t_env *env, int i, char *str)
{
	if (!(str = ft_strjoin("ls: ", env->p[i])))
		exit(1);
	perror(str);
	env->file[i] = 0;
	env->p[i] = 0;
	env->y = 1;
	free(str);
}

static int		ft_file_tab2(t_env *env, int i, char *str, struct stat *st)
{
	if (lstat(env->p[i], st) == -1)
	{
		ft_perror(env, i, str);
		return (1);
	}
	else if (errno == 20 || ((errno == 2 || errno == 13)
		&& S_ISLNK(st->st_mode) != 0))
	{
		env->file[i] = env->p[i];
		env->p[i] = 0;
	}
	else if (S_ISDIR(st->st_mode) == 0)
		ft_perror(env, i, str);
	return (0);
}

static int		ft_file_tab(t_env *env, int i)
{
	char		*str;
	struct stat	st;

	str = NULL;
	if (errno == 2 && ft_strcmp(env->p[i], "") == 0)
	{
		if (!(str = ft_strjoin("ls: fts_open: ", env->p[i])))
			exit(1);
		perror(str);
		env->p[i] = 0;
		env->file[i] = 0;
		free(str);
		exit(1);
	}
	else
		ft_file_tab2(env, i, str, &st);
	return (0);
}

void			ft_print_file(t_env *env, t_max *chp)
{
	int		i;

	i = 0;
	while (i < env->np)
	{
		if (env->file[i] != 0 && env->p[i] == 0)
		{
			if (env->l == 1)
			{
				ft_champ_file(chp, env);
				ft_affichage_l_file(env, i, chp);
			}
			else
				ft_printf("%s\n", env->file[i]);
			env->y = 0;
			env->x = 1;
		}
		i++;
	}
}

int				ft_level0(t_env *env)
{
	DIR				*rep;
	int				i;

	i = 0;
	while (i < env->np)
	{
		rep = opendir(env->p[i]);
		if (rep == NULL && env->d == 0)
			ft_file_tab(env, i);
		else
			env->file[i] = 0;
		if (rep != NULL)
		{
			if (closedir(rep) == -1)
				exit(1);
		}
		i++;
	}
	return (0);
}
