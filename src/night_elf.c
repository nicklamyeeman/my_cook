/*
** EPITECH PROJECT, 2018
** night elf
** File description:
** sme
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	night_elf_text(cook_t *cook)
{
	cook->ne = sfTexture_createFromFile("./assets/night_elf.png", NULL);
	cook->night_elf = sfSprite_create();
	sfSprite_setTexture(cook->night_elf, cook->ne, sfTrue);
}

void	night_elf(cook_t *cook)
{
	if (cook->brace == 1)
		night_elf_text(cook);
	sfRenderWindow_drawSprite(cook->w, cook->night_elf, NULL);
}
