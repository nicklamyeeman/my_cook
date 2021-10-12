/*
** EPITECH PROJECT, 2018
** cook
** File description:
** pause
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	in_pause(cook_t *c)
{
	sfFloatRect     h19 = sfText_getGlobalBounds(c->font19);
	sfFloatRect     h6 = sfText_getGlobalBounds(c->f_quit);
	sfFloatRect     h7 = sfText_getGlobalBounds(c->f_tomenu);
	sfEvent         e = c->evt;

	if (sfFloatRect_contains(&h19, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 2;
		c->check = 1;
	}
	if (sfFloatRect_contains(&h6, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 3;
		c->check = 3;
	}
	if (sfFloatRect_contains(&h7, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 3;
		c->check = 4;
		c->check_for_pause = 1;
	}
}

void	set_pause(cook_t *c)
{
	sfText_setPosition(c->font19, v2f(890, 350));
	sfText_setPosition(c->f_tomenu, v2f(850, 450));
	sfText_setPosition(c->f_quit, v2f(910, 550));
}

void	font_pause(cook_t *c)
{
	sfText_setString(c->font19, "Resume");
	sfText_setFont(c->font19, c->police);
	sfText_setFont(c->f_tomenu, c->police);
	sfText_setString(c->f_tomenu, "Back to Menu");
	sfText_setFont(c->f_quit, c->police);
	sfText_setString(c->f_quit, "Quit");
}
