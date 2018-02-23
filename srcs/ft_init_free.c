/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:03:26 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 12:48:37 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_env	*ft_init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		exit(1);
	ft_bzero(env, sizeof(t_env));
	return (env);
}

t_max	*ft_init_max(void)
{
	t_max	*chp;

	if (!(chp = (t_max*)malloc(sizeof(t_max))))
		exit(1);
	ft_bzero(chp, sizeof(t_max));
	chp->mn = 3;
	chp->mj = 2;
	return (chp);
}

void	ft_subdelone(t_sub **begin)
{
	free((*begin)->way);
	free((*begin)->name);
	free(*begin);
}

void	ft_free_lst(t_sub **tmp)
{
	t_sub	*el;

	while (*tmp != NULL)
	{
		el = (*tmp)->next;
		ft_subdelone(tmp);
		*tmp = el;
	}
	*tmp = NULL;
}

void	ft_repo_error(t_sub **begin)
{
	char	*str;
	t_sub	*elem;

	elem = *begin;
	if (!(str = ft_strjoin("ls: ", elem->name)))
		exit(1);
	perror(str);
	free(str);
}
