/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 22:55:16 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 22:55:18 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

int	get_good_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_number(str[i]))
			str[i] = 0;
		i = i + 1;
	}
	return (1);
}

char	*put_zero(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
		str[i++] = '0';
	str[i] = 0;
	return (str);
}

int	get_size(char *str)
{
	int	size;

	size = (ft_strlen(str) / 3);
	if (ft_strlen(str) % 3 != 0)
		size++;
	return (size);
}

int	free_blocks(char **blocks)
{
	int	i;

	i = 0;
	while (blocks[i])
		free(blocks[i++]);
	free(blocks);
	return (1);
}

char	**cut_str_blocks3(char *str)
{
	int		i;
	int		nb_pass;
	int		size;
	char	**res;

	size = get_size(str);
	res = malloc(sizeof(char *) * (size + 1));
	res[size] = NULL;
	nb_pass = -1;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (nb_pass == -1)
		{
			size--;
			nb_pass = 2;
			res[size] = malloc(sizeof (char ) * 4);
			put_zero(res[size], 4);
		}
		res[size][nb_pass] = str[i];
		nb_pass = (nb_pass - 1);
		i = i - 1;
	}
	return (res);
}
