/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:46:03 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 10:06:51 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_sub		*ft_subnew(struct dirent **rfile, char *way, char *nam)
{
	t_sub			*new;
	struct dirent	*file;

	file = *rfile;
	if (!(new = (t_sub *)malloc(sizeof(*new))))
		exit(0);
	if (*rfile == 0)
	{
		new->way = NULL;
		new->rfile = NULL;
		new->name = NULL;
	}
	else
	{
		new->rfile = file;
		new->way = way;
		new->name = nam;
	}
	new->next = NULL;
	return (new);
}

static void	ft_major_minor(struct stat st, t_max *chp)
{
	int		k;

	k = 0;
	if (S_ISBLK(st.st_mode) != 0 || S_ISCHR(st.st_mode) != 0)
	{
		chp->mj = ((lg_n(major(st.st_rdev)) > chp->mj) ?
			lg_n(major(st.st_rdev)) : chp->mj);
		chp->mn = ((lg_n(minor(st.st_rdev)) > chp->mn) ?
			lg_n(minor(st.st_rdev)) : chp->mn);
		k = 1;
	}
	if (k != 0)
		chp->s = ((chp->mn + chp->mj + 3) > chp->s ? (chp->mn + chp->mj + 3) :
			chp->s);
}

void		ft_fill_chp(t_max *chp, struct stat st)
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
	chp->l = (lg_n(st.st_nlink) > chp->l ? lg_n(st.st_nlink) : chp->l);
	chp->s = (lg_n(st.st_size) > chp->s ? lg_n(st.st_size) : chp->s);
	chp->u = (lg_s(s) > chp->u ? lg_s(s) : chp->u);
	chp->g = (lg_s(t) > chp->g ? lg_s(t) : chp->g);
	ft_major_minor(st, chp);
}

int			ft_count_tot(t_sub **begin, t_max *chp, t_env *env)
{
	t_sub			*current;
	struct stat		st;
	int				n;
	int				i;

	n = 0;
	i = 0;
	current = *begin;
	while (current != NULL)
	{
		if (lstat(current->way, &st) == -1 && errno != 9)
			return (1);
		if ((env->a == 0 && current->name[0] != '.') || env->a == 1)
		{
			n = n + (st.st_blocks);
			ft_fill_chp(chp, st);
			i++;
		}
		current = current->next;
	}
	if (i != 0)
		ft_printf("total %d\n", n);
	return (0);
}

void		ft_print_list(t_sub **begin, t_env *env, t_max *chp)
{
	t_sub			*current;

	current = *begin;
	while (current != NULL)
	{
		if (env->l == 1 && env->a == 1)
			ft_affichage_l_repo(current->way, current->name, chp, env);
		else if (env->l == 1 && env->a == 0)
		{
			if (current->name[0] != '.')
				ft_affichage_l_repo(current->way, current->name, chp, env);
		}
		else
		{
			if (env->a == 1)
				ft_printf("%s\n", current->name);
			else
			{
				if (current->name[0] != '.')
					ft_printf("%s\n", current->name);
			}
		}
		current = current->next;
	}
}
