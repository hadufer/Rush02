/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:59:23 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/19 18:56:31 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "match.h"
#include "stack.h"
#include "check_number.h"
#include "test.h"

int	first_pass(t_diclist *diclist, char **blocks)
{
	int	i;
	int	j;

	i = 0;
	while (blocks[i])
	{
		j = 0;
		while (blocks[i][j])
		{
			if (match(diclist, blocks[i] + j))
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
		i++;
	}
	return (1);
}

int	back_pass_util(t_diclist *diclist, char **blocks, int *i, int *j)
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

int	back_pass(t_diclist *diclist, char **blocks)
{
	int	i;
	int	j;

	i = 0;
	while (blocks[i])
	{
		j = 0;
		while (blocks[i][j] && blocks[i][j] != '0')
			j = j + 1;
		j--;
		while (j >= 0)
		{
			if (!back_pass_util(diclist, blocks, &i, &j))
				return (0);
		}
		i = i + 1;
	}
	return (1);
}

int	solver(t_diclist *diclist, char *input)
{
	int		i;
	char	*tmp;
	char	**blocks;

	i = 0;
	blocks = cut_str_blocks3(input);
	first_pass(diclist, blocks);
	back_pass(diclist, blocks);
	while (diclist->stack)
	{
		printf("%s\n", diclist->stack->data);
		if (diclist->stack)
			diclist->stack = pop_stack(diclist->stack);
	}
	return (1);
}
