/*
** EPITECH PROJECT, 2018
** orcs
** File description:
** orcs
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	orc_text(cook_t *cook)
{
	cook->or = sfTexture_createFromFile("./assets/orc.png", NULL);
	cook->orc = sfSprite_create();
	sfSprite_setTexture(cook->orc, cook->or, sfTrue);
}

void	orcs(cook_t *cook)
{
	if (cook->brace == 1)
		orc_text(cook);
	sfRenderWindow_drawSprite(cook->w, cook->orc, NULL);
}
