/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:19:22 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 12:59:56 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*ft_str_path(char *s, char *s2)
{
	char	*str;

	if (ft_strcmp(s, "/"))
	{
		if (!(str = ft_strjoinb(s, s2)))
			exit(1);
	}
	else
	{
		if (!(str = ft_strjoin(s, s2)))
			exit(1);
	}
	return (str);
}

t_sub			*ft_build_lst(DIR *rep, t_env *env, char *s)
{
	struct dirent	*rfile;
	t_sub			*elem;
	t_sub			*begin;
	char			*str;
	char			*str2;

	elem = NULL;
	begin = NULL;
	while ((rfile = readdir(rep)) != NULL)
	{
		if (!(str2 = ft_strdup(rfile->d_name)))
			exit(1);
		str = ft_str_path(s, rfile->d_name);
		elem = ft_subnew(&rfile, str, str2);
		elem->next = begin;
		begin = elem;
	}
	if (closedir(rep) == -1)
		exit(1);
	ft_sort_list(elem, env);
	return (begin);
}
