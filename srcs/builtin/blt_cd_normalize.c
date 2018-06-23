/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_cd_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:56:08 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/22 18:54:18 by mmervoye         ###   ########.fr       */
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

	str = ft_strnew(1);
	str[0] = '/';
	i = 0;
	if (!s)
		return (str);
	while (s[i])
	{
		str = ft_strjoinf(str, s[i]);
		str = ft_strjoinf(str, "/");
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
	ft_tab = ft_strsplit(s, '/');
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
