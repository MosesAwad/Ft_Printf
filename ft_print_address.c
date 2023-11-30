/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:23:31 by mawad             #+#    #+#             */
/*   Updated: 2023/07/23 18:32:01 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	address_len(unsigned long long int c)
{
	int	len;

	len = 0;
	if (c == 0)
		return (ft_strlen("0x0"));
	while (c >= 16)
	{
		c = c / 16;
		len++;
	}
	return (len + 1);
}

static void	put_address(unsigned long long int c)
{
	const char	*set;

	set = "0123456789abcdef";
	if (c >= 16)
	{
		put_address(c / 16);
		put_address(c % 16);
	}
	else
	{
		ft_putchar_fd(set[c % 16], 1);
	}
}

int	ft_print_address(unsigned long long int c)
{
	unsigned int	len;

	len = 0;
	if (c == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (ft_strlen("0x0"));
	}
	ft_putstr_fd("0x", 1);
	put_address(c);
	return (ft_strlen("0x") + address_len(c));
}
