/*
** EPITECH PROJECT, 2018
** cook
** File description:
** tutorial
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	in_tuto3(cook_t *c)
{
	sfFloatRect	h7 = sfText_getGlobalBounds(c->f_tomenu);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&h7, e.mouseButton.x, e.mouseButton.y)) {
		c->loob = 1;
		c->check = 0;
	}
}

void	in_tuto2(cook_t *c)
{
	sfFloatRect	hnl = sfSprite_getGlobalBounds(c->next_page_r);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&hnl, e.mouseButton.x, e.mouseButton.y)) {
		if (c->arrow_htp > 0 && c->arrow_htp <= 4)
			c->arrow_htp--;
		if (c->arrow_htp == 0)
			c->rhtp.top = 0;
		if (c->arrow_htp == 1)
			c->rhtp.top = 1080;
		if (c->arrow_htp == 2)
			c->rhtp.top = 2160;
		if (c->arrow_htp == 3)
			c->rhtp.top = 3240;
		sfSprite_setTextureRect(c->howtoplay, c->rhtp);
	}
	in_tuto3(c);
}

void	in_tuto(cook_t *c)
{
	sfFloatRect	hnr = sfSprite_getGlobalBounds(c->next_page_l);
	sfEvent		e = c->evt;

	if (sfFloatRect_contains(&hnr, e.mouseButton.x, e.mouseButton.y)) {
		if (c->arrow_htp >= 0 && c->arrow_htp < 4)
			c->arrow_htp++;
		if (c->arrow_htp == 1)
			c->rhtp.top = 1080;
		if (c->arrow_htp == 2)
			c->rhtp.top = 2160;
		if (c->arrow_htp == 3)
			c->rhtp.top = 3240;
		if (c->arrow_htp == 4)
			c->rhtp.top = 4320;
		sfSprite_setTextureRect(c->howtoplay, c->rhtp);
	}
	in_tuto2(c);
}

void	set_tutorial(cook_t *cook)
{
	sfSprite_setPosition(cook->next_page_r, v2f(840, 460));
	sfSprite_setScale(cook->next_page_r, v2f(-1, 1));
	sfText_setPosition(cook->f_tomenu, v2f(1680, 980));
	sfSprite_setPosition(cook->next_page_l, v2f(1055, 460));
}

void	font_tutorial(cook_t *cook)
{
	cook->arrow_htp = 0;
	sfText_setFont(cook->f_tomenu, cook->police);
	sfText_setString(cook->f_tomenu, "Back to Menu");
	cook->htp = sfTexture_createFromFile("./assets/tutorial.png", NULL);
	cook->howtoplay = sfSprite_create();
	sfSprite_setTexture(cook->howtoplay, cook->htp, sfTrue);
	cook->next_p_r = sfTexture_createFromFile("./assets/next_p.png", NULL);
	cook->next_page_r = sfSprite_create();
	sfSprite_setTexture(cook->next_page_r, cook->next_p_r, sfTrue);
	cook->next_p_l = sfTexture_createFromFile("./assets/next_p.png", NULL);
	cook->next_page_l = sfSprite_create();
	sfSprite_setTexture(cook->next_page_l, cook->next_p_l, sfTrue);
	cook->rhtp.top = 0;
	cook->rhtp.left = 0;
}
