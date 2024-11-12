#include <stdlib.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

#include <stdio.h>
void    *ft_calloc(size_t nmemb, size_t size)
{
    size_t actual_size = nmemb * size;
    char    *buffer = (char *)malloc(nmemb * size);
    if (buffer == NULL)
    {
        return NULL;
    }

    ft_bzero(buffer, actual_size);

    return buffer;
}

int main(void) {
    size_t num_elements = 5;
    int *arr = (int *)ft_calloc(num_elements, sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print the allocated memory to verify it is zeroed out
    printf("Array elements after ft_calloc:\n");
    for (size_t i = 0; i < num_elements; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]); // Each element should be 0
    }

    // Free the allocated memory
    free(arr);
    return 0;
}