/*
** EPITECH PROJECT, 2018
** hunter
** File description:
** score
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	timer_in_game(cook_t *cook)
{
	cook->ttime = sfClock_getElapsedTime(cook->ctime);
	cook->trew = sfClock_getElapsedTime(cook->crew);
	sfRenderWindow_drawText(cook->w, cook->f_minutes, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_hours, NULL);
	sfText_setString(cook->f_minutes, int_to_char(cook->minutes));
	sfText_setString(cook->f_hours, int_to_char(cook->hours));
	if (cook->minutes >= 60) {
		cook->hours += 1;
		cook->minutes = 0;
	}
	pop_character(cook);
	end_game(cook);
}

int	my_strlen(char const *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	check_first(int *n, int *j, int *i, int *s)
{
	if (*n < 0) {
		*n = *n * -1;
		*j = 1;
	}
	*i = *n;
	while (*i) {
		*i /= 10;
		*s += 1;
	}
}

char    *int_to_char(int n)
{
	char    *str = NULL;
	int     s = 0;
	int     i = 0;
	int     j = 0;

	check_first(&n, &j, &i, &s);
	str = malloc(sizeof(char) * s + j + 1);
	if (str == NULL)
		return (NULL);
	for (i = s + j - 1; i >= j; i--, n /= 10)
		str[i] = n % 10 + '0';
	if (j)
		str[0] = '-';
	str[s + j] = '\0';
	return (str);
}
