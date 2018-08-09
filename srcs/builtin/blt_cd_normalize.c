/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_cd_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:56:08 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/09 18:04:20 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		blt_cd_sort_rollback(char **s, int i)
{
	if (s[i] == NULL)
		return ;
	ft_strdel(s + i);
	while (s[i + 1])
	{
		s[i] = s[i + 1];
		i++;
	}
	s[i] = NULL;
}

static char		**blt_cd_sort(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i][0] == '.')
		{
			if (s[i][1] == '\0')
				blt_cd_sort_rollback(s, i);
			else if (s[i][1] == '.' && s[i][2] == '\0')
			{
				blt_cd_sort_rollback(s, i);
				if (i > 0)
				{
					blt_cd_sort_rollback(s, i - 1);
					i--;
				}
			}
			else
				i++;
		}
		else
			i++;
	}
	return (s);
}

static char		*blt_cd_join(char **s)
{
	char	*str;
	int		i;

	if ((str = ft_strnew(1)) == NULL)
		malloc_error();
	str[0] = '/';
	i = 0;
	if (!s)
		return (str);
	while (s[i])
	{
		if ((str = ft_strjoinf(str, s[i])) == NULL)
			malloc_error();
		if ((str = ft_strjoinf(str, "/")) == NULL)
			malloc_error();
		i++;
	}
	return (str);
}

static char		*blt_cd_normalize_step2(char *s)
{
	char	**ft_tab;
	char	*str;
	int		i;

	i = 0;
	if ((ft_tab = ft_strsplit(s, '/')) == NULL)
		malloc_error();
	ft_tab = blt_cd_sort(ft_tab);
	str = blt_cd_join(ft_tab);
	ft_deltab(&ft_tab);
	return (str);
}

char			*blt_cd_normalize(char *s)
{
	char *cpath;

	cpath = blt_cd_normalize_step2(s);
	return (cpath);
}
