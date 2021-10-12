/*
** EPITECH PROJECT, 2018
** cook
** File description:
** second initialisation
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	create_clock(cook_t *cook)
{
	cook->cpe = sfClock_create();
	cook->tpe = sfClock_getElapsedTime(cook->cpe);
	cook->cgp = sfClock_create();
	cook->cfi = sfClock_create();
	cook->tfi = sfClock_getElapsedTime(cook->cfi);
	cook->ctime = sfClock_create();
	cook->crew = sfClock_create();
}

void    create_font(cook_t *c)
{
	font_home(c);
	font_practice(c);
	font_tutorial(c);
	font_inventory(c);
	font_option(c);
	font_credits(c);
	font_quit(c);
	font_pause(c);
}

void    create_fontnmusic2(cook_t *cook)
{
	cook->f_credits = sfText_create();
	cook->f_tooptions = sfText_create();
	cook->f_hours = sfText_create();
	cook->f_minutes = sfText_create();
	cook->font19 = sfText_create();
	cook->f_score = sfText_create();
	sfText_setFont(cook->f_hours, cook->police);
	sfText_setFont(cook->f_minutes, cook->police);
	sfText_setFont(cook->f_score, cook->police);
	cook->wol = 0;
}

void    create_fontnmusic(cook_t *cook)
{
	cook->police = sfFont_createFromFile("./assets/Cookies.ttf");
	cook->f_practice = sfText_create();
	cook->f_tutorial = sfText_create();
	cook->f_invent = sfText_create();
	cook->f_options = sfText_create();
	cook->f_quit = sfText_create();
	cook->f_tomenu = sfText_create();
	cook->f_son = sfText_create();
	cook->f_volume = sfText_create();
	cook->f_minus = sfText_create();
	cook->f_plus = sfText_create();
	cook->f_askquit = sfText_create();
	cook->f_yes = sfText_create();
	cook->f_no = sfText_create();
	cook->music = sfMusic_createFromFile("./assets/Hearthstone.ogg");
	create_fontnmusic2(cook);
}

sfIntRect	int_rect(int left, int top, int width, int height)
{
	sfIntRect	rect;

	rect.left = left;
	rect.top = top;
	rect.width = width;
	rect.height = height;
	return (rect);
}
