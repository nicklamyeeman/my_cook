/*
** EPITECH PROJECT, 2018
** cook
** File description:
** check env for error
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*get_name(char *str)
{
	int     i = 0;
	char	*ret;

	while (str[i] != '=')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '=') {
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_all(char *str)
{
	int	i = 0;
	char	*ret;

	while (str[i] != '\0')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0') {
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*cut_check(char *dis, char *stock)
{
	if (my_strlen(stock) != my_strlen(dis))
		return (NULL);
	else {
		if (my_strcmp(stock, dis) == 0)
			return (stock);
		else
			return (NULL);
	}
}

char	*check_stock(char *stock, char *dis)
{
	if (cut_check(dis, stock) == NULL)
		return (NULL);
	else
		return (stock);
}

char	*check_env(char **env)
{
	int	i = 0;
	char	*stock;
	char	*dis = "DISPLAY=:0.0";

	while (env[i] != NULL) {
		stock = get_name(env[i]);
		if (my_strcmp(stock, "DISPLAY") == 0) {
			free(stock);
			stock = get_all(env[i]);
			return (check_stock(stock, dis));
		}
		else
			i++;
	}
	return (NULL);
}
