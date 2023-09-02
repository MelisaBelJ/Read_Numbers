
#include "Rush02.h"

int	main(int na, char **args)
{
	int	aux;

	if (na == 2 || na == 3)
	{
		aux = -90;
		if (na == 3 && check_file(args[2]) != -1)
			read_nbr(ft_atoi(args[1], &aux), args[2]);
		else
			read_nbr_default(ft_atoi(args[1], &aux));
	}
	else
		ft_puterror("Error\n");
	return (0);
}

void	read_nbr(int nbr, char *dict_path)
{
	struct s_element	*element_list;

	read_dict(dict_path, &element_list);
	if (nbr < 0)
	{
		ft_puterror("Error\n");
		exit(1);
	}
	convert(nbr, element_list, 1);
	ft_putstr("\n");
	free_list(element_list);
}

void	read_nbr_default(int nbr)
{
	read_nbr(nbr, "numbers.dict");
}

void	ft_puterror(char *str)
{
	write(2, str, ft_strlen(str));
}

void	free_list(struct s_element *head)
{
	if (head != NULL)
	{
		free(head->word);
		free_list(head->next);
		free(head);
	}
}
