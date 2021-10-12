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

sfVector2f	v2f(float x, float y)
{
	sfVector2f	v;

	v.x = x;
	v.y = y;
	return (v);
}
