
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i = 0;
    size_t src_l = 0;
    // Handle NULL source string case
    if (!s) 
    {
        return NULL;
    }
    // Calculate the length of the source string
    while (s[src_l] != '\0')
    {
        src_l++;
    }
    // Check if start is valid
    if (start >= src_l) 
    {
        return NULL;
    }
    // Adjust len if it goes beyond the source length
    if (src_l < (start + len))
    {
        len = src_l - start;
    }

    char * substr = (char *)malloc(len + 1);
    // Return NULL if malloc fails
    if (substr == NULL)
    {
        return NULL;
    }    
    while (i < len)
    {      
        substr[i] = s[start];
        i++;
        start++;
    }
    return (substr);
}
/*#include <stdio.h>
#include <stdlib.h>  // For strtoul
int main (int argc, char * argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <string> <start_index> <length>\n", argv[0]);
        return 1;
    }
    
    char const *s = argv[1];
    
    unsigned int start =(unsigned int) strtoul(argv[2], NULL, 10); 
    
    size_t len =  strtoul(argv[3], NULL, 10);  // Converts argv[3] to an unsigned integer
    
    char * result =  ft_substr(s, start, len);
   
    if (result) { // Check if the result is NULL
        printf("Substring: %s\n", result);
        free(result); // Free the allocated memory
    } else {
        printf("Error: Failed to allocate memory or invalid parameters.\n");
    }

    return 0;
}*/