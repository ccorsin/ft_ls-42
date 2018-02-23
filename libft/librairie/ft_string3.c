/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:20:03 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/05 12:20:11 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_uintbase(unsigned int n, t_flag *arg)
{
	char	*s;
	int		len;
	char	*base;

	if (!(base = ft_base(arg)))
		exit(0);
	if (arg->lg == 2)
		s = ft_itoabase((unsigned short int)n, base);
	else if (arg->lg == 1)
		s = ft_itoabase((unsigned char)n, base);
	else
		s = ft_itoabase((unsigned)n, base);
	ft_precisionnb(n, &s, arg);
	ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(base);
	free(s);
	return (len);
}

int		ft_ulintbase(unsigned long int n, t_flag *arg)
{
	char	*s;
	int		len;
	char	*base;

	if (!(base = ft_base(arg)))
		exit(0);
	s = ft_itoallbase(n, base);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(base);
	free(s);
	return (len);
}

int		ft_ullintbase(unsigned long long int n, t_flag *arg)
{
	char	*s;
	int		len;
	char	*base;

	if (!(base = ft_base(arg)))
		exit(0);
	s = ft_itoallbase(n, base);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(base);
	free(s);
	return (len);
}

int		ft_uintmbase(intmax_t n, t_flag *arg)
{
	char	*s;
	int		len;
	char	*base;

	if (!(base = ft_base(arg)))
		exit(0);
	s = ft_itoallbase(n, base);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(base);
	free(s);
	return (len);
}

int		ft_usizetbase(size_t n, t_flag *arg)
{
	char	*s;
	int		len;
	char	*base;

	if (!(base = ft_base(arg)))
		exit(0);
	s = ft_itoallbase((long long int)n, base);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(base);
	free(s);
	return (len);
}
