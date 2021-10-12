/*
** EPITECH PROJECT, 2018
** cook
** File description:
** text for quit
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	in_quit_ingame(cook_t *c)
{
	sfFloatRect	h15 = sfText_getGlobalBounds(c->f_yes);
	sfFloatRect	h16 = sfText_getGlobalBounds(c->f_no);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h16, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 3;
		c->check = 2;
	}
	if (sfFloatRect_contains(&h15, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 1;
		c->check = 0;
	}
}

void	in_quit(cook_t *c)
{
	sfFloatRect	h5 = sfText_getGlobalBounds(c->f_yes);
	sfFloatRect	h6 = sfText_getGlobalBounds(c->f_no);
	sfEvent		e = c->evt;

	if (c->loob == 2 && c->check == 6) {
		if (sfFloatRect_contains(&h6, e.mouseButton.x, e.mouseButton.y))
			c->loob = 1;
		if (sfFloatRect_contains(&h5, e.mouseButton.x, e.mouseButton.y))
			sfRenderWindow_close(c->w);
	}
	if (c->loob == 3 && c->check == 3) {
		if (sfFloatRect_contains(&h6, e.mouseButton.x, e.mouseButton.y))
			c->loob = 3;
		if (sfFloatRect_contains(&h6, e.mouseButton.x, e.mouseButton.y))
			c->check = 2;
		if (sfFloatRect_contains(&h5, e.mouseButton.x, e.mouseButton.y))
			sfRenderWindow_close(c->w);
	}
}

void	set_quit(cook_t *cook)
{
	sfText_setPosition(cook->f_askquit, v2f(700, 360));
	sfText_setPosition(cook->f_yes, v2f(800, 500));
	sfText_setPosition(cook->f_no, v2f(1000, 500));
}

void	font_quit(cook_t *cook)
{
	sfText_setFont(cook->f_askquit, cook->police);
	sfText_setFont(cook->f_yes, cook->police);
	sfText_setFont(cook->f_no, cook->police);
	sfText_setString(cook->f_askquit, "Are you sure you want to quit ?");
	sfText_setString(cook->f_yes, "Yes");
	sfText_setString(cook->f_no, "No");
	set_quit(cook);
}
