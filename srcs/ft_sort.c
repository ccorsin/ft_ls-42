/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:48:30 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/08 16:11:21 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_sort_path_lex(t_env *env, int (*cmp)(char *, char *))
{
	int				i;
	int				k;
	char			*tmp;
	struct stat		st;

	i = 0;
	while (i < env->np)
	{
		k = i + 1;
		while (k < env->np)
		{
			if ((lstat(env->p[i], &st) < lstat(env->p[k], &st)) ||
				((lstat(env->p[i], &st) == lstat(env->p[k], &st)) &&
				(*cmp)(env->p[i], env->p[k]) == 0))
			{
				tmp = env->p[i];
				env->p[i] = env->p[k];
				env->p[k] = tmp;
			}
			k++;
		}
		i++;
	}
}

static void		ft_sort_path_lex2(t_env *env, int (*cmp)(char *, char *),
		int (*cmp2)(char *, char *))
{
	int				i;
	int				k;
	char			*tmp;
	struct stat		st;

	i = 0;
	while (i < env->np)
	{
		k = i + 1;
		while (k < env->np)
		{
			if ((lstat(env->p[i], &st) < lstat(env->p[k], &st)) ||
			((lstat(env->p[i], &st) == lstat(env->p[k], &st)) &&
			(((lstat(env->p[k], &st) == -1) &&
			(*cmp)(env->p[i], env->p[k]) == 0) || ((lstat(env->p[k], &st) == 0)
			&& (*cmp2)(env->p[i], env->p[k]) == 0))))
			{
				tmp = env->p[i];
				env->p[i] = env->p[k];
				env->p[k] = tmp;
			}
			k++;
		}
		i++;
	}
}

static void		ft_sort_path_time(t_env *e, int (*cmp)(time_t, time_t))
{
	int				i;
	int				k;
	struct stat		st;
	struct stat		st2;

	ft_raz(&k, &i);
	if (e->np > 1)
	{
		while (k == 0)
		{
			while (i < e->np - 1)
			{
				k = 1;
				if (lstat(e->p[i], &st) == -1 || lstat(e->p[i + 1], &st2) == -1)
					i++;
				else
				{
					if ((*cmp)(st.st_mtime, st2.st_mtime) == 0)
						ft_swap_path(&e->p[i], &e->p[i + 1], &k, &i);
					else
						i++;
				}
			}
		}
	}
}

static void		ft_sort_path_time_u(t_env *e, int (*cmp)(time_t, time_t))
{
	int				i;
	int				k;
	struct stat		st;
	struct stat		st2;

	ft_raz(&k, &i);
	if (e->np > 1)
	{
		while (k == 0)
		{
			while (i < e->np - 1)
			{
				k = 1;
				if (lstat(e->p[i], &st) == -1 || lstat(e->p[i + 1], &st2) == -1)
					i++;
				else
				{
					if ((*cmp)(st.st_atime, st2.st_atime) == 0)
						ft_swap_path(&e->p[i], &e->p[i + 1], &k, &i);
					else
						i++;
				}
			}
		}
	}
}

void			ft_sort(t_env *env)
{
	if (env->t == 0 && env->r == 0)
		ft_sort_path_lex(env, ft_lex_up);
	else if (env->t == 0 && env->r == 1)
		ft_sort_path_lex2(env, ft_lex_up, ft_lex_down);
	else if (env->t == 1 && env->r == 0)
	{
		ft_sort_path_lex(env, ft_lex_up);
		if (env->u == 0)
			ft_sort_path_time(env, ft_time_up);
		else
			ft_sort_path_time_u(env, ft_time_up);
	}
	else if (env->t == 1 && env->r == 1)
	{
		ft_sort_path_lex(env, ft_lex_down);
		if (env->u == 0)
			ft_sort_path_time(env, ft_time_down);
		else
			ft_sort_path_time_u(env, ft_time_down);
	}
}
