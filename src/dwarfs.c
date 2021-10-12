/*
** EPITECH PROJECT, 2018
** dwarf
** File description:
** same
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	dwarf_text(cook_t *cook)
{
	cook->dw = sfTexture_createFromFile("./assets/dwarf.png", NULL);
	cook->dwarf = sfSprite_create();
	sfSprite_setTexture(cook->dwarf, cook->dw, sfTrue);
}

void	dwarfs(cook_t *cook)
{
	if (cook->brace == 1)
		dwarf_text(cook);
	sfRenderWindow_drawSprite(cook->w, cook->dwarf, NULL);
}
