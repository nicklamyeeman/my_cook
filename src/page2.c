/*
** EPITECH PROJECT, 2018
** cook
** File description:
** draw 2
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	pause_page(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->w, cook->gameplay, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->pause, NULL);
	sfRenderWindow_drawText(cook->w, cook->font19, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_tomenu, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_quit, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_minutes, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_hours, NULL);
}

void	quit_page(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->w, cook->home, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->pause, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_askquit, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_yes, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_no, NULL);
	if (cook->loob != 2 && cook->check != 6) {
		sfRenderWindow_drawText(cook->w, cook->f_minutes, NULL);
		sfRenderWindow_drawText(cook->w, cook->f_hours, NULL);
	}
}

void	credits_page(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->w, cook->home, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->credits, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_tooptions, NULL);
}

void	option_page2(cook_t *c, int *state)
{
	sfIntRect	area = int_rect(0, 0, 64, 64);

	sfRenderWindow_drawText(c->w, c->f_tomenu, NULL);
	sfRenderWindow_drawText(c->w, c->f_son, NULL);
	sfRenderWindow_drawText(c->w, c->f_volume, NULL);
	sfRenderWindow_drawText(c->w, c->f_minus, NULL);
	sfRenderWindow_drawText(c->w, c->f_plus, NULL);
	sfRenderWindow_drawText(c->w, c->f_credits, NULL);
	*state = c->sd - 1;
	area.left = 64 * *state;
	sfSprite_setTextureRect(c->volume_png, area);
	sfSprite_setScale(c->volume_png, v2f(4.7, 3));
	sfRenderWindow_drawSprite(c->w, c->volume_png, NULL);
}

void    option_page(cook_t *cook, int *state)
{
	sfRenderWindow_drawSprite(cook->w, cook->home, NULL);
	if (cook->son % 2 == 0)
		sfRenderWindow_drawSprite(cook->w, cook->uncheck, NULL);
	if (cook->son % 2 != 0)
		sfRenderWindow_drawSprite(cook->w, cook->check_png, NULL);
	if (cook->volume == 0)
		sfRenderWindow_drawSprite(cook->w, cook->uncheck, NULL);
	option_page2(cook, state);
}
