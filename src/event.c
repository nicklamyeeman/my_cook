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

void	event_mainpage(cook_t *cook)
{
	if (cook->evt.type == sfEvtKeyPressed)
		if (cook->evt.key.code == sfKeySpace)
			cook->skip = 1;
	if (cook->evt.key.code == sfKeyReturn && cook->loob <= 1)
		cook->loob = 1;
}

void	my_press_inmenu(cook_t *c)
{
	if (c->loob == 1)
		after_home(c);
	if (c->loob == 3 && c->check == 1)
		in_credits(c);
	if (c->loob == 3 && c->check == 2)
		in_pause(c);
	if (c->loob == 2 && c->check == 1)
		in_practice(c);
	if (c->loob == 2 && c->check == 2)
		in_tuto(c);
	if (c->loob == 2 && c->check == 4)
		in_inventory(c);
	if (c->loob == 2 && c->check == 5)
		in_option(c);
	if ((c->loob == 2 && c->check == 6) || (c->loob == 3 && c->check == 3))
		in_quit(c);
	if (c->loob == 3 && c->check == 4)
		in_quit_ingame(c);
}

void	cook_event3(cook_t *c)
{
	sfEvent	e = c->evt;

	if (e.type == sfEvtMouseMoved)
		sfSprite_setPosition(c->crs, v2f(e.mouseMove.x, e.mouseMove.y));
	if (c->evt.type == sfEvtKeyPressed && c->loob == 2 && c->check == 1) {
		if (c->evt.key.code == sfKeyEscape) {
			c->loob = 3;
			c->check = 2;
		}
	}
}

void	cook_event2(cook_t *cook)
{
	if (cook->evt.type == sfEvtClosed)
		sfRenderWindow_close(cook->w);
	event_mainpage(cook);
	if (cook->evt.type == sfEvtMouseButtonPressed)
		if (cook->evt.mouseButton.button == sfMouseLeft)
			my_press_inmenu(cook);
	if (cook->evt.type == sfEvtMouseMoved)
		check_forvisual(cook);
	if (cook->evt.type == sfEvtKeyPressed && cook->loob == 1) {
		if (cook->evt.key.code == sfKeyEscape) {
			cook->loob = 2;
			cook->check = 6;
		}
	}
	cook_event3(cook);
}

void	cook_event(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->w, cook->crs, NULL);
	while (sfRenderWindow_pollEvent(cook->w, &cook->evt)) {
		reset(cook);
		cook_event2(cook);
		event_practice(cook);
	}
}
