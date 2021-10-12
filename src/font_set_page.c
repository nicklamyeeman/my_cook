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

void	build_quit(cook_t *c)
{
	set_quit(c);
	quit_page(c);
}

void	build_credits(cook_t *c)
{
	set_credits(c);
	credits_page(c);
}

void	build_pause(cook_t *c)
{
	set_pause(c);
	pause_page(c);
}
