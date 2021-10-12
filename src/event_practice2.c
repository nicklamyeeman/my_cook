/*
** EPITECH PROJECT, 2018
** oui
** File description:
** oui
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	pyroco_event2(cook_t *cook)
{
	sfEvent	e = cook->evt;

	if (e.key.code == sfKeyS && cook->evt_bool == 1) {
		cook->evt_bool = 2;
		if (cook->compare == 0)
			cook->compare = 1;
		else if (cook->compare == 3)
			cook->compare = 4;
		cook->rpyco.top = 470;
		sfSprite_setTextureRect(cook->pyrocommand, cook->rpyco);
	}
	else if (e.key.code == sfKeyC && cook->evt_bool == 1) {
		cook->evt_bool = 2;
		if (cook->compare == 0)
			cook->compare = 2;
		else if (cook->compare == 3)
			cook->compare = 5;
		cook->rpyco.top = 705;
		sfSprite_setTextureRect(cook->pyrocommand, cook->rpyco);
	}
}

void	pyroco_event(cook_t *cook)
{
	sfEvent	e = cook->evt;

	if (e.type == sfEvtKeyPressed) {
		if (e.key.code == sfKeyP && cook->compare == -1) {
			cook->evt_bool = 1;
			cook->compare = 0;
		}
		else if (e.key.code == sfKeyP && cook->compare == 0) {
			cook->evt_bool = 1;
			cook->compare = 3;
			cook->rpyco.top = 235;
			sfSprite_setTextureRect(cook->pyrocommand, cook->rpyco);
		}
		else
			pyroco_event2(cook);
	}
}

void	rolled_event2(cook_t *cook)
{
	sfEvent	e = cook->evt;

	if (e.key.code == sfKeyM && cook->evt_bool == 1) {
		cook->evt_bool = 2;
		if (cook->compare == 0) {
			cook->compare = 3;
		}
		else if (cook->compare == 1)
			cook->compare = 4;
		else
			cook->compare = 5;
		cook->rroll.top = 322;
		sfSprite_setTextureRect(cook->rollcommand, cook->rroll);
	}
}

void	rolled_event(cook_t *cook)
{
	sfEvent	e = cook->evt;

	if (e.type == sfEvtKeyPressed) {
		if (e.key.code == sfKeyR && cook->compare == -1) {
			cook->evt_bool = 1;
			cook->compare = 0;
		}
		else if (e.key.code == sfKeyR && cook->compare == 0) {
			cook->evt_bool = 1;
			cook->compare = 1;
		}
		else if (e.key.code == sfKeyR && cook->compare == 1) {
			cook->rroll.top = 161;
			sfSprite_setTextureRect(cook->rollcommand, cook->rroll);
			cook->compare = 2;
		}
		else
			rolled_event2(cook);
	}
}

void	wings_event(cook_t *cook)
{
	sfEvent	e = cook->evt;

	if (e.type == sfEvtKeyPressed && cook->evt_bool == 0) {
		if (e.key.code == sfKeyW && cook->compare < 5)
			cook->compare += 1;
		if (cook->compare == 5) {
			cook->evt_bool = 1;
			cook->rwg.top = 120;
			sfSprite_setTextureRect(cook->wingscommand, cook->rwg);
		}
	}
}
