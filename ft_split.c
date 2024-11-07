/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:40:09 by apavlopo          #+#    #+#             */
/*   Updated: 2024/11/07 13:40:23 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	count_segments(const char *s, char c)
{
	size_t	count;
	int		in_segment;
	size_t	i;

	count = 0;
	in_segment = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_segment == 0)
		{
			in_segment = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_segment = 0;
		}
		i++;
	}
	return (count);
}

char	*allocate_segment(const char *s, size_t start, size_t end)
{
	char	*segment;
	size_t	i;

	segment = (char *)malloc((end - start + 1) * sizeof(char));
	if (!segment)
		return (NULL);
	i = 0;
	while (start < end)
	{
		segment[i] = s[start];
		start++;
		i++;
	}
	segment[i] = '\0';
	return (segment);
}

void	free_segments(char **segments, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(segments[i]);
		i++;
	}
	free(segments);
}

char	**ft_split(char const *s, char c)
{
	char	**segments;
	size_t	segment_count;
	size_t	i;
	size_t	segment_index;
	size_t	start;

	if (!s)
		return (NULL);
	segment_count = count_segments(s, c);
	segments = (char **)malloc((segment_count + 1) * sizeof(char *));
	if (!segments)
		return (NULL);
	i = 0;
	segment_index = 0;
	while (s[i] != '\0' && segment_index < segment_count)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
			}
			segments[segment_index] = allocate_segment(s, start, i);
			if (!segments[segment_index])
			{
				free_segments(segments, segment_index);
				return (NULL);
			}
			segment_index++;
		}
		else
		{
			i++;
		}
	}
	segments[segment_count] = NULL;
	return (segments);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char **result;
	char delimiter;

	if (argc != 3)
	{
		printf("Usage: %s <string> <delimiter>\n", argv[0]);
		return (1);
	}
	delimiter = argv[2][0];
	result = ft_split(argv[1], delimiter);

	if (result)
	{
		for (size_t i = 0; result[i] != NULL; i++)
		{
			printf("Segment %zu: %s\n", i, result[i]);
			free(result[i]); // Free each allocated word
		}
		free(result); // Free the array itself
	}
	else
	{
		printf("Failed to split the string.\n");
	}
	return (0);
}*/
/*
int	main(void) {
	char **result = ft_split("/hello world//42 / ", '/');

	for (int i = 0; result[i] != NULL; i++) {
		printf("Segment %d: %s\n", i, result[i]);
		free(result[i]); // Free each segment
	}
	free(result); // Free the array of pointers

	return (0);
}*/
