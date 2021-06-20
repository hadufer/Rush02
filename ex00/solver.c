/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:59:23 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 22:56:06 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "match.h"
#include "stack.h"
#include "check_number.h"
#include "struct.h"
#include "utils.h"
#include "solve_tools.h"

int	fill_tens_words(t_diclist *diclist, char **blocks, int index)
{
	int		i;
	int		size_tab;
	char	*tens;

	size_tab = nb_blocks(blocks);
	if (((size_tab - index - 1) * 3 + 1) == 1)
		return (1);
	tens = malloc(sizeof (char ) * ((size_tab - index - 1) * 3 + 2));
	tens[0] = '1';
	i = 1;
	while (i < ((size_tab - index - 1) * 3 + 1))
		tens[i++] = '0';
	tens[i] = 0;
	if (match(diclist, tens))
		diclist->stack
			= push_stack(diclist->stack, match(diclist, tens));
	else
	{
		free(tens);
		return (0);
	}
	free(tens);
	return (1);
}

int	first_pass(t_diclist *diclist, char **blocks, int i)
{
	int	j;

	j = 0;
	while (blocks[i][j])
	{
		if (blocks[i][j] != '0' && match(diclist, blocks[i] + j))
		{
			diclist->stack
				= push_stack(diclist->stack, match(diclist, blocks[i] + j));
			while (blocks[i][j])
			{
				blocks[i][j] = '0';
				j++;
			}
		}
		else
			j++;
	}
	return (1);
}

int	back_pass_util (t_diclist *diclist, char **blocks, int *i, int *j)
{
	if (!*j)
	{
		diclist->stack
			= push_stack(diclist->stack, match(diclist, "100"));
		blocks[*i][*j + 1] = 0;
		diclist->stack
			= push_stack(diclist->stack, match(diclist, blocks[*i] + *j));
	}
	else
		diclist->stack
			= push_stack(diclist->stack, match(diclist, blocks[*i] + *j));
	blocks[*i][*j] = '0';
	*j = *j - 1;
	return (1);
}

int	back_pass(t_diclist *diclist, char **blocks, int i)
{
	int	j;

	j = 2;
	while (j >= 0)
	{
		if (blocks[i][j] == '0')
			j--;
		else if (!back_pass_util(diclist, blocks, &i, &j))
			return (0);
	}
	return (1);
}

int	solver(t_diclist *diclist, char *input)
{
	int		i;
	char	**blocks;

	blocks = cut_str_blocks3(input);
	if (is_blank_number(blocks))
	{
		diclist->stack
			= push_stack(diclist->stack, match(diclist, "0"));
		print_tab_clear(diclist->stack);
		return (1);
	}
	i = nb_blocks(blocks) - 1;
	while (i >= 0)
	{
		if (!is_block_zero(blocks[i]))
			if (!fill_tens_words(diclist, blocks, i) || \
!first_pass(diclist, blocks, i) || !back_pass(diclist, blocks, i))
				return (0);
		i--;
	}
	print_tab_clear(diclist->stack);
	free_blocks(blocks);
	return (1);
}
