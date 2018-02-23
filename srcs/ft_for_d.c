/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:19:22 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 12:47:02 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_raz(int *k, int *i)
{
	*k = 0;
	*i = 0;
}

static char	*ft_time(struct stat st, t_env *env)
{
	char		*s;
	time_t		date;
	time_t		today;
	time_t		diff;
	char		*tmp;

	today = time(NULL);
	if (env->u == 0)
		date = st.st_mtime;
	else
		date = st.st_atime;
	s = ctime(&date);
	diff = today - date;
	if (diff > (15778463) || diff < (-15778463))
	{
		if (!(tmp = ft_strjoin(ft_strsub(s, 4, 7), ft_strsub(s, 19, 5))))
			exit(1);
	}
	else
	{
		if (!(tmp = ft_strsub(s, 4, 12)))
			exit(1);
	}
	return (tmp);
}

void		ft_champ_file_d(t_max *chp, t_env *env)
{
	int				i;
	struct stat		st;
	int				n;

	i = 0;
	n = 0;
	while (i < env->np)
	{
		if (env->p[i] != 0)
		{
			if (lstat(env->p[i], &st) == -1)
				exit(1);
			chp->l = (lg_n(st.st_nlink) > chp->l ? lg_n(st.st_nlink) : chp->l);
			chp->s = (lg_n(st.st_size) > chp->s ? lg_n(st.st_size) : chp->s);
		}
		i++;
	}
}

int			ft_affichage_l_file_d(t_env *env, int i, t_max *chp)
{
	struct stat		st;
	char			*s;
	char			buf[1000];

	if (lstat(env->p[i], &st) == -1)
		return (1);
	s = ft_mode(st.st_mode);
	ft_printf("%s", s);
	ft_print_attr(env->p[i]);
	ft_printf(" %*d ", chp->l, st.st_nlink);
	ft_print_uid(st, chp, env);
	ft_print_size(st, chp);
	free(s);
	ft_printf("%s %s", ft_time(st, env), env->p[i]);
	s = ft_mode(st.st_mode);
	if (s[0] == 'l')
	{
		ft_bzero(buf, 1000);
		readlink(env->p[i], buf, 1000);
		ft_printf(" -> %s", buf);
	}
	ft_printf("\n");
	free(s);
	return (0);
}
