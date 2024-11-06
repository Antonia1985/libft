#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*populate_string(char *src)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(12);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*string_edge_case(int n, int min, int max)
{
	size_t	i;
	char	*str_num;

	i = 0;
	str_num = (char *)malloc(12);
	if (!str_num)
		return (NULL);
	if (n == min)
	{
		char *min_s = "-2147483648";
		str_num = populate_string(min_s);
		return (str_num);
	}
	else if (n == max)
	{
		char *max_s = "2147483647";
		str_num = populate_string(max_s);
		return (str_num);
	}
	else if (n == 0)
	{
		str_num[i] = '0';
		i++;
		str_num[i] = '\0';
		return (str_num);
	}
	return (str_num);
}

char	*integer_to_string(char *dest, int n, size_t i)
{
	while (n != 0)
	{
		dest[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*reverse_string(char *src, size_t str_len, size_t start)
{
	char	swap;

	while (start < (str_len + start) / 2)
	{
		swap = src[start];
		src[start] = src[str_len - 1 - start];
		src[str_len - start - 1] = swap;
		start++;
	}
	return (src);
}

char	*ft_itoa(int n)
{
	size_t	start;
	size_t	str_len;
	int		min;
	int		max;
	char	*str_num;

	start = 0;
	min = -2147483648;
	max = 2147483647;
	if (n == min || n == max || n == 0)
		return (string_edge_case(n, min, max));
	str_num = (char *)malloc(12);
	if (n < 0)
	{
		str_num[start] = '-';
		n = -n;
		start++;
	}
	str_num = integer_to_string(str_num, n, start);
	str_len = ft_strlen(str_num);
	str_num = reverse_string(str_num, str_len, start);
	return (str_num);
}
/*int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648)); // Prints "-2147483648"
	printf("%s\n", ft_itoa(2147483647));  // Prints "2147483647"
	printf("%s\n", ft_itoa(0));           // Prints "0"
	printf("%s\n", ft_itoa(-123));        // Prints "-123"
	printf("%s\n", ft_itoa(456));         // Prints "456"
	return (0);
}*/