#ifndef RUSH02_H
# define RUSH02_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_element {
	int					nbr;
	char				*word;
	struct s_element	*next;
};

char				*find_nbr(int nbr, struct s_element *element_list);
int					find_bigs(int nbr, int big, struct s_element *element_list,
						int *i);
int					find_littles(int nbr, struct s_element *element_list,
						int *i, int zero_ok);
int					convert(int nbr, struct s_element *element_list,
						int zero_ok);

int					is_space(char c);
int					is_digit(char c);
int					is_print(char c);
int					check_format(char *line);
int					check_file(char *dict_path);

struct s_element	*add_element(struct s_element *list, int nbr,
						char *character);
int					parse_line(char *line, int *nbr, char **character);
int					read_line(int fd, char *buf);
void				read_dict(const char *filename, struct s_element **list);

int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *src);
void				ft_putstr(char *str);
int					ft_atoi(char *str, int *char_count);

void				read_nbr(int nbr, char *dict_path);
void				read_nbr_default(int nbr);
void				ft_puterror(char *str);
void				free_list(struct s_element *head);

#endif
