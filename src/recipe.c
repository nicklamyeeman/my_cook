/*
** EPITECH PROJECT, 2018
** recipe
** File description:
** same
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	recipe_choice(cook_t *cook)
{
	if (cook->recipe == 0)
		pyrocotelette(cook);
	if (cook->recipe == 1)
		wings(cook);
	if (cook->recipe == 2)
		beer(cook);
	if (cook->recipe == 3)
		rolled(cook);
}

void	which_recipe(cook_t *cook)
{
	if (cook->brecipe == 0) {
		cook->recipe = rand() % 4;
		cook->brecipe = 1;
	}
	else if (cook->brecipe == 1) {
		recipe_choice(cook);
		cook->brecipe = 2;
	}
	else
		recipe_choice(cook);
}

void	races_choice(cook_t *cook)
{
	if (cook->race == 0)
		humans(cook);
	if (cook->race == 1)
		orcs(cook);
	if (cook->race == 2)
		dwarfs(cook);
	if (cook->race == 3)
		undead(cook);
	if (cook->race == 4)
		night_elf(cook);
	if (cook->race == 5)
		tauren(cook);
}

void	which_race(cook_t *cook)
{
	if (cook->brace == 0) {
		cook->race = rand() % 6;
		cook->brace = 1;
	}
	else if (cook->brace == 1) {
		races_choice(cook);
		cook->brace = 2;
	}
	else
		races_choice(cook);
}

void	traitment(cook_t *cook)
{
	if (cook->end == 0) {
		which_race(cook);
		which_recipe(cook);
	}
}
