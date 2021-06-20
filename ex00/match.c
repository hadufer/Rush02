/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:21:32 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 22:55:36 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "match.h"

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

char	*match(t_diclist *diclist, char *search)
{
	int	i;

	i = 0;
	while (diclist->key[i])
	{
		if (!ft_strcmp(diclist->key[i], search))
			return (diclist->value[i]);
		i++;
	}
	return (NULL);
}
