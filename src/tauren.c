/*
** EPITECH PROJECT, 2018
** tauren
** File description:
** smae
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	tauren_text(cook_t *cook)
{
	cook->ta = sfTexture_createFromFile("./assets/tauren.png", NULL);
	cook->tauren = sfSprite_create();
	sfSprite_setTexture(cook->tauren, cook->ta, sfTrue);
}

void	tauren(cook_t *cook)
{
	if (cook->brace == 1)
		tauren_text(cook);
	sfRenderWindow_drawSprite(cook->w, cook->tauren, NULL);
}
