/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:53:18 by mawad             #+#    #+#             */
/*   Updated: 2023/08/14 16:45:05 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_str(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(s, 1);
	return ((int) ft_strlen(s));
}

static int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	case_choose(va_list args, const char *str, unsigned int *i)
{
	unsigned int	len;

	if (str[*i + 1] == 'x' || str[*i + 1] == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), str[*i + 1]);
	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		len = ft_print_nbr(va_arg(args, int));
	if (str[*i + 1] == 's')
		len = ft_print_str(va_arg(args, char *));
	if (str[*i + 1] == 'p')
		len = ft_print_address(va_arg(args, unsigned long long int));
	if (str[*i + 1] == 'c')
		len = ft_print_char(va_arg(args, int));
	if (str[*i + 1] == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	if (str[*i + 1] == '%')
	{
		ft_putchar_fd(str[*i + 1], 1);
		len = 1;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	len;
	const char		*set;

	va_start(args, str);
	i = 0;
	len = 0;
	set = "cdisxXpu%%";
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr(set, str[i + 1]))
		{
			len += case_choose(args, str, &i);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len += 1;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	ft_printf("len is %d\n", ft_printf("\70\n"));
// 	printf("len is %d\n", printf("\70\n"));
// }

// int main()
// {
// 	//ft_printf("%X", 4294967295);
// 	ft_printf("%p", NULL);

// 	return (0);
// }