/*
** EPITECH PROJECT, 2018
** cook
** File description:
** wings
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void    draw_wings2(cook_t *cook)
{
	if (cook->compare == 3) {
		cook->rewards = 21;
		cook->rwd.top = 346;
		cook->rwd.left = 856;
	}
	if (cook->compare == 4) {
		cook->rewards = 27;
		cook->rwd.top = 694;
		cook->rwd.left = 0;
	}
	if (cook->compare == 5) {
		cook->rewards = 33;
		cook->rwd.top = 694;
		cook->rwd.left = 856;
	}
	sfSprite_setTextureRect(cook->wingsdraw, cook->rwd);
	sfSprite_setPosition(cook->wingsdraw, v2f(530, 630));
	sfRenderWindow_drawSprite(cook->w, cook->wingsdraw, NULL);
}

void	draw_wings(cook_t *cook)
{
	if (cook->compare != -1) {
		if (cook->compare == 0) {
			cook->rewards = 6;
			cook->rwd.top = 0;
			cook->rwd.left = 0;
		}
		if (cook->compare == 1) {
			cook->rewards = 11;
			cook->rwd.top = 0;
			cook->rwd.left = 856;
		}
		if (cook->compare == 2) {
			cook->rewards = 17;
			cook->rwd.top = 346;
			cook->rwd.left = 0;
		}
		draw_wings2(cook);
	}
}

void    random_recipe_wings(cook_t *cook)
{
	cook->qw = sfTexture_createFromFile("./assets/questcw.png", NULL);
	cook->questcw = sfSprite_create();
	sfSprite_setTexture(cook->questcw, cook->qw, sfTrue);
	cook->rqw.top = 0;
	cook->rqw.left = 0;
	if (cook->inrecipe == 1)
		cook->rqw.left = 640;
	else if (cook->inrecipe == 2)
		cook->rqw.left = 1280;
	else if (cook->inrecipe >= 3) {
		cook->rqw.top = 1080;
		if (cook->inrecipe == 4)
			cook->rqw.left = 640;
		else if (cook->inrecipe == 5)
			cook->rqw.left = 1280;
	}
	sfSprite_setTextureRect(cook->questcw, cook->rqw);
}

void	wings_text(cook_t *cook)
{
	cook->cl = sfTexture_createFromFile("./assets/client.png", NULL);
	cook->client = sfSprite_create();
	cook->wgs = sfTexture_createFromFile("./assets/wingscommand.png", NULL);
	cook->wingscommand = sfSprite_create();
	cook->wd = sfTexture_createFromFile("./assets/chickenwings.png", NULL);
	cook->wingsdraw = sfSprite_create();
	sfSprite_setTexture(cook->wingsdraw, cook->wd, sfTrue);
	sfSprite_setTextureRect(cook->wingsdraw, cook->rpd);
	sfSprite_setTexture(cook->client, cook->cl, sfTrue);
	sfSprite_setTexture(cook->wingscommand, cook->wgs, sfTrue);
	cook->rwg.left = 0;
	cook->rwg.top = 0;
	sfSprite_setTextureRect(cook->wingscommand, cook->rwg);
	sfSprite_setPosition(cook->wingscommand, v2f(1140, 540));
	random_recipe_wings(cook);
	cook->rcl.top = 1080;
	cook->rcl.left = 0;
	sfSprite_setTextureRect(cook->client, cook->rcl);
}

void	wings(cook_t *cook)
{
	if (cook->brecipe == 1) {
		cook->inrecipe = rand() % 6;
		cook->compare = -1;
	}
	if (cook->brecipe == 1)
		wings_text(cook);
	sfRenderWindow_drawSprite(cook->w, cook->client, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->wingscommand, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->questcw, NULL);
	draw_wings(cook);
}
