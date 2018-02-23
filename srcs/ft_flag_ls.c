/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:18:16 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/08 10:15:30 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_analyse_flag2(t_env *env, char *s, int i)
{
	if (s[i] == 'd')
		env->d = 1;
	else if (s[i] == 'f')
	{
		env->f = 1;
		env->a = 1;
	}
	else if (s[i] == 'u')
		env->u = 1;
	else if (s[i] == '1' && env->l == 1)
		env->l = 0;
	else if (s[i] != '1')
	{
		write(2, "ls: illegal option -- ", 22);
		write(2, &s[i], 1);
		write(2, "\nusage: ls [-Radfglrt1] [file ...]\n", 35);
		exit(1);
	}
}

static void		ft_analyse_flag(t_env *env, char *s)
{
	int		i;

	i = 1;
	while (s[i])
	{
		if (s[i] == 'r')
			env->r = 1;
		else if (s[i] == 'R')
			env->gr = 1;
		else if (s[i] == 'l')
			env->l = 1;
		else if (s[i] == 't')
			env->t = 1;
		else if (s[i] == 'a')
			env->a = 1;
		else if (s[i] == 'g')
		{
			env->g = 1;
			env->l = 1;
		}
		else
			ft_analyse_flag2(env, s, i);
		i++;
	}
}

static void		ft_analyse_path(t_env *env, int i, int n, char **argv)
{
	int		j;
	int		k;

	(void)argv;
	j = 0;
	k = i;
	if (!(env->p = (char **)malloc(sizeof(char *) * (n - i + 1))))
		exit(1);
	if (!(env->file = (char **)malloc(sizeof(char *) * (n - i + 1))))
		exit(1);
}

static void		ft_fill_path(t_env *env, int i, int n, char **argv)
{
	int		j;

	j = 0;
	if (i == n)
	{
		env->p[0] = ".";
		env->np = 1;
	}
	else
	{
		while (i < n)
		{
			env->p[j] = argv[i];
			j++;
			i++;
		}
	}
}

t_env			*ft_flag_ls(int argc, char **argv)
{
	t_env	*env;
	int		i;
	int		j;
	int		n;

	env = ft_init_env();
	n = argc;
	i = 1;
	j = 0;
	if (argc > 1)
		while (i < n && argv[i][0] == '-' && ft_strcmp(argv[i], "-"))
		{
			if (ft_strcmp(argv[i], "--") == 0)
			{
				i++;
				break ;
			}
			else
				ft_analyse_flag(env, argv[i++]);
		}
	env->np = n - i;
	ft_analyse_path(env, i, n, argv);
	ft_fill_path(env, i, n, argv);
	return (env);
}
