#include <ncurses.h>

int	main(void)
{
	initscr();
	move(20, 20);
	printw("20:20\n");
	getch();
	endwin();
	return (0);
}
