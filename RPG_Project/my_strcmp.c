/*
** ETNA PROJECT, 2022
** $NAME_OF_THE_PROJECT
** File description:
** 		No file there, just an etna header example
*/

#include <string.h>

int my_strcmp(const char *s1, const char *s2)
{
    int i;
    i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' )
    {
        i++;
    }
    return (s1[i]-s2[i]);
}