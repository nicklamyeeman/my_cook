/*
** EPITECH PROJECT, 2018
** humans
** File description:
** create humans
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	human_text(cook_t *cook)
{
	cook->hu = sfTexture_createFromFile("./assets/human.png", NULL);
	cook->human = sfSprite_create();
	sfSprite_setTexture(cook->human, cook->hu, sfTrue);
}

void	humans(cook_t *cook)
{
	if (cook->brace == 1)
		human_text(cook);
	sfRenderWindow_drawSprite(cook->w, cook->human, NULL);
}
