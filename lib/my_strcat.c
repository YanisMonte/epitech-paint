/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** day07
*/

#include "../include/lib.h"

char *my_strcat(char *dest, char const *src)
{
    char *result = malloc(my_strlen(dest) + my_strlen(src) + 1);
    int i = 0;
    int j = my_strlen(dest);

    result[my_strlen(dest) + my_strlen(src)] = '\0';
    while (dest[i] != '\0') {
        result[i] = dest[i];
        i++;
    }
    i = 0;
    while (src[i] != '\0') {
        result[i + j] = src[i];
        i += 1;
    }
    return (result);
}
