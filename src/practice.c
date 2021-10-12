/*
** EPITECH PROJECT, 2018
** cook
** File description:
** création text dans career etc
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	during_gameplay(cook_t *cook)
{
	cook->tfi = sfClock_getElapsedTime(cook->cfi);
	if (sfTime_asSeconds(cook->tfi) > 0.2) {
		if (cook->rfi.left > (288 * 2))
			cook->rfi.left = 0;
		else
			cook->rfi.left += 288;
		sfSprite_setTextureRect(cook->fire, cook->rfi);
		sfClock_restart(cook->cfi);
	}
	sfRenderWindow_drawSprite(cook->w, cook->fire, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_score, NULL);
}

void    in_practice(cook_t *c)
{
	sfFloatRect     h7 = sfText_getGlobalBounds(c->f_tomenu);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h7, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 1;
		c->check = 0;
	}
}

void    set_practice(cook_t *cook)
{
	sfText_setPosition(cook->f_tomenu, v2f(1530, 900));
	sfText_setScale(cook->f_hours, v2f(2, 2));
	sfText_setScale(cook->f_minutes, v2f(2, 2));
	sfText_setPosition(cook->f_hours, v2f(1152, 122));
	sfText_setPosition(cook->f_minutes, v2f(1189, 123));
	sfText_setPosition(cook->f_score, v2f(1740, 17));
	sfText_setScale(cook->f_score, v2f(2, 2));
}

void    font_practice(cook_t *cook)
{
	sfText_setFont(cook->f_tomenu, cook->police);
	sfText_setString(cook->f_tomenu, "Back to Menu");
}
