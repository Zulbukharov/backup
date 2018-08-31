#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * Функции ввода
 * Вывод без ввода смысла не имеет, поэтому разберём функции ввода. 
 * Как и функции вывода, функции ввода условно можно поделить на три группы:
 * getch()-функции. Считывание символа.
 * scanw()-функции. Форматированный ввод.
 * getstr()-функции. Считывание строки.
 */
void	putstr(char *s)
{
	int i;

	i = 0;
	if (!s || !*s)
		return ;
	while (*s)
	{
		addch(*s | A_BOLD);
		s++;
	}
}

int	main(void)
{
	char items[5][7] = {
		"Item 1\0",
		"Item 2\0",
		"Item 3\0",
		"Item 4\0",
		"exit  \0",
	};
	int choice;

	choice = 0;
	initscr(); // init nahuuuuuuuuuuuuui
	curs_set(0); // kill mouse
	keypad(stdscr, 1);
	while (1)
	{
		clear(); //clear window
		for (int i = 0; i < 5; i++)
		{
			if (i == choice)
				addch('>');
			else
				addch(' ');
			//printw("1");
			printw("%s\n", items[i]);
			//putstr(items[i]);
		}
		switch (getch()) // get keyboard
		{
			case KEY_UP:
				if (choice)
					choice--;
				break ;
			case KEY_DOWN:
				if (choice != 4)
					choice++;
				break ;
			case 10:
				if (choice == 4)
				{
					endwin();
					exit(0);
				}
				break ;
		}
	}
	endwin();
	return (0);
}
