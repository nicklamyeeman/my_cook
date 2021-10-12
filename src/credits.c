/*
** EPITECH PROJECT, 2018
** cook
** File description:
** credits
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void    in_credits(cook_t *c)
{
	sfFloatRect	h18 = sfText_getGlobalBounds(c->f_tooptions);
	sfEvent		e = c->evt;

	sfText_setPosition(c->f_tomenu, v2f(0, 0));
	if (sfFloatRect_contains(&h18, e.mouseButton.x, e.mouseButton.y)) {
		c->check = 5;
		c->loob = 2;
	}
}

void	set_credits(cook_t *cook)
{
	sfText_setPosition(cook->f_tooptions, v2f(1530, 960));
}

void	font_credits(cook_t *cook)
{
	cook->cre = sfTexture_createFromFile("./assets/credits.png", NULL);
	cook->credits = sfSprite_create();
	sfSprite_setTexture(cook->credits, cook->cre, sfTrue);
	sfText_setFont(cook->f_tooptions, cook->police);
	sfText_setString(cook->f_tooptions, "Back to Options");
}
