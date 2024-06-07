/*
** EPITECH PROJECT, 2024
** lib h
** File description:
** lib
*/

#ifndef LIB_H
    #define LIB_H

    #include <stdarg.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>

void my_putchar(char c);

int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_putstr(char const *str);
int my_strlen(const char *str);
int mini_printf(const char *format, ...);

char *my_strcpy(char const *src);
char *my_strdup(char const *str);
char *my_str_realloc(char *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

char **my_str_to_word_array(char *str);

#endif /* !LIB_H_ */
