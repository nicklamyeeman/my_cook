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
#include <stdio.h>
#include "my.h"

void	my_cook(cook_t *cook)
{
	int	state = 6;
	int	beer = 0;

	while (sfRenderWindow_isOpen(cook->w)) {
		cook_event(cook);
		sfRenderWindow_clear(cook->w, sfBlack);
		main_page(cook);
		page(cook, &state);
		beer_ispressed(cook, &beer);
		sfText_setString(cook->f_score, int_to_char(cook->score));
		sfRenderWindow_display(cook->w);
	}
}

void	starting_game()
{
	cook_t cook;

	init_values(&cook);
	cook.w = sfRenderWindow_create(cook.mode, "mycook", sfFullscreen, NULL);
	sfRenderWindow_setKeyRepeatEnabled(cook.w, sfFalse);
	font_home(&cook);
	textn_sprite(cook);
	sfRenderWindow_setFramerateLimit(cook.w, 60);
	my_cook(&cook);
	destroy(&cook);
	return;
}

int	help_message(void)
{
	my_putstr("USAGE\n\t./my_cook [options]\n");
	my_putstr("DESCRIPTION\n\toptions:\t-h.\n");
	return (0);
}

int	check_arg(char *str, char *cmp)
{
	for (int i = 0; str[i] != '\0'; i ++)
		if (str[i] != cmp[i])
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	void	*m = malloc(1);

	srand((unsigned long)m);
	if (ac > 2)
		return (84);
	if (ac == 1)
		starting_game();
	else if (ac == 2)
		if (check_arg(av[1], "-h") == 1)
			return (help_message());
	return (0);
}
