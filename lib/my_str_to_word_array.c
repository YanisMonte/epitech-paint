/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../include/lib.h"

static int find_word(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            nb++;
        i++;
    }
    if (str[i - 1] != '\n')
        nb++;
    return (nb);
}

char **my_str_to_word_array(char *str)
{
    int nb = find_word(str);
    char **array = malloc(sizeof(char *) * (nb + 1));
    int i = 0;
    int pos = 0;
    int length = 0;

    while (str[i]) {
        length = i;
        while (str[i] != '\n' && str[i] != '\0')
            i++;
        array[pos] = malloc(sizeof(char) * (i - length + 1));
        my_strncpy(array[pos], &(str[length]), i - length);
        array[pos][i - length] = '\0';
        pos++;
        if (str[i])
            i++;
    }
    array[pos] = 0;
    return array;
}
