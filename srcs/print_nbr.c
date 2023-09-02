
#include "Rush02.h"

char	*find_nbr(int nbr, struct s_element *element_list)
{
	struct s_element	*current;

	current = element_list;
	while (current != NULL)
	{
		if (current->nbr == nbr)
			return (current->word);
		current = current->next;
	}
	ft_puterror("Dict Error\n");
	exit(1);
	return (NULL);
}

int	find_bigs(int nbr, int big, struct s_element *element_list, int *i)
{
	char	*line;

	if (nbr >= big)
	{
		*i = convert(nbr / big, element_list, 0);
		if (i)
		{
			ft_putstr(" ");
			line = find_nbr(big, element_list);
			ft_putstr(line);
			nbr %= big;
			if (line[0] != '\0' && nbr != 0)
				ft_putstr(" ");
		}
	}
	return (nbr);
}

int	find_littles(int nbr, struct s_element *element_list, int *i, int zero_ok)
{
	int		and;

	and = 0;
	if (nbr >= 20)
	{
		*i = 1;
		zero_ok = 0;
		ft_putstr(find_nbr((nbr / 10) * 10, element_list));
		nbr %= 10;
		if (nbr > 0)
			and = 1;
	}
	if (nbr > 0 && nbr < 20)
	{
		*i = 1;
		if (and == 1)
			ft_putstr(" ");
		ft_putstr(find_nbr(nbr, element_list));
	}
	else if (nbr == 0 && zero_ok)
	{
		ft_putstr(find_nbr(nbr, element_list));
	}
	return (nbr);
}

int	convert(int nbr, struct s_element *element_list, int zero_ok)
{
	int	and;
	int	i;

	and = 0;
	i = 0;
	if (nbr >= 100)
		and = 1;
	nbr = find_bigs(nbr, 1000000000, element_list, &i);
	nbr = find_bigs(nbr, 1000000, element_list, &i);
	nbr = find_bigs(nbr, 1000, element_list, &i);
	nbr = find_bigs(nbr, 100, element_list, &i);
	if (and == 1 && nbr != 0)
		ft_putstr("and ");
	if (i == 1)
		zero_ok = 0;
	nbr = find_littles(nbr, element_list, &i, zero_ok);
	return (i);
}
