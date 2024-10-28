#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i = 0;
    size_t len1 = 0;
    size_t len2 = 0;
    size_t len = 0;
    while(s1[len1] != '\0')
    {
        len1++;
    }
    while(s2[len2] != '\0')
    {
        len2++;
    }
    len =len1 + len2 + 1;

    char * joined = (char *)malloc(len);

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

#include <stdio.h>
#include <stdlib.h>  // For strtoul
int main (int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <string> <start_index> <length>\n", argv[0]);
        return 1;
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

    return 0;
}