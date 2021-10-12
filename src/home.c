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

void	after_home2(cook_t *c)
{
	sfFloatRect	h6 = sfText_getGlobalBounds(c->f_quit);
	sfFloatRect	h2 = sfText_getGlobalBounds(c->f_tutorial);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h6, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 2;
		c->check = 6;
	}
	if (sfFloatRect_contains(&h2, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 2;
		c->check = 2;
	}
}

void	after_home(cook_t *c)
{
	sfFloatRect	h1 = sfText_getGlobalBounds(c->f_practice);
	sfFloatRect	h4 = sfText_getGlobalBounds(c->f_invent);
	sfFloatRect	h5 = sfText_getGlobalBounds(c->f_options);
	sfEvent		e = c->evt;

	sfText_setPosition(c->f_credits, v2f(0, 0));
	if (sfFloatRect_contains(&h1, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 2;
		c->check = 1;
	}
	if (sfFloatRect_contains(&h4, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 2;
		c->check = 4;
	}
	if (sfFloatRect_contains(&h5, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 2;
		c->check = 5;
	}
	after_home2(c);
}

void	set_home(cook_t *cook)
{
	sfText_setPosition(cook->f_practice, v2f(400, 250));
	sfText_setPosition(cook->f_tutorial, v2f(400, 350));
	sfText_setPosition(cook->f_invent, v2f(400, 450));
	sfText_setPosition(cook->f_options, v2f(400, 550));
	sfText_setPosition(cook->f_quit, v2f(400, 650));
}

void	font_home(cook_t *cook)
{
	sfText_setFont(cook->f_practice, cook->police);
	sfText_setFont(cook->f_tutorial, cook->police);
	sfText_setFont(cook->f_invent, cook->police);
	sfText_setFont(cook->f_options, cook->police);
	sfText_setFont(cook->f_quit, cook->police);
	sfText_setString(cook->f_practice, "Practice");
	sfText_setString(cook->f_tutorial, "How to Play ?");
	sfText_setString(cook->f_invent, "Inventory");
	sfText_setString(cook->f_options, "Options");
	sfText_setString(cook->f_quit, "Quit");
}
