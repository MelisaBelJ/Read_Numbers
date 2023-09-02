
#include "Rush02.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_print(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	check_format(char *line)
{
	if (!(*line))
		return (2);
	while (is_space(*line))
		line++;
	if (!is_digit(*line))
		return (0);
	if (!is_digit(*line))
		return (0);
	while (is_digit(*line))
		line++;
	while (is_space(*line))
		line++;
	if (*line != ':')
		return (0);
	line++;
	while (is_space(*line))
		line++;
	while (*line != '\0')
	{
		if (!is_print(*line))
			return (0);
		line++;
	}
	return (1);
}

int	check_file(char *dict_path)
{
	int	fd;

	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
		ft_puterror("Error\n");
	else
		close(fd);
	return (fd);
}
