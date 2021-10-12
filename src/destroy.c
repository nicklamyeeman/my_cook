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

void	destroy_sprite_again(cook_t *cook)
{
	sfSprite_destroy(cook->crs);
	sfTexture_destroy(cook->cur);
}

void	destroy_sprite(cook_t *cook)
{
	sfSprite_destroy(cook->intro1);
	sfTexture_destroy(cook->i1);
	sfSprite_destroy(cook->intro2);
	sfTexture_destroy(cook->i2);
	sfSprite_destroy(cook->inter);
	sfTexture_destroy(cook->in);
	sfSprite_destroy(cook->check_png);
	sfTexture_destroy(cook->ch);
	sfSprite_destroy(cook->uncheck);
	sfTexture_destroy(cook->un);
	sfSprite_destroy(cook->volume_png);
	sfTexture_destroy(cook->vol);
	sfSprite_destroy(cook->gameplay);
	sfTexture_destroy(cook->gp);
	destroy_sprite_again(cook);
}

void	destroy_font(cook_t *cook)
{
	sfText_destroy(cook->f_practice);
	sfText_destroy(cook->f_tutorial);
	sfText_destroy(cook->f_invent);
	sfText_destroy(cook->f_options);
	sfText_destroy(cook->f_quit);
	sfText_destroy(cook->f_tomenu);
	sfText_destroy(cook->f_son);
	sfText_destroy(cook->f_volume);
	sfText_destroy(cook->f_minus);
	sfText_destroy(cook->f_plus);
	sfText_destroy(cook->f_askquit);
	sfText_destroy(cook->f_no);
	sfText_destroy(cook->f_credits);
	sfText_destroy(cook->f_tooptions);
	sfText_destroy(cook->font19);
	sfText_destroy(cook->f_hours);
	sfText_destroy(cook->f_minutes);
	sfText_destroy(cook->f_score);
	destroy_sprite(cook);
}

void	destroy(cook_t *cook)
{
	sfSprite_destroy(cook->menu);
	sfTexture_destroy(cook->me);
	sfSprite_destroy(cook->home);
	sfTexture_destroy(cook->ho);
	sfSprite_destroy(cook->pause);
	sfTexture_destroy(cook->pau);
	sfSprite_destroy(cook->pressenter);
	sfTexture_destroy(cook->pe);
	sfClock_destroy(cook->cpe);
	sfMusic_destroy(cook->music);
	sfRenderWindow_destroy(cook->w);
	destroy_font(cook);
}
