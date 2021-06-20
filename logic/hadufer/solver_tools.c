/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abittel <abittel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:22:35 by abittel           #+#    #+#             */
/*   Updated: 2021/06/20 21:24:22 by abittel          ###   ########.fr       */
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
