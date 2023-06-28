#include "struct_db.h"

char* get_town()
{
    char symb;
    char* str = (char*) calloc(0, sizeof(char));
    for (int i = 0; (symb = getchar()) != ' ' && symb != '\n' && symb != '\t'; i)
    {
        str = (char*) realloc(str, (i + 2) * sizeof(char));
        str[i++] = symb;
        str[i] = '\0';
    }
    if (*str >= 'a' && *str <= 'z')
    {
        *str += ('A'-'a');
    }
    return str;
}

ull get_num()
{
    char symb;
    char* str = (char*) calloc(0, sizeof(char));
    for (int i = 0; (symb = getchar()) != '\n'; i)
    {
        str = (char*) realloc(str, (i + 2) * sizeof(char));
        str[i++] = symb;
        str[i] = '\0';
    }
    ull num = strtoull(str, NULL, 10);
    return num;
}

char get_command()
{
    int i = 0;
    char symb;
    char str[2];
    do
    {
        symb = getchar();
        str[i] = symb;
        i = 1;
    } while (symb != '\n');
    return str[0];
}