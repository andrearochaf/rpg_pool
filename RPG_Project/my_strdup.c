/* rocha_a
** ETNA PROJECT, 2022
** $my_strncmp
** File description:
** 		comparer deux strings max n lettres
*/

#include <string.h>
#include <stdlib.h> //pour malloc


char *my_strdup(const char *src)
{
    int i = 0;

    char *dest;
    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0')
    {
        dest[i] = src[i] ;
        i++ ;
    }
    dest[i] = '\0';
    return (dest);
}
