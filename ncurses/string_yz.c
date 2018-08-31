#include <ncurses.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int row;
	int col;

	if (ac != 2)
		return (0);
	initscr();
	getmaxyx(stdscr, row, col); // get max y x of stdscr window
	mvwprintw(stdscr, row / 2, (col - strlen(av[1])) / 2 - 2, "[%s]", av[1]);
	//функция для вывода строки по y x который принимает как в printf
	getch();
	endwin();
	printf("[%d][%d]\n", row, col);
	return (0);
}
