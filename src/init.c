/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	create_textnspri2(cook_t *cook)
{
	cook->gp = sfTexture_createFromFile("./assets/gameplay.png", NULL);
	cook->gameplay = sfSprite_create();
	cook->cur = sfTexture_createFromFile("./assets/cursor.png", NULL);
	cook->crs = sfSprite_create();
	cook->pau = sfTexture_createFromFile("./assets/pause.png", NULL);
	cook->pause = sfSprite_create();
	cook->fi = sfTexture_createFromFile("./assets/fire.png", NULL);
	cook->fire = sfSprite_create();
	cook->y = sfTexture_createFromFile("./assets/Yep.png", NULL);
	cook->yep = sfSprite_create();
	cook->n = sfTexture_createFromFile("./assets/Nop.png", NULL);
	cook->nop = sfSprite_create();
	cook->end_od = sfTexture_createFromFile("./assets/endotd.png", NULL);
	cook->endofday = sfSprite_create();
}

void	create_textnspri(cook_t *cook)
{
	cook->me = sfTexture_createFromFile("./assets/menu.png", NULL);
	cook->menu = sfSprite_create();
	cook->pe = sfTexture_createFromFile("./assets/pressenter.png", NULL);
	cook->pressenter = sfSprite_create();
	cook->ho = sfTexture_createFromFile("./assets/home.png", NULL);
	cook->home = sfSprite_create();
	cook->i1 = sfTexture_createFromFile("./assets/ATU.png", NULL);
	cook->intro1 = sfSprite_create();
	cook->i2 = sfTexture_createFromFile("./assets/NIK.png", NULL);
	cook->intro2 = sfSprite_create();
	cook->in = sfTexture_createFromFile("./assets/inter.png", NULL);
	cook->inter = sfSprite_create();
	cook->ch = sfTexture_createFromFile("./assets/check.png", NULL);
	cook->check_png = sfSprite_create();
	cook->un = sfTexture_createFromFile("./assets/uncheck.png", NULL);
	cook->uncheck = sfSprite_create();
	cook->vol = sfTexture_createFromFile("./assets/volume.png", NULL);
	cook->volume_png = sfSprite_create();
	create_textnspri2(cook);
}

void	textn_sprite(cook_t cook)
{
	sfSprite_setTexture(cook.menu, cook.me, sfTrue);
	sfSprite_setTexture(cook.pressenter, cook.pe, sfTrue);
	sfSprite_setTexture(cook.fire, cook.fi, sfTrue);
	sfSprite_setTextureRect(cook.pressenter, cook.rpe);
	sfSprite_setTextureRect(cook.gameplay, cook.rgp);
	sfSprite_setTextureRect(cook.fire, cook.rfi);
	sfSprite_setPosition(cook.pressenter, v2f(690, 860));
	sfSprite_setPosition(cook.fire, v2f(1420, 300));
	sfTexture_setRepeated(cook.pe, sfTrue);
	sfSprite_setTexture(cook.home, cook.ho, sfTrue);
	sfSprite_setTexture(cook.intro1, cook.i1, sfTrue);
	sfSprite_setTexture(cook.intro2, cook.i2, sfTrue);
	sfSprite_setTexture(cook.inter, cook.in, sfTrue);
	sfSprite_setTexture(cook.check_png, cook.ch, sfTrue);
	sfSprite_setTexture(cook.uncheck, cook.un, sfTrue);
	sfSprite_setTexture(cook.volume_png, cook.vol, sfTrue);
	sfSprite_setTexture(cook.gameplay, cook.gp, sfTrue);
	sfSprite_setTexture(cook.crs, cook.cur, sfTrue);
	textn_sprite2(cook);
}

void	create_rect(cook_t *cook)
{
	sfIntRect	rpe = {0, 0, 577, 90};
	sfIntRect	rgp = {0, 0, 1920, 1080};
	sfIntRect	rfi = {0, 0, 288, 271};
	sfIntRect	rpyco = {0, 0, 604, 235};
	sfIntRect	rqp = {0, 0, 640, 1080};
	sfIntRect	rpd = {0, 0, 850, 341};
	sfIntRect	rwg = {0, 0, 517, 120};
	sfIntRect	rqw = {0, 0, 640, 1080};

	cook->rpe = rpe;
	cook->rgp = rgp;
	cook->rfi = rfi;
	cook->rcl = rgp;
	cook->rpyco = rpyco;
	cook->rqp = rqp;
	cook->rpd = rpd;
	cook->rwg = rwg;
	cook->rqw = rqw;
	create_rect2(cook);
}

void	init_values(cook_t *cook)
{
	create_textnspri(cook);
	create_fontnmusic(cook);
	create_clock(cook);
	cook->mode.width = WIDTH;
	cook->mode.height = HEIGHT;
	cook->mode.bitsPerPixel = 32;
	cook->loob = 0;
	cook->hours = 9;
	cook->minutes = 0;
	cook->check_for_pause = 0;
	cook->check = 0;
	cook->score = 0;
	cook->son = 1;
	cook->end = 0;
	cook->volume = 50;
	sfMusic_setLoop(cook->music, 1);
	sfMusic_play(cook->music);
	sfMusic_setVolume(cook->music, cook->volume);
	init_values2(cook);
	create_rect(cook);
}
