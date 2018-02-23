/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:18:38 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/30 14:15:36 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct	s_flag
{
	int			*at;
	size_t		ch;
	int			pr;
	int			lg;
	char		co;
	int			max;
}				t_flag;

int				ft_printf(const char *format, ...);
t_flag			*ft_flag(const char *s, int i, t_flag *arg, int max);
int				ft_conversion(t_flag *arg, va_list ap, int max);
char			**ft_attribut(long n, char **s, t_flag *arg);
char			**ft_champ(long n, char **s, t_flag *arg);
char			**ft_champchar(char **s, t_flag *arg, int k);
char			**ft_champwchar(char **s, t_flag *arg, int k);
char			**ft_precisionnb(long n, char **s, t_flag *arg);
char			**ft_precisionchar(char **s, t_flag *arg, int max);
char			*ft_strzero(size_t size);
char			*ft_strspace(size_t size);
int				ft_int(int n, t_flag *arg);
int				ft_schar(int n, t_flag *arg);
int				ft_sint(int n, t_flag *arg);
int				ft_lint(long int n, t_flag *arg);
int				ft_llint(long long int n, t_flag *arg);
int				ft_intm(intmax_t n, t_flag *arg);
int				ft_sizet(size_t n, t_flag *arg);
int				ft_uint(unsigned int n, t_flag *arg);
int				ft_ulint(unsigned long int n, t_flag *arg);
int				ft_ullint(unsigned long long int n, t_flag *arg);
int				ft_uintm(intmax_t n, t_flag *arg);
int				ft_usizet(size_t n, t_flag *arg);
char			*ft_itoaintmax(intmax_t n);
char			*ft_itoalgint(long int n);
char			*ft_itoalglgint(long long int n);
char			*ft_itoaulgint(unsigned long int n);
char			*ft_itoabase(unsigned int n, const char *base);
char			*ft_itoallbase(unsigned long long n, const char *base);
int				ft_uintbase(unsigned int n, t_flag *arg);
int				ft_ulintbase(unsigned long int n, t_flag *arg);
int				ft_ullintbase(unsigned long long int n, t_flag *arg);
int				ft_uintmbase(intmax_t n, t_flag *arg);
int				ft_usizetbase(size_t n, t_flag *arg);
char			*ft_base(t_flag *arg);
int				ft_putc(int c, t_flag *arg, int max);
int				ft_puts(char *s, t_flag *arg, int max);
int				ft_putp(void *p, t_flag *arg);
void			ft_putstrtot(char const *s);
int				ft_putwc(int c, t_flag *arg, int max);
int				ft_putws(wchar_t *s, t_flag *arg);
char			*ft_printplus(char *s);
int				ft_wsize(int c);
void			ft_putwstrsub(wchar_t *str, int k);
void			ft_free(t_flag *arg);
void			ft_check_star(t_flag *arg, va_list ap, int i, const char *s);

#endif
