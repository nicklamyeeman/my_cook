/*
** EPITECH PROJECT, 2018
** cook
** File description:
** font + set + page
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	build_home(cook_t *c)
{
	set_home(c);
	home_page(c);
}

void	build_practice(cook_t *c)
{
	set_practice(c);
	practice_page(c);
}

void	build_inventory(cook_t *c)
{
	set_inventory(c);
	inventory_page(c);
}

void	build_option(cook_t *c, int *state)
{
	set_option(c);
	option_page(c, state);
}

void	build_howtoplay(cook_t *cook)
{
	set_tutorial(cook);
	tuto_page(cook);
}
