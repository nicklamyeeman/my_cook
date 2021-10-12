/*
** EPITECH PROJECT, 2018
** cook
** File description:
** création text dans option etc
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	in_option3(cook_t *c)
{
	sfFloatRect	h11 = sfText_getGlobalBounds(c->f_minus);
	sfFloatRect	h17 = sfText_getGlobalBounds(c->f_credits);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h11, e.mouseButton.x, e.mouseButton.y)) {
		if (c->volume > 0) {
			c->volume -= 10;
			c->sd--;
			sfMusic_setVolume(c->music, c->volume);
		}
	}
	if (sfFloatRect_contains(&h17, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 3;
		c->check = 1;
	}
}

void	in_option2(cook_t *c)
{
	sfFloatRect	h13 = sfText_getGlobalBounds(c->f_plus);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h13, e.mouseButton.x, e.mouseButton.y)) {
		if (c->volume < 100) {
			c->volume += 10;
			c->sd++;
			sfMusic_setVolume(c->music, c->volume);
		}
	}
	in_option3(c);
	sfText_setPosition(c->f_credits, v2f(400, 450));
	sfText_setPosition(c->f_tomenu, v2f(1530, 900));
}

void    in_option(cook_t *c)
{
	sfFloatRect	h7 = sfText_getGlobalBounds(c->f_tomenu);
	sfFloatRect	chek_png = sfSprite_getGlobalBounds(c->check_png);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h7, e.mouseButton.x, e.mouseButton.y))
		c->loob = 1;
	if (sfFloatRect_contains(&chek_png, e.mouseButton.x, e.mouseButton.y)) {
		c->son ++;
		if (c->son % 2 == 0)
			sfMusic_pause(c->music);
		else
			sfMusic_play(c->music);
	}
	in_option2(c);
}

void	set_option(cook_t *cook)
{
	sfText_setPosition(cook->f_son, v2f(400, 250));
	sfText_setPosition(cook->f_volume, v2f(400, 350));
	sfSprite_setPosition(cook->check_png, v2f(520, 240));
	sfSprite_setPosition(cook->volume_png, v2f(550, 300));
	sfSprite_setPosition(cook->uncheck, v2f(520, 240));
	sfText_setPosition(cook->f_minus, v2f(555, 325));
	sfText_setPosition(cook->f_plus, v2f(814, 332));
	sfSprite_setScale(cook->check_png, v2f(0.5, 0.5));
	sfSprite_setScale(cook->uncheck, v2f(0.5, 0.5));
}

void	font_option(cook_t *cook)
{
	sfText_setFont(cook->f_tomenu, cook->police);
	sfText_setFont(cook->f_son, cook->police);
	sfText_setFont(cook->f_volume, cook->police);
	sfText_setFont(cook->f_minus, cook->police);
	sfText_setFont(cook->f_plus, cook->police);
	sfText_setFont(cook->f_credits, cook->police);
	sfText_setString(cook->f_tomenu, "Back to Menu");
	sfText_setString(cook->f_son, "Son :");
	sfText_setString(cook->f_volume, "Volume : ");
	sfText_setString(cook->f_minus, "-");
	sfText_setString(cook->f_plus, "+");
	sfText_setString(cook->f_credits, "Credits");
}
