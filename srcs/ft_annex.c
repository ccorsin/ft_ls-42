/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:55:38 by ccorsin           #+#    #+#             */
/*   Updated: 2018/02/09 12:41:59 by ccorsin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_strjoinb(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	n;
	char	*str;

	str = NULL;
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	j = 0;
	if (s1 && s2)
	{
		if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		i = 0;
		while (s1[i])
			str[j++] = s1[i++];
		str[j++] = '/';
		i = 0;
		while (s2[i])
			str[j++] = s2[i++];
		str[j] = '\0';
		return (str);
	}
	else
		return (0);
}

int		ft_end_nb(char *s)
{
	int		i;

	i = 1;
	while (s[i] > 47 && s[i] < 58 && s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	ft_repo_error2(char *s)
{
	char	*str;

	if (!(str = ft_strjoin("ls: ", s)))
		exit(1);
	perror(str);
	free(str);
}

void	ft_swap_path(char **s1, char **s2, int *k, int *i)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	*k = 0;
	*i = 0;
}

void	ft_print_attr(char *s)
{
	int		attr;
	acl_t	acl;
	char	str[1000];

	attr = (int)listxattr(s, str, 1000, XATTR_NOFOLLOW);
	if (attr > 0)
		ft_printf("@");
	else
	{
		acl = acl_get_file(s, ACL_TYPE_EXTENDED);
		(acl != 0 ? ft_printf("+") : ft_printf(" "));
	}
}
