/*
** EPITECH PROJECT, 2018
** cook
** File description:
** check env for error
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_strcmp(char *str1, char *str2)
{
	int	i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
