/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:03:09 by mawad             #+#    #+#             */
/*   Updated: 2023/07/08 19:23:30 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*buffer;
	size_t			s1len;
	size_t			s2len;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	buffer = (char *)malloc((s1len + s2len + 1) * sizeof(*buffer));
	if (buffer == NULL)
		return (NULL);
	while (*s1)
	{
		buffer[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		buffer[i++] = *s2;
		s2++;
	}
	buffer[i] = '\0';
	return (buffer);
}
