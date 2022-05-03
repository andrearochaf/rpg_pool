/* rocha_a
** ETNA PROJECT, 2022
** $my_strncmp
** File description:
** 		comparer deux strings max n lettres
*/

#include <string.h>

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    if (n == 0)
    {
        return (0);
    }
    n--;
    while (i < n && s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0') )
    {
        i++;
    }
    return (s1[i] - s2[i]);
}