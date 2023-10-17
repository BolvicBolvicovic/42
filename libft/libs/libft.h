/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:04:13 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 15:05:35 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

int			ft_isalpha(char str);
int			ft_isdigit(char str);
int			ft_isalnum(char str);
int			ft_isascii(char str);
int			ft_isprint(char str);
int			ft_strlen(char *str);
void		*ft_memset(void *s, int c, int n);
void		ft_bzero(void *s, int n);
void		*ft_memcpy(void *dest, const void *src, int n);
void		*ft_memmove(void *dest, const void *src, int n);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, int n);
void		*ft_memchr(const void *s, int c, int n);
int			ft_memcmp(const void *s1, const void *s2, int n);
char		*ft_strnstr(const char *big, const char *little, int len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(int nmemb, int size);
char		*ft_strdup(char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
