/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:06:31 by mawad             #+#    #+#             */
/*   Updated: 2023/07/23 16:14:17 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int	ft_print_hex(unsigned int c, char frmt);
int	ft_print_nbr(int nb);
int	ft_print_address(unsigned long long int c);
int	ft_print_unsigned(unsigned int nb);
int	ft_printf(const char *placeholders, ...);

#endif