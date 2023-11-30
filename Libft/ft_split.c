/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:34:07 by mawad             #+#    #+#             */
/*   Updated: 2023/07/19 13:58:41 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

static int	word_counter(const char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], sep))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && !is_sep(s[i], sep))
			i++;
	}
	return (count);
}

static char	*word_create(int i, int j, const char *s, char sep)
{
	char	*new_word;
	int		index;

	index = 0;
	new_word = (char *)malloc((j + 1) * sizeof(*new_word));
	if (new_word == NULL)
		return (NULL);
	while (s[i] && !is_sep(s[i], sep))
	{
		new_word[index] = s[i];
		i++;
		index++;
	}
	new_word[index] = '\0';
	return (new_word);
}

static void	array_filler(char **arr, const char *s, char sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (is_sep(s[i], sep) && s[i])
			i++;
		else
		{
			j = 0;
			while (s[i + j] != '\0' && !is_sep(s[i + j], sep))
				j++;
			arr[k++] = word_create(i, j, s, sep);
			if (arr[k - 1] == NULL)
			{
				while (k > 0)
					free(arr[k - 1]);
				return ;
			}
			i = i + j;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**buffer;

	if (!s)
		return (NULL);
	words = word_counter(s, c);
	buffer = (char **)malloc((words + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	array_filler(buffer, s, c);
	buffer[words] = NULL;
	return (buffer);
}

// #include<stdio.h>
// int main()
// {
// 	int count = word_counter("chinimala", ' ');
//  	char **buffer = ft_split("chinimala", ' ');
// 	int i = 0;
// 		printf("%d\n", count);
// 	while (i < count)
// 	{
// 		printf("%s", buffer[i]);
// 		free(buffer[i++]);
// 	}
// 	free (buffer);
// 	return (0);
// }