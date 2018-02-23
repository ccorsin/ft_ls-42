/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:19:22 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 14:13:33 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_recur_dir(DIR *rep, t_sub **elem, t_env *env, char *s)
{
	struct stat		st;
	t_sub			*begin;

	begin = *elem;
	if (lstat(begin->way, &st) == -1)
		return (1);
	if (closedir(rep) == -1)
		exit(1);
	if (ft_strcmp(s, "/.") && ft_strcmp(s, "/..") && S_ISDIR(st.st_mode)
			&& ((env->a == 0 && s[1] != '.') || (env->a == 1)))
	{
		ft_printf("\n%s:\n", begin->way);
		if ((st.st_mode) & S_IXUSR)
			ft_deep_repo(env, begin->way);
	}
	return (0);
}

int				ft_recursion(t_sub **elem, t_env *env, char *s)
{
	t_sub			*begin;
	DIR				*rep;
	struct stat		st;

	begin = *elem;
	while (begin != NULL)
	{
		rep = opendir(begin->way);
		if (lstat(begin->way, &st) == -1)
			return (1);
		s = ft_strchr_rev(begin->way, '/');
		if (rep != NULL)
			ft_recur_dir(rep, &begin, env, s);
		if (rep == NULL && (errno == 13) && S_ISLNK(st.st_mode) == 0)
		{
			ft_printf("\n%s:\n", begin->way);
			ft_repo_error(&begin);
		}
		begin = begin->next;
	}
	return (0);
}

int				ft_deep_repo(t_env *env, char *s)
{
	DIR					*rep;
	t_sub				*begin;
	t_max				*chp;
	t_sub				**tmp;
	struct stat			st;

	begin = NULL;
	rep = opendir(s);
	if ((lstat(s, &st) == -1) || (((st.st_mode) & S_IRUSR) != 0
		&& ((st.st_mode) & S_IXUSR) == 0))
		return (1);
	if (rep == NULL && (errno == 13))
		ft_repo_error2(s);
	if (rep != NULL)
		begin = ft_build_lst(rep, env, s);
	tmp = &begin;
	chp = ft_init_max();
	if (env->l == 1)
		ft_count_tot(&begin, chp, env);
	ft_print_list(&begin, env, chp);
	free(chp);
	if (env->gr == 1)
		ft_recursion(&begin, env, s);
	ft_free_lst(&begin);
	return (0);
}

static int		ft_get_repo2(t_env *env, int i)
{
	struct stat		st;
	t_max			*chp;

	if (lstat(env->p[i], &st) == -1)
		return (1);
	if ((env->d == 1 || S_ISLNK(st.st_mode) != 0) && env->l == 1)
	{
		chp = ft_init_max();
		ft_champ_file_d(chp, env);
		ft_affichage_l_file_d(env, i, chp);
		free(chp);
	}
	else
	{
		if (env->p[i] != 0 && env->d == 0 && env->y == 0 && ((env->x == 0
			&& i != 0) || (env->x == 1)))
			ft_printf("\n");
		if (env->np > 1 && env->p[i] != 0 && env->d == 0)
			ft_printf("%s:\n", env->p[i]);
		if (env->p[i] != 0 && env->d == 0)
			ft_deep_repo(env, env->p[i]);
		if (env->d == 1 && env->l == 0)
			ft_printf("%s\n", env->p[i]);
	}
	return (0);
}

int				ft_get_repo(t_env *env)
{
	int			i;

	i = 0;
	while (i < env->np)
	{
		if (env->p[i] != 0)
			ft_get_repo2(env, i);
		i++;
	}
	return (0);
}
