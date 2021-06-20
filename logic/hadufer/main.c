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
	int	n;
	int	i;

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
int	main(void)
{
	// creating two **char array to link numbers and alphabetic_representation with an index
	char **number;
	char **alphabetic_representation;
	int 	i;
	int	number_fill;
	int	size;
	char alpha[41][12] = {{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"},{"ten"},{"eleven"},{"twelve"},{"thirteen"},{"fourteen"},{"fifteen"},{"sixteen"},{"seventeen"},{"eighteen"},{"nineteen"},{"twenty"},{"thirty"},{"forty"},{"fifty"},{"sixty"},{"seventy"},{"eighty"},{"ninety"},{"hundred"}, {"thousand"},{"million"},{"billion"},{"trillion"},{"quadrillion"},{"quintillion"},{"sextillion"},{"septillion"},{"octillion"},{"nonillion"},{"decillion"},{"undecillion"}};
	size = 32;
	number = (char **)malloc(sizeof(char *) * size);
	alphabetic_representation = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		number[i] = malloc(sizeof(*number) * 4);
		alphabetic_representation[i] = malloc(sizeof(*alphabetic_representation) * 12);
		i++;
	}
	i = 0;
	number_fill = 0;
	// filling numbers tab
	while (i < size)
	{
		if (i <= 19)
		{
			number[i] = ft_itoa(number_fill);
			i++;
			number_fill++;
		}
		else if ( i >= 20 && i < 28)
		{
			number[i] = ft_itoa(number_fill);
			i++;
			number_fill += 10;
		}
		else if (i == 28)
		{
			number[i] = ft_itoa(number_fill);
			i++;
			number_fill *= 10;
		}
		else
		{
			number[i] = ft_itoa(number_fill);
			i++;
			number_fill = number_fill * 10 * 10 * 10;
		}
	}
	i = 0;
	while (i < size)
	{
		alphabetic_representation[i] = alpha[i]; 
		i++;
	}
	/* Afficher les tableaux pour tester 
	i = 0;
	while (i < size)
	{
		printf("Number : %s\n Alphabet repr : %s\n", number[i],alphabetic_representation[i]);
		i++;
	} */
	i = 0;
	t_diclist	*diclist;
	diclist = malloc(sizeof(diclist));
	diclist->key = number;
	diclist->value = alphabetic_representation;
	diclist->stack = init();
	char	*test;
	asprintf(&test,"0");
	solver(diclist, test);
}
