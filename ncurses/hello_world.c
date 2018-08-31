#include <ncurses.h>

int	main(void)
{
	initscr();//переход в режим curses
	printw("Hello World\n"); // отображение приветсвия в буфер
	refresh(); // вывод приветствия на экран
	getch(); // ожидание нажатия кнопки
	endwin(); // выход из curses режима
	return (0);
}
