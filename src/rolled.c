/*
** EPITECH PROJECT, 2018
** cook
** File description:
** rolled
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	draw_rolled2(cook_t *cook)
{
	if (cook->compare == 3) {
		cook->rewards = 7;
		cook->rrd.top = 0;
		cook->rrd.left = 856;
	}
	if (cook->compare == 4) {
		cook->rewards = 13;
		cook->rrd.top = 346;
		cook->rrd.left = 856;
	}
	if (cook->compare == 5) {
		cook->rewards = 20;
		cook->rrd.top = 694;
		cook->rrd.left = 856;
	}
	sfSprite_setTextureRect(cook->rolleddraw, cook->rrd);
	sfSprite_setPosition(cook->rolleddraw, v2f(530, 630));
	sfRenderWindow_drawSprite(cook->w, cook->rolleddraw, NULL);
}

void	draw_rolled(cook_t *cook)
{
	if (cook->compare != -1) {
		if (cook->compare == 0) {
			cook->rewards = 6;
			cook->rrd.top = 0;
			cook->rrd.left = 0;
		}
		if (cook->compare == 1) {
			cook->rewards = 11;
			cook->rrd.top = 346;
			cook->rrd.left = 0;
		}
		if (cook->compare == 2) {
			cook->rewards = 17;
			cook->rrd.top = 693;
			cook->rrd.left = 0;
		}
		draw_rolled2(cook);
	}
}

void	random_recipe_rolled(cook_t *cook)
{
	cook->qr = sfTexture_createFromFile("./assets/questrolled.png", NULL);
	cook->questrolled = sfSprite_create();
	sfSprite_setTexture(cook->questrolled, cook->qr, sfTrue);
	cook->rqr.top = 0;
	cook->rqr.left = 0;
	if (cook->inrecipe == 1)
		cook->rqr.left = 640;
	else if (cook->inrecipe == 2)
		cook->rqr.left = 1280;
	else if (cook->inrecipe >= 3) {
		cook->rqr.top = 1080;
		if (cook->inrecipe == 4)
			cook->rqr.left = 640;
		else if (cook->inrecipe == 5)
			cook->rqr.left = 1280;
	}
	sfSprite_setTextureRect(cook->questrolled, cook->rqr);
}

void    rolled_text(cook_t *cook)
{
	cook->cl = sfTexture_createFromFile("./assets/client.png", NULL);
	cook->client = sfSprite_create();
	cook->roll = sfTexture_createFromFile("./assets/rollcommand.png", NULL);
	cook->rollcommand = sfSprite_create();
	cook->rd = sfTexture_createFromFile("./assets/rolled.png", NULL);
	cook->rolleddraw = sfSprite_create();
	sfSprite_setTexture(cook->rolleddraw, cook->rd, sfTrue);
	sfSprite_setTextureRect(cook->rolleddraw, cook->rrd);
	sfSprite_setTexture(cook->client, cook->cl, sfTrue);
	sfSprite_setTexture(cook->rollcommand, cook->roll, sfTrue);
	cook->rroll.left = 0;
	cook->rroll.top = 0;
	sfSprite_setTextureRect(cook->rollcommand, cook->rroll);
	sfSprite_setPosition(cook->rollcommand, v2f(1140, 485));
	random_recipe_rolled(cook);
	cook->rcl.top = 0;
	cook->rcl.left = 0;
	sfSprite_setTextureRect(cook->client, cook->rcl);
}

void	rolled(cook_t *cook)
{
	if (cook->brecipe == 1) {
		cook->inrecipe = rand() % 6;
		cook->compare = -1;
	}
	if (cook->brecipe == 1) {
		rolled_text(cook);
	}
	sfRenderWindow_drawSprite(cook->w, cook->client, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->rollcommand, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->questrolled, NULL);
	draw_rolled(cook);
}
