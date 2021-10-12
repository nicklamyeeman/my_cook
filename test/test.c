/*
** EPITECH PROJECT, 2018
** cook
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

Test(test_window, open_window)
{
	cook_t	w;

	starting_game(w);
	cr_assert_neq(w.w, NULL);
}
