/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:48:17 by apavlopo          #+#    #+#             */
/*   Updated: 2024/10/22 15:48:20 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
#include <stdlib.h>

void	ft_putstr_fd(char *s, int fd);
/*{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}*/

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	char	*msg;

	msg = "Memory not allocated.\n";
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
	{
		ft_putstr_fd(msg, 1);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int	main(int argc, char **argv)
{
	(void)argc;
	char *dest = ft_strdup(argv[1]);
	ft_putstr_fd(dest, 1);

	if (&argv[1] != NULL)
	{
		free(dest);
	}

	return (0);
}*/