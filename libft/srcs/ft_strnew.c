/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:50:40 by mmervoye          #+#    #+#             */
/*   Updated: 2017/11/10 14:44:59 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnew(size_t size)
{
	char		*str;

	str = (char *)malloc(sizeof(*str) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}
