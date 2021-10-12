/*
** EPITECH PROJECT, 2018
** cook
** File description:
** beer
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	draw_beer2(cook_t *cook)
{
	if (cook->compare == 3) {
		cook->rbd.top = 348;
		cook->rbd.left = 856;
	}
	if (cook->compare == 4) {
		cook->rbd.top = 695;
		cook->rbd.left = 0;
		cook->inrecipe = 4;
	}
	if (cook->compare == 5) {
		cook->inrecipe = 0;
		cook->rbd.top = 694;
		cook->rbd.left = 856;
	}
	sfSprite_setTextureRect(cook->beerdraw, cook->rbd);
	sfSprite_setPosition(cook->beerdraw, v2f(530, 630));
	sfRenderWindow_drawSprite(cook->w, cook->beerdraw, NULL);
}

void	draw_beer(cook_t *cook)
{
	if (cook->compare != -1) {
		if (cook->compare == 0) {
			cook->rbd.top = 0;
			cook->rbd.left = 0;
		}
		if (cook->compare == 1) {
			cook->rbd.top = 0;
			cook->rbd.left = 856;
		}
		if (cook->compare == 2) {
			cook->rbd.top = 347;
			cook->rbd.left = 0;
		}
		draw_beer2(cook);
	}
}

void    recipe_beer(cook_t *cook)
{
	cook->qb = sfTexture_createFromFile("./assets/questbeer.png", NULL);
	cook->questbeer = sfSprite_create();
	sfSprite_setTexture(cook->questbeer, cook->qb, sfTrue);
	cook->rqb.top = 0;
	cook->rqb.left = 0;
	sfSprite_setTextureRect(cook->questbeer, cook->rqb);
}

void	beer_text(cook_t *cook)
{
	cook->cl = sfTexture_createFromFile("./assets/client.png", NULL);
	cook->client = sfSprite_create();
	cook->br = sfTexture_createFromFile("./assets/beercommand.png", NULL);
	cook->beercommand = sfSprite_create();
	cook->bd = sfTexture_createFromFile("./assets/beer.png", NULL);
	cook->beerdraw = sfSprite_create();
	sfSprite_setTexture(cook->beerdraw, cook->bd, sfTrue);
	sfSprite_setTextureRect(cook->beerdraw, cook->rbd);
	sfSprite_setTexture(cook->client, cook->cl, sfTrue);
	sfSprite_setTexture(cook->beercommand, cook->br, sfTrue);
	cook->rbr.left = 0;
	cook->rbr.top = 0;
	sfSprite_setTextureRect(cook->beercommand, cook->rbr);
	sfSprite_setPosition(cook->beercommand, v2f(1140, 540));
	recipe_beer(cook);
	cook->rcl.top = 0;
	cook->rcl.left = 1920;
	sfSprite_setTextureRect(cook->client, cook->rcl);
}

void	beer(cook_t *cook)
{
	cook->rewards = 100;
	if (cook->brecipe == 1) {
		cook->inrecipe = rand() % 6;
		cook->compare = -1;
	}
	if (cook->brecipe == 1)
		beer_text(cook);
	sfRenderWindow_drawSprite(cook->w, cook->client, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->beercommand, NULL);
	sfRenderWindow_drawSprite(cook->w, cook->questbeer, NULL);
	draw_beer(cook);
}
