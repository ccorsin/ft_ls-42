/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:03:26 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/05 17:58:06 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	t_env	*env;
	t_max	*chp;

	env = ft_flag_ls(argc, argv);
	if (env->f == 0)
		ft_sort(env);
	ft_level0(env);
	chp = ft_init_max();
	if (env->d == 0)
		ft_print_file(env, chp);
	free(chp);
	ft_get_repo(env);
	free(env->p);
	free(env->file);
	free(env);
	return (0);
}
