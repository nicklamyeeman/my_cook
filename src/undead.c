/*
** EPITECH PROJECT, 2018
** undead
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

void	undead_text(cook_t *cook)
{
	cook->ud = sfTexture_createFromFile("./assets/undead.png", NULL);
	cook->undead = sfSprite_create();
	sfSprite_setTexture(cook->undead, cook->ud, sfTrue);
}

void	undead(cook_t *cook)
{
	if (cook->brace == 1)
		undead_text(cook);
	sfRenderWindow_drawSprite(cook->w, cook->undead, NULL);
}
