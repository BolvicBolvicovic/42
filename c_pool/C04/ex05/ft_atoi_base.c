/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:21:55 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/16 10:25:38 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_valid_base(char *base)
{
	int	i;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return 0;
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return 0;
	}
	return 1;
}

char	*isminus(char *str, long int *ismin)
{
	int	count;

	count = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			count++;
		str++;
	}
	*ismin = count % 2; 
	return (str);
}

int	ft_atoi(char *str)
{
	int	ismin;
	int	num;
	int	ws0;
	int	ws1;

	ws0 = (*str == ' ' || *str == '\n' || *str == '\t');
	ws1 = (*str == '\v' || *str == '\f' || *str == '\r');
	num = 0;
	while (ws0 || ws1)
	{
		str++;
		ws0 = (*str == ' ' || *str == '\n' || *str == '\t');
		ws1 = (*str == '\v' || *str == '\f' || *str == '\r');
	}
	str = isminus(str, &ismin);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (ismin)
		num = -num;
	return (num);
}
// Fonction pour convertir une chaîne de caractères d'une base donnée en base 10
char *convert_from_basechar_to_base10char(char *str, char *base)
{
	int	base_len;
	int	num;
	int	power;
	int	str_len;
	int	i;
	
	str_len = 0;
	power = 1;
	num = 0;
	base_len = 0;
 	while (base[base_len])
 		base_len++;
	while (str[str_len])
		str_len++;
	i = str_len - 1;
    while (i >= 0)
    {
        int digit = char_to_digit(str[i], base);
        if (digit == -1)
            return NULL; // Caractère invalide dans la base

        num += digit * power;
        power *= base_len;

        i--;
    }

    // Convertir le nombre en une chaîne de caractères (représentation en base 10)
    i = 0;
    char temp[12]; // Max 32-bit integer en base 10 a 10 caractères
    while (num > 0)
    {
        temp[i] = '0' + (num % 10);
        num /= 10;
        i++;
    }

    // Inverser la chaîne temp
    int j = 0;
    while (i > 0)
    {
        i--;
        str[j] = temp[i];
        j++;
    }
    str[j] = '\0';
	return (str0;
}

int	ft_atoi_base(char *str, char *base)
{
	long int	validbase;
	long int	num;

	validbase = is_valid_base(char *base)
	if (!validbase)
		return (0);
	str = convert_from_basechar_to_base10char(str, base);
	if (!str)
		return (0);
	num = ft_atoi(str);
	return (num);
}
