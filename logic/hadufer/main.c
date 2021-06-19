#include "stdlib.h"

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char *str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

#include "stack.h"
#include "match.h"
#include "check_number.h"
#include "test.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	// creating two **char array to link numbers and alphabetic_representation with an index
	char **number; 
	char **alphabetic_representation;
	int	i;
	int	j;
	int	number_fill;
	char alpha[29][12] = {{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"},{"ten"},{"eleven"},{"twelve"},{"thirteen"},{"fourteen"},{"fifteen"},{"sixteen"},{"seventeen"},{"eighteen"},{"nineteen"},{"twenty"},{"thirty"},{"forty"},{"fifty"},{"sixty"},{"seventy"},{"eighty"},{"ninety"},{"hundred"}};
	number = (char **)malloc(sizeof(char *) * 29);
	alphabetic_representation = (char **)malloc(sizeof(char *) * 29);
	i = 0;
	while (i < 29)
	{
		number[i] = malloc(sizeof(*number) * 3);
		alphabetic_representation[i] = malloc(sizeof(*alphabetic_representation) * 12);
		i++;
	}
	i = 0;
	number_fill = 0;
	// filling numbers tab
	while (i < 29)
	{
		if (i <= 19)
		{
			number[i] = ft_itoa(number_fill);
			i++;
			number_fill++;
		}
		else
		{
			number[i] = ft_itoa(number_fill);
			i++;
			number_fill += 10;
		}
	}
	i = 0;
	while (i < 29)
	{
		alphabetic_representation[i] = alpha[i]; 
		i++;
	}
	i = 0;
	t_diclist	*diclist;
	diclist = malloc(sizeof(diclist));
	diclist->key = number;
	diclist->value = alphabetic_representation;
	diclist->stack = init();
	char	*test;
	asprintf(&test,"218");
	solver(diclist, test);
}
