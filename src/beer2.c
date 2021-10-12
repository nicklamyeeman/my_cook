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

void	beer_ispressed(cook_t *cook, int *beer)
{
	if (cook->recipe == 2) {
		if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
			*beer += 1;
		if (*beer >= 25) {
			cook->compare++;
			*beer = 0;
		}
	}
}
