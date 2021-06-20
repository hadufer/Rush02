/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:58:56 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 17:59:52 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bis.h"
#include "utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	char	*tmp_1;
	char	*tmp_2;

	tmp_1 = s1;
	tmp_2 = s2;
	while (*tmp_2 || *tmp_1)
	{
		if (*tmp_2 == 0 && *tmp_1 == 0)
			return (*tmp_1 - *tmp_2);
		if (*tmp_2 > *tmp_1)
			return (*tmp_1 - *tmp_2);
		if (*tmp_2 < *tmp_1)
			return (*tmp_1 - *tmp_2);
		tmp_1++;
		tmp_2++;
	}
	return (*tmp_1 - *tmp_2);
}
