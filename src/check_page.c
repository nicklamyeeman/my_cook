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

void	second_page(cook_t *cook)
{
	if (cook->loob == 3 && cook->check == 1)
		build_credits(cook);
	if (cook->loob == 3 && cook->check == 2)
		build_pause(cook);
	if (cook->loob == 3 && cook->check == 3)
		quit_page_ingame(cook);
	if (cook->loob == 3 && cook->check == 4)
		quit_page_ingame(cook);
	if (cook->loob != 2 && cook->loob != 3) {
		cook->minutes = 0;
		cook->hours = 9;
		cook->score = 0;
	}
	sfRenderWindow_drawSprite(cook->w, cook->crs, NULL);
}

void	page(cook_t *cook, int *state)
{
	sfRenderWindow_setMouseCursorVisible(cook->w, 0);
	if (cook->loob == 1)
		build_home(cook);
	if (cook->loob == 2 && cook->check == 1)
		build_practice(cook);
	if (cook->loob == 2 && cook->check == 2)
		build_howtoplay(cook);
	if (cook->loob == 2 && cook->check == 4)
		build_inventory(cook);
	if (cook->loob == 2 && cook->check == 5)
		build_option(cook, state);
	if (cook->loob == 2 && cook->check == 6)
		build_quit(cook);
	second_page(cook);
}
