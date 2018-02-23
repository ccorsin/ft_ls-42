/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:42:16 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/02 09:02:07 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ft_tri_swap(t_sub **current, t_sub **suiv)
{
	char			*s;
	struct dirent	*t;
	char			*u;
	t_sub			*tmp;
	t_sub			*tmp2;

	tmp = *current;
	tmp2 = *suiv;
	s = tmp->way;
	t = tmp->rfile;
	u = tmp->name;
	tmp->way = tmp2->way;
	tmp->rfile = tmp2->rfile;
	tmp->name = tmp2->name;
	tmp2->way = s;
	tmp2->rfile = t;
	tmp2->name = u;
}

static void			ft_sort_file_lex(t_sub *elem, int (*cmp)(char *, char *))
{
	t_sub			*suiv;
	t_sub			*current;

	current = elem;
	while (current->next != NULL)
	{
		suiv = current->next;
		while (suiv != NULL)
		{
			if ((*cmp)(current->name, suiv->name) == 0)
				ft_tri_swap(&current, &suiv);
			suiv = suiv->next;
		}
		current = current->next;
	}
}

static void			ft_sort_file_time(t_sub *elem, int (*cmp)(time_t, time_t),\
		int (*cmp2)(char *, char *))
{
	t_sub			*suiv;
	t_sub			*current;
	struct stat		st;
	struct stat		st2;

	current = elem;
	while (current->next != NULL)
	{
		suiv = current->next;
		while (suiv != NULL)
		{
			if (lstat(current->way, &st) == -1 || lstat(suiv->way, &st2) == -1)
				break ;
			if ((*cmp)(st.st_mtime, st2.st_mtime) == 0)
				ft_tri_swap(&current, &suiv);
			else if ((*cmp)(st.st_mtime, st2.st_mtime) == 2)
			{
				if ((*cmp2)(current->name, suiv->name) == 0)
					ft_tri_swap(&current, &suiv);
			}
			suiv = suiv->next;
		}
		current = current->next;
	}
}

static void			ft_sort_file_time_u(t_sub *elem, int (*cmp)(time_t, time_t),
		int (*cmp2)(char *, char *))
{
	t_sub			*suiv;
	t_sub			*current;
	struct stat		st;
	struct stat		st2;

	current = elem;
	while (current->next != NULL)
	{
		suiv = current->next;
		while (suiv != NULL)
		{
			if (lstat(current->way, &st) == -1 || lstat(suiv->way, &st2) == -1)
				break ;
			if ((*cmp)(st.st_atime, st2.st_atime) == 0)
				ft_tri_swap(&current, &suiv);
			else if ((*cmp)(st.st_atime, st2.st_atime) == 2)
			{
				if ((*cmp2)(current->name, suiv->name) == 0)
					ft_tri_swap(&current, &suiv);
			}
			suiv = suiv->next;
		}
		current = current->next;
	}
}

void				ft_sort_list(t_sub *begin, t_env *env)
{
	if ((env->t == 0 && env->r == 0) || env->f == 1)
		ft_sort_file_lex(begin, ft_lex_up);
	else if (env->t == 0 && env->r == 1 && env->f == 0)
		ft_sort_file_lex(begin, ft_lex_down);
	else if (env->t == 1 && env->r == 0 && env->f == 0)
	{
		if (env->u == 0)
			ft_sort_file_time(begin, ft_time_up, ft_lex_up);
		else
			ft_sort_file_time_u(begin, ft_time_up, ft_lex_up);
	}
	else if (env->t == 1 && env->r == 1 && env->f == 0)
	{
		if (env->u == 0)
			ft_sort_file_time(begin, ft_time_down, ft_lex_down);
		else
			ft_sort_file_time_u(begin, ft_time_down, ft_lex_down);
	}
}
