/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:34:08 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 17:32:41 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "parsing.h"
#include "check_number.h"
#include "match.h"
#include "parsingtools.h"
#include "struct.h"
#include "solver.h"

int	main(int argc, char **argv)
{
	t_diclist	*diclist;
	char		*readdic;
	char		*str;

	if (argc == 2)
	{
		readdic = ft_strdup("numbers.dict");
		str = argv[1];
	}
	else if (argc == 3)
	{
		readdic = argv[1];
		str = argv[2];
	}
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
	diclist = malloc(sizeof(t_diclist));
	diclist->key = ft_getkey(ft_readdic(readdic));
	diclist->value = ft_getvalue(ft_readdic(readdic));
	diclist->stack = init();
	if (!solver(diclist, str))
		ft_putstr("Error\n");
}
