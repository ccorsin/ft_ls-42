/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:36:25 by ccorsin           #+#    #+#             */
/*   Updated: 2018/01/11 18:19:55 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_conv1(t_flag *arg, va_list ap)
{
	if (arg->lg == 1)
		return (ft_int(va_arg(ap, int), arg));
	else if (arg->lg == 2)
		return (ft_int(va_arg(ap, int), arg));
	else if (arg->lg == 3)
		return (ft_lint(va_arg(ap, long int), arg));
	else if (arg->lg == 4)
		return (ft_llint(va_arg(ap, long long int), arg));
	else if (arg->lg == 5)
		return (ft_intm(va_arg(ap, intmax_t), arg));
	else if (arg->lg == 6)
		return (ft_sizet(va_arg(ap, size_t), arg));
	else
		return (ft_int(va_arg(ap, int), arg));
}

static int		ft_conv2(t_flag *arg, va_list ap)
{
	if (arg->lg == 1)
		return (ft_uint(va_arg(ap, unsigned int), arg));
	else if (arg->lg == 2)
		return (ft_uint(va_arg(ap, unsigned int), arg));
	else if (arg->lg == 3)
		return (ft_ulint(va_arg(ap, unsigned long int), arg));
	else if (arg->lg == 4)
		return (ft_ullint(va_arg(ap, unsigned long long int), arg));
	else if (arg->lg == 5)
		return (ft_uintm(va_arg(ap, uintmax_t), arg));
	else if (arg->lg == 6)
		return (ft_usizet(va_arg(ap, size_t), arg));
	else
		return (ft_uint(va_arg(ap, unsigned int), arg));
}

static int		ft_conv3(t_flag *arg, va_list ap)
{
	if (arg->lg == 1)
		return (ft_uintbase(va_arg(ap, unsigned int), arg));
	else if (arg->lg == 2)
		return (ft_uintbase(va_arg(ap, unsigned int), arg));
	else if (arg->lg == 3)
		return (ft_ulintbase(va_arg(ap, unsigned long int), arg));
	else if (arg->lg == 4)
		return (ft_ullintbase(va_arg(ap, unsigned long long int), arg));
	else if (arg->lg == 5)
		return (ft_uintmbase(va_arg(ap, uintmax_t), arg));
	else if (arg->lg == 6)
		return (ft_usizetbase(va_arg(ap, size_t), arg));
	else
		return (ft_uintbase(va_arg(ap, unsigned int), arg));
}

static int		ft_conv4(t_flag *arg, va_list ap, int max)
{
	if (max != -1)
		return (ft_putc(arg->co, arg, max));
	if (arg->co == 'c')
	{
		if (arg->lg == 0)
			return (ft_putc(va_arg(ap, int), arg, max));
		if (arg->lg == 3)
			return (ft_putwc(va_arg(ap, wchar_t), arg, max));
	}
	if (arg->co == 's')
	{
		if (arg->lg == 0)
			return (ft_puts(va_arg(ap, char*), arg, max));
		if (arg->lg == 3)
			return (ft_putws(va_arg(ap, wchar_t*), arg));
	}
	if (arg->co == '%')
		return (ft_putc(37, arg, max));
	if (arg->co == 'p')
		return (ft_putp(va_arg(ap, void*), arg));
	return (0);
}

int				ft_conversion(t_flag *arg, va_list ap, int max)
{
	int		len;

	len = 0;
	if (arg->co == 'd' || arg->co == 'i')
		len = ft_conv1(arg, ap);
	else if (arg->co == 'u')
		len = ft_conv2(arg, ap);
	else if (arg->co == 'o' || arg->co == 'x' || arg->co == 'X')
		len = ft_conv3(arg, ap);
	else if (arg->co == 'c' || arg->co == 's' || arg->co == 'p'
		|| arg->co == '%' || max != -1)
		len = ft_conv4(arg, ap, max);
	return (len);
}
