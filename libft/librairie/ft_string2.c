/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:19:18 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/05 12:19:32 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_uint(unsigned int n, t_flag *arg)
{
	char	*s;
	int		len;

	if (arg->lg == 2)
		s = ft_itoalglgint((unsigned short int)n);
	else if (arg->lg == 1)
		s = ft_itoalglgint((unsigned char)n);
	else
		s = ft_itoalglgint((unsigned)n);
	ft_precisionnb(n, &s, arg);
	ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int		ft_ulint(unsigned long int n, t_flag *arg)
{
	char	*s;
	int		len;

	s = ft_itoaulgint(n);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int		ft_ullint(unsigned long long int n, t_flag *arg)
{
	char	*s;
	int		len;

	s = ft_itoaulgint(n);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int		ft_uintm(intmax_t n, t_flag *arg)
{
	char	*s;
	int		len;

	s = ft_itoaulgint((unsigned long long int)n);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}

int		ft_usizet(size_t n, t_flag *arg)
{
	char	*s;
	int		len;

	s = ft_itoaulgint((unsigned long long int)n);
	s = *ft_precisionnb(n, &s, arg);
	s = *ft_attribut(n, &s, arg);
	if (arg->ch != 0)
		s = *ft_champ(n, &s, arg);
	ft_putstr(s);
	len = (int)ft_strlen(s);
	free(s);
	return (len);
}
