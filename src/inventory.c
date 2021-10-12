/*
** EPITECH PROJECT, 2018
** cook
** File description:
** inventory text
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	in_inventory2(cook_t *c)
{
	sfFloatRect	h_next = sfSprite_getGlobalBounds(c->next_page);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h_next, e.mouseButton.x, e.mouseButton.y)) {
		c->arrow++;
		sfSprite_setTextureRect(c->inventory, c->rinv);
		if (c->arrow % 2 == 0) {
			c->rinv.top = 0;
			sfSprite_setTextureRect(c->inventory, c->rinv);
			sfSprite_setScale(c->next_page, v2f(1, 1));
			sfSprite_setPosition(c->next_page, v2f(1700, 460));
		}
		else if (c->arrow % 2 != 0) {
			c->rinv.top = 1080;
			sfSprite_setTextureRect(c->inventory, c->rinv);
			sfSprite_setScale(c->next_page, v2f(-1, 1));
		}
	}
}

void    in_inventory(cook_t *c)
{
	sfFloatRect	h7 = sfText_getGlobalBounds(c->f_tomenu);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h7, e.mouseButton.x, e.mouseButton.y))
		c->loob = 1;
	in_inventory2(c);
}

void    set_inventory(cook_t *cook)
{
	sfText_setPosition(cook->f_tomenu, v2f(1530, 900));
	sfSprite_setPosition(cook->next_page, v2f(955, 460));
}

void    font_inventory(cook_t *cook)
{
	cook->arrow = 0;
	sfText_setFont(cook->f_tomenu, cook->police);
	sfText_setString(cook->f_tomenu, "Back to Menu");
	cook->inv = sfTexture_createFromFile("./assets/inventory.png", NULL);
	cook->inventory = sfSprite_create();
	sfSprite_setTexture(cook->inventory, cook->inv, sfTrue);
	cook->next_p = sfTexture_createFromFile("./assets/next_p.png", NULL);
	cook->next_page = sfSprite_create();
	sfSprite_setTexture(cook->next_page, cook->next_p, sfTrue);
	cook->rinv.left = 0;
	cook->rinv.top = 0;
	sfSprite_setTextureRect(cook->inventory, cook->rinv);
}
