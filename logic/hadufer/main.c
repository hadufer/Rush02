/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:34:08 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 21:57:19 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "check_number.h"
#include "match.h"
#include "parsingtools.h"
#include "struct.h"
#include "solver.h"
#include "utils.h"

int	cond_prepars(int argc, char **argv, char **readdic, char **str)
{
	if (argc == 2)
	{
		*(readdic) = ft_strdup("numbers.dict");
		*str = argv[1];
	}
	else if (argc == 3)
	{
		*(readdic) = argv[1];
		*str = argv[2];
	}
	else
	{
		ft_putstr ("Error\n");
		return (0);
	}
	if (!is_number((*str)[0]) || !get_good_number(*str))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	free_tabs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

int	size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i = i + 1;
	return (i);
}

int	main(int argc, char **argv)
{
	t_diclist	*diclist;
	char		*readdic;
	char		*str;

	if (!cond_prepars(argc, argv, &readdic, &str) || !ft_readdic(readdic))
	{
		if (!ft_readdic(readdic))
			ft_putstr("Error\n");
		free(readdic);
		return (0);
	}
	diclist = malloc(sizeof(t_diclist));
	diclist->key = ft_getkey(ft_readdic(readdic));
	diclist->value = ft_getvalue(ft_readdic(readdic));
	diclist->stack = init();
	if (!diclist->value || !diclist->key || \
size_tab(diclist->key) != size_tab(diclist->value))
		ft_putstr("Dict Error\n");
	else if (!solver(diclist, str))
		ft_putstr("Error\n");
	free_tabs(diclist->key);
	free_tabs(diclist->value);
	free(readdic);
	free(diclist);
}
