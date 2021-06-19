/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:34:08 by rahmed            #+#    #+#             */
/*   Updated: 2021/06/19 18:02:45 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "parsing.h"

int	main(void)//(int argc, char **argv)
{
/*TESTS*/
char *str;
	str = ft_readdic("test.dict");
	//////ft_putstr(str);
	str = ft_trimspaces(str);
	ft_putstr(str);
/*
	int		val;
	char	*strdic;
	int		len;
	int		i;

	val = 0;
	if (argc == 2)
	{
		if (ft_atoi(argv[2]) >= 0)
			val = ft_atoi(argv[1]);
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
			val = ft_atoi(argv[2]);
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
*/
	return (0);
}
