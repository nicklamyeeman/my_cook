/*
** EPITECH PROJECT, 2018
** cook
** File description:
** visual text pour les menus
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	reset(cook_t *cook)
{
	sfText_setColor(cook->f_practice, sfWhite);
	sfText_setColor(cook->f_tutorial, sfWhite);
	sfText_setColor(cook->f_invent, sfWhite);
	sfText_setColor(cook->f_options, sfWhite);
	sfText_setColor(cook->f_quit, sfWhite);
	sfText_setColor(cook->f_tomenu, sfWhite);
	sfText_setColor(cook->f_son, sfWhite);
	sfText_setScale(cook->f_practice, v2f(2, 2));
	sfText_setScale(cook->f_tutorial, v2f(2, 2));
	sfText_setScale(cook->f_invent, v2f(2, 2));
	sfText_setScale(cook->f_options, v2f(2, 2));
	sfText_setScale(cook->f_quit, v2f(2, 2));
	sfText_setScale(cook->f_tomenu, v2f(2, 2));
	sfText_setScale(cook->f_son, v2f(2, 2));
	reset2(cook);
}

void	visualstate_options(cook_t *c)
{
	sfFloatRect	h7 = sfText_getGlobalBounds(c->f_tomenu);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h7, e.mouseMove.x, e.mouseMove.y)) {
		sfText_setColor(c->f_tomenu, sfYellow);
		sfText_setScale(c->f_tomenu, v2f(2.2, 2.2));
	}
	visualstate_options2(c);
}

void	visualstate_practice(cook_t *c)
{
	sfFloatRect	h7 = sfText_getGlobalBounds(c->f_tomenu);

	if (sfFloatRect_contains(&h7, c->evt.mouseMove.x, c->evt.mouseMove.y)) {
		sfText_setColor(c->f_tomenu, sfYellow);
		sfText_setScale(c->f_tomenu, v2f(2.2, 2.2));
	}
}

void	visualstate_home2(cook_t *c)
{
	sfFloatRect	h4 = sfText_getGlobalBounds(c->f_options);
	sfFloatRect	h5 = sfText_getGlobalBounds(c->f_quit);

	if (sfFloatRect_contains(&h4, c->evt.mouseMove.x, c->evt.mouseMove.y)) {
		sfText_setColor(c->f_options, sfYellow);
		sfText_setScale(c->f_options, v2f(2.2, 2.2));
	}
	if (sfFloatRect_contains(&h5, c->evt.mouseMove.x, c->evt.mouseMove.y)) {
		sfText_setColor(c->f_quit, sfYellow);
		sfText_setScale(c->f_quit, v2f(2.2, 2.2));
	}
}

void	visualstate_home1(cook_t *c)
{
	sfFloatRect	h1 = sfText_getGlobalBounds(c->f_practice);
	sfFloatRect	h2 = sfText_getGlobalBounds(c->f_tutorial);
	sfFloatRect	h3 = sfText_getGlobalBounds(c->f_invent);

	if (sfFloatRect_contains(&h1, c->evt.mouseMove.x, c->evt.mouseMove.y)) {
		sfText_setColor(c->f_practice, sfYellow);
		sfText_setScale(c->f_practice, v2f(2.2, 2.2));
	}
	if (sfFloatRect_contains(&h2, c->evt.mouseMove.x, c->evt.mouseMove.y)) {
		sfText_setColor(c->f_tutorial, sfYellow);
		sfText_setScale(c->f_tutorial, v2f(2.2, 2.2));
	}
	if (sfFloatRect_contains(&h3, c->evt.mouseMove.x, c->evt.mouseMove.y)) {
		sfText_setColor(c->f_invent, sfYellow);
		sfText_setScale(c->f_invent, v2f(2.2, 2.2));
	}
	visualstate_home2(c);
}
