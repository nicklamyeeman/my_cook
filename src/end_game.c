/*
** EPITECH PROJECT, 2018
** cook
** File description:
** end
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	end_game(cook_t *cook)
{
	sfClock         *cend = sfClock_create();
	sfTime          tend = sfClock_restart(cend);

	sfText_setPosition(cook->f_score, v2f(937, 780));
	sfText_setScale(cook->f_score, v2f(5, 5));
	if (cook->hours == 23 && cook->minutes == 1) {
		sfRenderWindow_drawSprite(cook->w, cook->endofday, NULL);
		sfRenderWindow_drawText(cook->w, cook->f_score, NULL);
		sfRenderWindow_display(cook->w);
		while (sfTime_asSeconds(tend) <= 5)
			tend = sfClock_getElapsedTime(cend);
		cook->loob = 1;
		cook->check = 0;
	}
}
