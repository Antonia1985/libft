/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:42:23 by apavlopo          #+#    #+#             */
/*   Updated: 2024/11/07 13:43:08 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	size_t	len;
	char	*joined;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 1;
	joined = (char *)malloc(len);
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		joined[len1 + i] = s2[i];
		i++;
	}
	joined[len] = '\0';
	return (joined);
}
/*#include <stdio.h>
#include <stdlib.h>  // For strtoul

int main (int argc, char * argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s <string> <start_index> <length>\n", argv[0]);
		return (1);
	}

	char const *s1 = argv[1];

	char const *s2 = argv[2];

	char * result =  ft_strjoin(s1, s2);

	if (result) { // Check if the result is NULL
		printf("Joined string: %s\n", result);
		free(result); // Free the allocated memory
	} else {
		printf("Error: Failed to allocate memory or invalid parameters.\n");
	}

	return (0);
}*/
