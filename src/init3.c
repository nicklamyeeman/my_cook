/*
** EPITECH PROJECT, 2018
** init
** File description:
** cook
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void    textn_sprite2(cook_t cook)
{
	sfSprite_setTexture(cook.pause, cook.pau, sfTrue);
	sfSprite_setTexture(cook.yep, cook.y, sfTrue);
	sfSprite_setTexture(cook.nop, cook.n, sfTrue);
	sfSprite_setTexture(cook.endofday, cook.end_od, sfTrue);
}

void	create_rect3(cook_t *cook)
{
	sfIntRect	rhtp = {0, 0, 1920, 1080};

	cook->rhtp = rhtp;
}

void	create_rect2(cook_t *cook)
{
	sfIntRect	rwd = {0, 0, 849, 340};
	sfIntRect	rbr = {0, 0, 604, 126};
	sfIntRect	rqb = {0, 0, 640, 1080};
	sfIntRect	rbd = {0, 0, 849, 340};
	sfIntRect	rroll = {0, 0, 849, 170};
	sfIntRect	rqr = {0, 0, 640, 1080};
	sfIntRect	rrd = {0, 0, 850, 341};
	sfIntRect	rinv = {0, 0, 1920, 1080};

	cook->rwd = rwd;
	cook->rbr = rbr;
	cook->rqb = rqb;
	cook->rbd = rbd;
	cook->rroll = rroll;
	cook->rqr = rqr;
	cook->rrd = rrd;
	cook->rinv = rinv;
	create_rect3(cook);
	create_font(cook);
}

void	init_values2(cook_t *cook)
{
	cook->skip = 0;
	cook->sd = 6;
	cook->evt_bool = 0;
	cook->recipe = 0;
	cook->brecipe = 0;
}
