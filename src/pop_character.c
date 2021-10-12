/*
** EPITECH PROJECT, 2018
** cook
** File description:
** character
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	make_rand(int *recup, int *ret, int *time_for_cook, cook_t *cook)
{
	*recup = rand() % *ret;
	*ret += -1;
	*time_for_cook = cook->minutes;
	cook->brace = 0;
	cook->brecipe = 0;
}

void	change_bool(int *pop_char1, int *pop_char2, cook_t *cook)
{
	*pop_char1 = 1;
	*pop_char2 = 1;
	cook->end = 0;
}

void	draw_char(int *char1, int *char2, int *for_cook, cook_t *cook)
{
	if (cook->end != 0)
		*char2 = 0;
	if (*char1 == 1 && *char2 == 1)
		traitment(cook);
	if (cook->minutes == *for_cook + 15)
		*char2 = 0;
}

int	reset_values(cook_t *cook, int *ret, int *time_for_cook, int *recup)
{
	cook->brace = 0;
	cook->brecipe = 0;
	cook->evt_bool = 0;
	*ret = 15;
	*recup = 0;
	*time_for_cook = 0;
	cook->end = 1;
	if (cook->check_for_pause >= 1)
		cook->check_for_pause = 0;
	return (0);
}

void	pop_character(cook_t *cook)
{
	static  int pop_char1 = 0;
	static  int pop_char2 = 0;
	static  int ret = 15;
	static  int time_for_cook = 0;
	int     recup = 0;

	if (cook->check_for_pause >= 1) {
		pop_char1 = reset_values(cook, &ret, &time_for_cook, &recup);
		pop_char2 = 0;
	}
	if (sfTime_asMilliseconds(cook->ttime) > 450) {
		cook->minutes += 1;
		if (pop_char1 == 0 && pop_char2 == 0)
			make_rand(&recup, &ret, &time_for_cook, cook);
		if (recup == ret)
			change_bool(&pop_char1, &pop_char2, cook);
		sfClock_restart(cook->ctime);
	}
	draw_char(&pop_char1, &pop_char2, &time_for_cook, cook);
	if (cook->minutes == 0 || cook->minutes == 30)
		pop_char1 = reset_values(cook, &ret, &time_for_cook, &recup);
}
