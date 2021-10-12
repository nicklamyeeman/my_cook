/*
** EPITECH PROJECT, 2018
** oui
** File description:
** non
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	draw_pyroco2(cook_t *cook)
{
	if (cook->compare == 4) {
		cook->rewards = 11;
		cook->rpd.top = 0;
		cook->rpd.left = 856;
	}
	if (cook->compare == 2) {
		cook->rewards = 13;
		cook->rpd.top = 694;
		cook->rpd.left = 0;
	}
	if (cook->compare == 5) {
		cook->rewards = 12;
		cook->rpd.top = 694;
		cook->rpd.left = 856;
	}
	sfSprite_setTextureRect(cook->pyrodraw, cook->rpd);
	sfSprite_setPosition(cook->pyrodraw, v2f(530, 630));
	sfRenderWindow_drawSprite(cook->w, cook->pyrodraw, NULL);
}

void	draw_pyroco(cook_t *cook)
{
	if (cook->compare != -1) {
		if (cook->compare == 0) {
			cook->rewards = 6;
			cook->rpd.top = 346;
			cook->rpd.left = 0;
		}
		if (cook->compare == 3) {
			cook->rewards = 8;
			cook->rpd.top = 346;
			cook->rpd.left = 856;
		}
		if (cook->compare == 1) {
			cook->rewards = 7;
			cook->rpd.top = 0;
			cook->rpd.left = 0;
		}
		draw_pyroco2(cook);
	}
}

void	random_recipe_pyro(cook_t *cook)
{
	cook->qp = sfTexture_createFromFile("./assets/questspyroco.png", NULL);
	cook->questpyro = sfSprite_create();
	sfSprite_setTexture(cook->questpyro, cook->qp, sfTrue);
	cook->rqp.top = 0;
	cook->rqp.left = 0;
	if (cook->inrecipe == 1)
		cook->rqp.left = 640;
	else if (cook->inrecipe == 2)
		cook->rqp.left = 1280;
	else if (cook->inrecipe >= 3) {
		cook->rqp.top = 1080;
		if (cook->inrecipe == 4)
			cook->rqp.left = 640;
		else if (cook->inrecipe == 5)
			cook->rqp.left = 1280;
	}
	sfSprite_setTextureRect(cook->questpyro, cook->rqp);
}

void	pyroco_text(cook_t *cook)
{
	cook->cl = sfTexture_createFromFile("./assets/client.png", NULL);
	cook->client = sfSprite_create();
	cook->pyco = sfTexture_createFromFile("./assets/pyrocommand.png", NULL);
	cook->pyrocommand = sfSprite_create();
	cook->pd = sfTexture_createFromFile("./assets/pyrocotelette.png", NULL);
	cook->pyrodraw = sfSprite_create();
	sfSprite_setTexture(cook->pyrodraw, cook->pd, sfTrue);
	sfSprite_setTextureRect(cook->pyrodraw, cook->rpd);
	sfSprite_setTexture(cook->client, cook->cl, sfTrue);
	sfSprite_setTexture(cook->pyrocommand, cook->pyco, sfTrue);
	cook->rpyco.left = 0;
	cook->rpyco.top = 0;
	sfSprite_setTextureRect(cook->pyrocommand, cook->rpyco);
	sfSprite_setPosition(cook->pyrocommand, v2f(1140, 461));
	random_recipe_pyro(cook);
	cook->rcl.top = 1080;
	cook->rcl.left = 1920;
	sfSprite_setTextureRect(cook->client, cook->rcl);
}

void	pyrocotelette(cook_t *cook)
{
	if (cook->brecipe == 1) {
		cook->inrecipe = rand() % 6;
		cook->compare = -1;
	}
	if (cook->brecipe == 1) {
		pyroco_text(cook);
	}
	sfRenderWindow_drawSprite(cook->w, cook->client, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->pyrocommand, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->questpyro, NULL);
	draw_pyroco(cook);
}
