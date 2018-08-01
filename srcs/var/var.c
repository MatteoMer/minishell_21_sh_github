/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 22:09:58 by xmazella          #+#    #+#             */
/*   Updated: 2018/08/01 22:54:36 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "var.h"

t_var					*var_new(char *name, char *value)
{
	t_var				*var;

	if ((var = (t_var *)malloc(sizeof(t_var))) == NULL)
		return (NULL);
	var->name = name;
	var->value = value;
	var->export = 0;
	var->next = NULL;
	return (var);
}

int						var_set(t_var **var_lst, char *name, char *value)
{
	t_var				*var;

	if ((var = var_get(*var_lst, name)))
	{
		var->value = value;
		return (0);
	}
	if ((var = var_new(name, value)))
	{
		var_add(var_lst, var);
		return (1);
	}
	return (-1);
}

int						var_unset(t_var **var_lst, char *name)
{
	t_var				*ptr;
	t_var				*tmp;
	t_var				*prev;

	ptr = *var_lst;
	prev = NULL;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, name) == 0)
		{
			if (prev == NULL)
				*var_lst = *var_lst->next;
			else
				prev->next = ptr->next;
			free(ptr);
			return (0);
		}
		prev = ptr;
		ptr = ptr->next;
	}
	return (1);
}

t_var					*var_get(t_var *var_lst, char *name)
{
	while (var_lst)
	{
		if (ft_strcmp(var_lst->name, name) == 0)
			return (var_lst);
		var_lst = var_lst->next;
	}
	return (NULL);
}

void					var_add(t_var **var_lst, t_var *var)
{
	if (var)
	{
		var->next = *var_lst;
		*var_lst = var;
	}
}
