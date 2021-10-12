/*
** EPITECH PROJECT, 2018
** cook
** File description:
** second visual text
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void    reset2(cook_t *cook)
{
	sfText_setColor(cook->f_volume, sfWhite);
	sfText_setColor(cook->f_minus, sfWhite);
	sfText_setColor(cook->f_plus, sfWhite);
	sfText_setColor(cook->f_yes, sfWhite);
	sfText_setColor(cook->f_no, sfWhite);
	sfText_setColor(cook->f_credits, sfWhite);
	sfText_setColor(cook->f_tooptions, sfWhite);
	sfText_setColor(cook->font19, sfWhite);
	sfText_setScale(cook->f_volume, v2f(2, 2));
	sfText_setScale(cook->f_minus, v2f(3, 3));
	sfText_setScale(cook->f_plus, v2f(3, 3));
	sfText_setScale(cook->f_askquit, v2f(2, 2));
	sfText_setScale(cook->f_yes, v2f(2, 2));
	sfText_setScale(cook->f_no, v2f(2, 2));
	sfText_setScale(cook->f_credits, v2f(2, 2));
	sfText_setScale(cook->f_tooptions, v2f(2, 2));
	sfText_setScale(cook->font19, v2f(2, 2));
}

void	visualstate_quit(cook_t *c)
{
	sfFloatRect	h15 = sfText_getGlobalBounds(c->f_yes);
	sfFloatRect	h16 = sfText_getGlobalBounds(c->f_no);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h15, e.mouseMove.x, e.mouseMove.y)) {
		sfText_setColor(c->f_yes, sfYellow);
		sfText_setScale(c->f_yes, v2f(2.2, 2.2));
	}
	if (sfFloatRect_contains(&h16, e.mouseMove.x, e.mouseMove.y)) {
		sfText_setColor(c->f_no, sfYellow);
		sfText_setScale(c->f_no, v2f(2.2, 2.2));
	}
}

void	visualstate_pause(cook_t *c)
{
	sfFloatRect	h19 = sfText_getGlobalBounds(c->font19);
	sfFloatRect	h6 = sfText_getGlobalBounds(c->f_quit);
	sfFloatRect	h7 = sfText_getGlobalBounds(c->f_tomenu);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h19, e.mouseMove.x, e.mouseMove.y)) {
		sfText_setColor(c->font19, sfYellow);
		sfText_setScale(c->font19, v2f(2.2, 2.2));
	}
	if (sfFloatRect_contains(&h6, e.mouseMove.x, e.mouseMove.y)) {
		sfText_setColor(c->f_quit, sfYellow);
		sfText_setScale(c->f_quit, v2f(2.2, 2.2));
	}
	if (sfFloatRect_contains(&h7, e.mouseMove.x, e.mouseMove.y)) {
		sfText_setColor(c->f_tomenu, sfYellow);
		sfText_setScale(c->f_tomenu, v2f(2.2, 2.2));
	}
}

void	visualstate_options2(cook_t *c)
{
	sfFloatRect	h17 = sfText_getGlobalBounds(c->f_credits);
	sfFloatRect	h18 = sfText_getGlobalBounds(c->f_tooptions);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h17, e.mouseMove.x, e.mouseMove.y)) {
		sfText_setColor(c->f_credits, sfYellow);
		sfText_setScale(c->f_credits, v2f(2.2, 2.2));
	}
	if (sfFloatRect_contains(&h18, e.mouseMove.x, e.mouseMove.y)) {
		sfText_setColor(c->f_tooptions, sfYellow);
		sfText_setScale(c->f_tooptions, v2f(2.2, 2.2));
	}
}

void	check_forvisual(cook_t *c)
{
	if (c->loob == 1)
		visualstate_home1(c);
	if (c->loob == 3 && c->check == 2)
		visualstate_pause(c);
	if (c->loob == 2 && c->check == 1)
		visualstate_practice(c);
	if (c->loob == 2 && c->check == 4 || c->check == 2)
		visualstate_pause(c);
	if ((c->loob == 3) || (c->loob == 2 && c->check == 5))
		visualstate_options(c);
	if ((c->loob == 2 && c->check == 6) || (c->loob == 3 && c->check == 3))
		visualstate_quit(c);
	if (c->loob == 3 && c->check == 4)
		visualstate_quit(c);
}
