#include <ncurses.h>

/*
 * addch() - Вывод одного символа с заданными атрибутами
 * printw() - Форматированный вывод строки
 * addstr() - Вывод строки
 * A_NORMAL    - обычный режим
 * A_STANDOUT  - самое яркое выделение из всех возможных
 * A_UNDERLINE - подчёркивание
 * A_BLINK     - мигание
 * A_DIM       - тусклый символ
 * A_BOLD      - выделение жирным шрифтом
 */

int	main(void)
{
	initscr();
	printw("Typical sympol \'A\': ");
	addch('A');
	printw("\nUnderline and blink symbol: ");
	addch('A' | A_BLINK);
	printw("\nPrint any key\n");
	getch();
	endwin();
	return (0);
}
