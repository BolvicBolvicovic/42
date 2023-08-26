
#ifndef FT_RUSH_H
# define FT_RUSH_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
//string.c
int		ft_strlen(char *str);
char	*ft_strstr(char **str_array, int array_l, char *to_find);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
//number.c
int		ft_is_number(char *str);
int		ft_modthree(char *str);
//error.c
int		ft_error(char *str);
void	ft_puterror(char *err);
//main_malloc.c
char	**ft_allocate(char *arg);
char	**ft_populate(char *arg, char **arr, int arg_len, int first_slot);
int		ft_read_words(char *str);
//triple.c
void	ft_first_digit(char **array, char digit, int counter_rows);
void	ft_second_digit(char **array, char *digits, int counter_rows);
void	ft_third_digit(char **array, char digit, int counter_rows);
void	ft_ord(char **array, int counter_rows, int max, int i);
//dict.c
char	*ft_read_dict(char *dictionary);
int		ft_counter_rows(char *buf);
char	**ft_alloc_array(char *buf);
char	**ft_copy_dict_array(char *dictionary);
//main_algo.c
int		ft_algo(char *dictionary, char *str);
void	ft_algosheart(char *digits, char **dictionary, int counter_rows);

#endif
