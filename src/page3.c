/*
** EPITECH PROJECT, 2018
** cook
** File description:
** page3
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	tuto_page(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->w, cook->howtoplay, NULL);
	if (cook->arrow_htp == 1 || cook->arrow_htp == 2) {
		sfRenderWindow_drawSprite(cook->w, cook->next_page_l, NULL);
		sfRenderWindow_drawSprite(cook->w, cook->next_page_r, NULL);
	}
	if (cook->arrow_htp == 3) {
		sfRenderWindow_drawSprite(cook->w, cook->next_page_l, NULL);
		sfRenderWindow_drawSprite(cook->w, cook->next_page_r, NULL);
	}
	if (cook->arrow_htp == 0)
		sfRenderWindow_drawSprite(cook->w, cook->next_page_l, NULL);
	if (cook->arrow_htp == 4)
		sfRenderWindow_drawSprite(cook->w, cook->next_page_r, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_tomenu, NULL);
}

void	quit_page_ingame(cook_t *cook)
{
	sfRenderWindow_drawSprite(cook->w, cook->gameplay, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->pause, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_askquit, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_yes, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_no, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_minutes, NULL);
	sfRenderWindow_drawText(cook->w, cook->f_hours, NULL);
}
