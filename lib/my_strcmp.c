/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char *temp1, char *temp2)
{
    int i = 0;

    while (temp1[i]) {
        if (temp1[i] < temp2[i])
            return -1;
        if (temp1[i] > temp2[i])
            return 1;
        i++;
    }
    if (temp1[i] < temp2[i])
        return -1;
    if (temp1[i] > temp2[i])
        return 1;
    return 0;
}
