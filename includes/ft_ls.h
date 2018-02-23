/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:16:45 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 14:14:02 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct			s_sub
{
	struct s_sub		*next;
	struct dirent		*rfile;
	char				*way;
	char				*name;
}						t_sub;

typedef struct			s_env
{
	int		l;
	int		r;
	int		gr;
	int		t;
	int		a;
	int		g;
	int		d;
	int		f;
	int		u;
	int		y;
	int		x;
	char	**p;
	int		np;
	char	**file;
}						t_env;

typedef struct			s_max
{
	int		l;
	int		u;
	int		g;
	int		s;
	int		mn;
	int		mj;
}						t_max;

t_env					*ft_flag_ls(int argc, char **argv);
int						ft_affichage_l_file(t_env *env, int i, t_max *chp);
int						ft_affichage_l_repo(char *str, char *str2, t_max *chp,
							t_env *env);
int						ft_affichage_l_file_d(t_env *env, int i, t_max *chp);
char					*ft_strjoinb(const char *s1, const char *s2);
void					ft_sort(t_env *env);
int						ft_level0(t_env *env);
void					ft_print_file(t_env *env, t_max *chp);
int						ft_get_repo(t_env *env);
t_sub					*ft_subnew(struct dirent **rfile, char *way, char *nam);
void					ft_print_list(t_sub **begin, t_env *env, t_max *chp);
void					ft_sort_list(t_sub *begin, t_env *env);
void					ft_deeper(t_sub **begin, t_env *env);
void					ft_subdel(t_sub **begin);
void					ft_subdelone(t_sub **begin);
void					ft_lstdel2(t_sub **begin);
int						ft_count_tot(t_sub **begin, t_max *chp, t_env *env);
t_max					*ft_init_max(void);
int						lg_n(int n);
int						lg_s(char *s);
void					ft_champ_file(t_max *chp, t_env *env);
void					ft_champ_file_d(t_max *chp, t_env *env);
int						ft_lex_up(char *s, char *t);
int						ft_lex_down(char *s, char *t);
int						ft_time_up(time_t t, time_t m);
int						ft_time_down(time_t t, time_t m);
int						ft_recursion(t_sub **begin, t_env *env, char *s);
int						ft_deep_repo(t_env *env, char *s);
void					ft_free_lst(t_sub **tmp);
void					ft_repo_error(t_sub **begin);
void					ft_repo_error2(char *s);
void					ft_print_uid(struct stat st, t_max *chp, t_env *env);
void					ft_print_size(struct stat st, t_max *chp);
t_env					*ft_init_env(void);
char					ft_type_file(mode_t c);
char					*ft_mode(mode_t c);
void					ft_raz(int *k, int *i);
int						ft_end_nb(char *s);
t_sub					*ft_build_lst(DIR *rep, t_env *env, char *s);
void					ft_swap_path(char **s1, char **s2, int *k, int *i);
void					ft_print_attr(char *s);
void					ft_fill_chp(t_max *chp, struct stat st);

#endif
