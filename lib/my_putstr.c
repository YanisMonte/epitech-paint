/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr
*/
#include "../include/lib.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
