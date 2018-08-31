#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	w_error(void)
{
	printf("Usage: helper [name]\n");
	exit(0);
}

void	show_math()
{
	int row;
	int col;
	int i;
	char numbers[4][1024] = {
		"[N] = {1, 2, 3, ...}",
		"[Z] = {0, +-1, +-2, +-3, ...}",
		"[Q] = {p/q : p, q part of Z, q != 0}",
		"[R] = {irrational numbers}"
	};

	i = -1;
	getmaxyx(stdscr, row, col);
	while (++i < 4)
		mvwprintw(stdscr, row / 2 + i, (col - strlen(numbers[i])) / 2, "%s", numbers[i]);
	getch();
}

int	main(int ac, char **av)
{
	if (ac != 2)
		w_error();
	initscr();
	wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');    
	if (!strcmp(av[1], "math"))
		show_math();
	endwin();
	return (0);
}
