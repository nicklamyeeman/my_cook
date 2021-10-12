/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	introduction(cook_t *cook)
{
	cook->tpe = sfClock_getElapsedTime(cook->cpe);
	if (sfTime_asSeconds(cook->tpe) > 1)
		sfRenderWindow_drawSprite(cook->w, cook->intro1, NULL);
	if (sfTime_asSeconds(cook->tpe) > 6)
		sfRenderWindow_drawSprite(cook->w, cook->intro2, NULL);
	if (sfTime_asSeconds(cook->tpe) > 11) {
		cook->skip = 1;
		return;
	}
}

void	pressenter(cook_t *cook)
{
	cook->tpe = sfClock_getElapsedTime(cook->cpe);
	if (sfTime_asSeconds(cook->tpe) > 0.3) {
		if (cook->rpe.top == 90 * 3)
			cook->rpe.top = 0;
		else
			cook->rpe.top -= 90;
		sfSprite_setTextureRect(cook->pressenter, cook->rpe);
		sfClock_restart(cook->cpe);
	}
	sfRenderWindow_drawSprite(cook->w, cook->pressenter, NULL);
}
