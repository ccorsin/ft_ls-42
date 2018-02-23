/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:19:22 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 13:19:57 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		ft_type_file(mode_t c)
{
	char	a;

	if (S_ISREG(c) != 0)
		a = '-';
	else if (S_ISCHR(c) != 0)
		a = 'c';
	else if (S_ISBLK(c) != 0)
		a = 'b';
	else if (S_ISFIFO(c) != 0)
		a = 'p';
	else if (S_ISLNK(c) != 0)
		a = 'l';
	else if (S_ISSOCK(c) != 0)
		a = 's';
	else if (S_ISDIR(c) != 0)
		a = 'd';
	else
		a = '-';
	return (a);
}

char		*ft_mode(mode_t c)
{
	char	*s;

	if (!(s = ft_strnew(11)))
		exit(1);
	s[10] = '\0';
	s[0] = ft_type_file(c);
	s[1] = (c & S_IRUSR ? 'r' : '-');
	s[2] = (c & S_IWUSR ? 'w' : '-');
	s[3] = (c & S_IXUSR ? 'x' : '-');
	s[3] = (c & S_ISUID ? 'S' : s[3]);
	if ((c & S_IXUSR) && (c & S_ISUID))
		s[3] = 's';
	s[4] = (c & S_IRGRP ? 'r' : '-');
	s[5] = (c & S_IWGRP ? 'w' : '-');
	s[6] = (c & S_IXGRP ? 'x' : '-');
	s[6] = (c & S_ISGID ? 'S' : s[6]);
	if ((c & S_IXGRP) && (c & S_ISGID))
		s[6] = 's';
	s[7] = (c & S_IROTH ? 'r' : '-');
	s[8] = (c & S_IWOTH ? 'w' : '-');
	s[9] = (c & S_IXOTH ? 'x' : '-');
	s[9] = (c & S_ISVTX ? 't' : s[9]);
	if ((c & S_ISVTX) && (c & S_IXUSR) == 0 && (c & S_IXGRP) == 0)
		s[9] = 'T';
	return (s);
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
	if ((diff < (-15778463)) || (diff > (15778463)))
		tmp = ft_strjoin(ft_strsub(s, 4, 7), ft_strsub(ft_strchr_rev(s, ' '),
			0, ft_end_nb(ft_strchr_rev(s, ' '))));
	else
		tmp = ft_strsub(s, 4, 12);
	return (tmp);
}

int			ft_affichage_l_file(t_env *env, int i, t_max *chp)
{
	struct stat		st;
	char			*s;
	char			buf[1000];

	if (lstat(env->file[i], &st) == -1)
		return (1);
	s = ft_mode(st.st_mode);
	ft_printf("%s", s);
	ft_print_attr(env->file[i]);
	ft_printf(" %*d ", chp->l, st.st_nlink);
	ft_print_uid(st, chp, env);
	ft_print_size(st, chp);
	free(s);
	ft_printf("%s %s", ft_time(st, env), env->file[i]);
	s = ft_mode(st.st_mode);
	if (s[0] == 'l')
	{
		ft_bzero(buf, 1000);
		readlink(env->file[i], buf, 1000);
		ft_printf(" -> %s", buf);
	}
	ft_printf("\n");
	free(s);
	return (0);
}

int			ft_affichage_l_repo(char *str, char *str2, t_max *chp, t_env *env)
{
	struct stat		st;
	char			*s;
	char			buf[1000];

	if (lstat(str, &st) == -1)
		return (1);
	s = ft_mode(st.st_mode);
	ft_printf("%s", s);
	ft_print_attr(str);
	ft_printf(" %*d ", chp->l, st.st_nlink);
	ft_print_uid(st, chp, env);
	ft_print_size(st, chp);
	free(s);
	ft_printf("%s %s", ft_time(st, env), str2);
	s = ft_mode(st.st_mode);
	if (s[0] == 'l')
	{
		ft_bzero(buf, 1000);
		readlink(str, buf, 1000);
		ft_printf(" -> %s", buf);
	}
	free(s);
	ft_printf("\n");
	return (0);
}
