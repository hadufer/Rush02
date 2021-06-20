/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:34:08 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/20 11:55:13 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "parsing.h"

int	main(void)//(int argc, char **argv)
{
/*TESTS*/
//t_diclist test;
char *str;
//char *str2;
char **key;
char **value;
	str = ft_readdic("test.dict");

	key = ft_getkey(str);
	ft_putstr("---KEY LIST---\n");
	int i = 0;
	while (key[i] != NULL)
	{
		ft_putstr(key[i]);
		ft_putstr("\n");
		i++;
	}
	free(key);

	str = ft_readdic("test.dict");
	value = ft_getvalue(str);
	ft_putstr("---VALUE LIST---\n");
	int j = 0;
	while (value[j] != NULL)
	{
		ft_putstr(value[j]);
		ft_putstr("\n");
		j++;
	}
	free(value);
/*
	int		val;
	char	*strdic;
	int		len;
	int		i;

	val = 0;
	if (argc == 2)
	{
		if (ft_atoi(argv[2]) >= 0)
			val = (argv[1]);
		else
			ft_putstr("Error\n");
	}
	else if (argc == 3)
	{
		i = 0;
		len = ft_strlen(argv[1]);
		while (i < len)
		{
			strdic[i] = argv[1][i];
		}
		if (ft_atoi(argv[2]) >= 0)
			val = (argv[2]);
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
*/
	return (0);
}
