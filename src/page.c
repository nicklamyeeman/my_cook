/*
** EPITECH PROJECT, 2018
** cook
** File description:
** draw sprite pour chaques pages
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	main_page(cook_t *cook)
{
	if (cook->skip == 0)
		introduction(cook);
	else {
		sfRenderWindow_drawSprite(cook->w, cook->menu, NULL);
		pressenter(cook);
	}
}

void	practice_page(cook_t *cook)
{
	if (cook->wol == 0)
		sfClock_restart(cook->crew);
	if (cook->hours == 18 && cook->minutes == 0) {
		cook->rgp.top = 1080;
		sfSprite_setTextureRect(cook->gameplay, cook->rgp);
	}
	sfRenderWindow_drawSprite(cook->w, cook->gameplay, NULL);
	during_gameplay(cook);
	timer_in_game(cook);
	if (cook->wol == 1) {
		sfRenderWindow_drawSprite(cook->w, cook->yep, NULL);
	}
	else if (cook->wol == 2) {
		sfRenderWindow_drawSprite(cook->w, cook->nop, NULL);
	}
	if (sfTime_asMilliseconds(cook->trew) > 3000) {
		cook->wol = 0;
		sfClock_restart(cook->crew);
	}
}

void	inventory_page(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->w, cook->home, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->inventory, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->next_page, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_tomenu, NULL);
}

void	home_page(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->w, cook->home, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_practice, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_tutorial, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_invent, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_options, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_quit, NULL);
}
