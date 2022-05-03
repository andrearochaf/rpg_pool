/*
** ETNA PROJECT, 2022
** $NAME_OF_THE_PROJECT
** File description:
** 		No file there, just an etna header example
*/

#include <string.h>

char *my_strncpy(char *dest, const char *src, int n)
{
    int i;
    i = 0;

    while (src[i] != '\0' && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return dest;
}