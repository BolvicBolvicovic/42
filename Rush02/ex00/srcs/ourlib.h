/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ourlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:14:15 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/27 12:58:27 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OURLIB_H
# define OURLIB_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
//main_algo
int		algo(char *dictionary, char *str);
void	algosheart(char *digits, char **dictionary, int counter_rows);
//error
int		error(char *str);
void	puterror(char *err);
//string
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
//isnumber
int		is_number(char *str);
int		modthree(char *str);
//main_allocation
char	**allocnum(char *arg);
char	**populate(char *arg, char **arr, int arg_len, int first_slot);
//find_read
char	*ft_strstr(char **str_array, int array_l, char *to_find);
int		read_words(char *str);
//triple
void	first_digit(char **array, char digit, int counter_rows);
void	second_digit(char **array, char *digits, int counter_rows);
void	third_digit(char **array, char digit, int counter_rows);
void	bignum(char **array, int counter_rows, int max, int i);
//dict
char	*read_dict(char *dictionary);
int		count_rows(char *buf);
char	**alloc_array(char *buf);
char	**copy_dict(char *dictionary);

#endif
