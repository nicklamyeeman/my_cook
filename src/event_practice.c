/*
** EPITECH PROJECT, 2018
** oui
** File description:
** oui
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	beer_event(cook_t *cook)
{
	sfEvent	e = cook->evt;

	if (e.type == sfEvtKeyPressed) {
		if (e.key.code == sfKeyDown)
			cook->compare += 1;
		if (cook->compare == 5) {
			cook->rbr.top = 120;
			sfSprite_setTextureRect(cook->beercommand, cook->rbr);
		}
	}
}

void	check_recipe(cook_t *cook)
{
	if (cook->end == 0) {
		if (cook->compare == cook->inrecipe) {
			cook->score = cook->score + cook->rewards;
			cook->wol = 1;
		}
		else
			cook->wol = 2;
	}
}

void	event_practice(cook_t *cook)
{
	sfEvent	e = cook->evt;

	if (cook->brecipe == 2) {
		if (e.type == sfEvtKeyPressed && e.key.code == sfKeyReturn) {
			check_recipe(cook);
			cook->end = 1;
			cook->brace = 0;
			cook->recipe = 0;
		}
		if (cook->recipe == 0)
			pyroco_event(cook);
		if (cook->recipe == 1)
			wings_event(cook);
		if (cook->recipe == 2)
			beer_event(cook);
		if (cook->recipe == 3)
			rolled_event(cook);
	}
}
