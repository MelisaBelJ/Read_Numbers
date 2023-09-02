
#include "Rush02.h"

struct s_element	*add_element(struct s_element *list, int nbr,
							char *character)
{
	struct s_element	*new_element;

	new_element = (struct s_element *)malloc(sizeof(struct s_element));
	if (new_element == NULL)
		return (NULL);
	new_element->nbr = nbr;
	new_element->word = character;
	new_element->next = list;
	return (new_element);
}

int	parse_line(char *line, int *nbr, char **character)
{
	char	*colon;
	char	*nbr_ptr;
	int		new_line;

	colon = line;
	new_line = 1;
	while (*colon != '\0' && *colon != ':')
		colon++;
	if (*colon != '\0')
	{
		new_line = 0;
		*nbr = 0;
		nbr_ptr = line;
		while (nbr_ptr < colon && is_digit(*nbr_ptr))
		{
			*nbr = (*nbr * 10) + (*nbr_ptr - '0');
			nbr_ptr++;
		}
		while (is_space(*nbr_ptr) || *nbr_ptr == ':')
			nbr_ptr++;
		*character = ft_strdup(nbr_ptr);
	}
	return (new_line);
}

int	read_line(int fd, char *buf)
{
	int	total;

	total = 0;
	while (read(fd, buf, 1) > 0 && *buf != '\n')
	{
		total++;
		buf++;
	}
	*buf = '\0';
	return (total);
}

void	read_dict(const char *filename, struct s_element **list)
{
	int					nbr;
	char				*character;
	char				*buffer;
	int					file;
	struct s_element	*current;

	file = open(filename, O_RDONLY);
	current = NULL;
	buffer = malloc(100);
	while (file != -1 && read_line(file, buffer) > 0)
	{
		if (!check_format(buffer))
		{
			ft_puterror("Dict Error\n");
			exit(1);
		}
		if (!parse_line(buffer, &nbr, &character))
			current = add_element(current, nbr, character);
	}
	free(buffer);
	if (file == -1)
		ft_puterror("Dict Error\n");
	else
		close(file);
	*list = current;
}
