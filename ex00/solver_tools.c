/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 22:55:59 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 22:56:01 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "match.h"
#include "stack.h"
#include "check_number.h"
#include "struct.h"
#include "utils.h"

int	nb_blocks(char **blocks)
{
	int	i;

	i = 0;
	while (blocks[i])
		i = i + 1;
	return (i);
}

int	is_block_zero(char *block)
{
	int	i;

	i = 0;
	while (block[i])
	{
		if (block[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	is_blank_number(char **blocks)
{
	int	i;

	i = 0;
	while (blocks[i])
		if (!is_block_zero(blocks[i++]))
			return (0);
	return (1);
}
