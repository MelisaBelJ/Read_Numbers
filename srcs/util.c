
#include "Rush02.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	length;

	length = 0;
	while (src[length])
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(src) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_atoi(char *str, int *char_count)
{
	int	nb;
	int	pos;

	nb = 0;
	pos = 0;
	while (is_space(str[pos]))
		pos++;
	if (str[pos] == '+')
		pos++;
	if (!is_digit(str[pos]))
	{
		ft_puterror("Error\n");
		exit(1);
	}
	while (str[pos] && (is_digit(str[pos])))
		nb = nb * 10 + str[pos++] - '0';
	if (str[pos] && *char_count == -90)
	{
		ft_puterror("Error\n");
		exit(1);
	}
	*char_count = -1;
	return (nb);
}
