#include <string.h>

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

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	i = 0;
	while (i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (s_len);
}

/*#include <stdio.h>
#include <stdlib.h>
//#include "ft_strlcpy.h"  // Include your custom strlcpy header

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_string> <dest_length>\n", argv[0]);
        return 1;
    }

    const char *src = argv[1];
    size_t dest_length = (size_t)atoi(argv[2]);

    // Allocate destination buffer with specified length
    char dest[dest_length];

    // Call the custom strlcpy function
    size_t src_length = ft_strlcpy(dest, src, dest_length);

    // Print results
    printf("Source string: \"%s\"\n", src);
    printf("Destination buffer length: %zu\n", dest_length);
    printf("Copied string: \"%s\"\n", dest);
    printf("Length of source string: %zu\n", src_length);
    printf("Was truncation needed? %s\n", (src_length >= dest_length) ? "Yes" : "No");

    return 0;
}*/