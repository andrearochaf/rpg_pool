/*
** ETNA PROJECT, $YEAR
** $NAME_OF_THE_PROJECT
** File description:
** 		No file there, just an etna header example
*/

void my_putstr(const char *str)
{
    for (int i=0; str[i]!='\0'; i++)
    {
        my_putchar(str[i]);
    }
}