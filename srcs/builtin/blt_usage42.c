/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_usage42.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:27:41 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/06 22:34:12 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int					blt_usage42(void)
{
	ft_putendl("Welcome to our 42sh");
	ft_putendl("This program is a shell, with many cool things !");
	ft_putendl("");
	ft_putendl("");
	ft_putendl("You can type any cool you want like `ls' for instance !");
	ft_putendl("");
	ft_putendl("");
	ft_putendl("You can configure our 42sh by using the config file in\
~/.config/42sh/.42shrc");
	ft_putendl("");
	ft_putendl("");
	ft_putendl("We hope you'll like our shell !");
	return (1);
}
