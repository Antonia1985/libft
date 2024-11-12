/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:42:29 by apavlopo          #+#    #+#             */
/*   Updated: 2024/11/12 18:42:47 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

static size_t	count_segments(const char *s, char c)
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
			in_segment = 0;
		i++;
	}
	return (count);
}

static char	*allocate_segment(const char *s, size_t start, size_t end)
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

static void	free_segments(char **segments)
{
	size_t	i;

	i = 0;
	while (segments[i])
	{
		free(segments[i]);
		i++;
	}
	free(segments);
}

static char	**create_segments(const char *s, char c, size_t segment_count)
{
	char	**segments;
	size_t	i;
	size_t	seg_idx;
	size_t	start;

	segments = (char **)malloc((segment_count + 1) * sizeof(char *));
	if (!segments)
		return (NULL);
	i = 0;
	seg_idx = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			segments[seg_idx] = allocate_segment(s, start, i);
			if (!segments[seg_idx])
			{
				free_segments(segments);
				return (NULL);
			}
			seg_idx++;
		}
		else
			i++;
	}
	segments[seg_idx] = NULL;
	return (segments);
}

char	**ft_split(char const *s, char c)
{
	size_t	segment_count;

	if (!s)
		return (NULL);
	segment_count = count_segments(s, c);
	return (create_segments(s, c, segment_count));
}
