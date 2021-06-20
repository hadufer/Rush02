/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:32:35 by hadufer           #+#    #+#             */
/*   Updated: 2021/06/20 17:32:27 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

t_stack	*push_stack(t_stack *stack, char *data)
{
	t_stack	*tmp;
	t_stack	*insert;

	tmp = stack;
	insert = malloc(sizeof(t_stack));
	if (!insert)
		return (stack);
	insert->next = tmp;
	insert->data = data;
	stack = insert;
	return (stack);
}

t_stack	*pop_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	tmp = stack;
	if (tmp->next)
		tmp_next = tmp->next;
	else
		tmp_next = NULL;
	free(tmp);
	return (tmp_next);
}

t_stack	*init(void)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	tmp->next = NULL;
	tmp->data = NULL;
	return (tmp);
}

int	print_tab_clear(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data)
		{
			ft_putstr(stack->data);
			if (stack->next->next)
				ft_putstr(" ");
		}
		stack = pop_stack(stack);
	}
	stack = pop_stack(stack);
	return (1);
}
