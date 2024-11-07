/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:46:10 by apavlopo          #+#    #+#             */
/*   Updated: 2024/10/22 15:47:15 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
/*int	main(int argc, char *argv[])
{
	int	i;
	char	*s;
	//char	*n = "\n";
	i = 1;
	while(i < argc)
	{
		s = argv[i];
		ft_putstr_fd(s, 1);
		//ft_putstr_fd(n, 1);
		i++;
	}
	return (0);
}*/