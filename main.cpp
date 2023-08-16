#include <cstdio>
#include <curses.h>
#include <ncurses.h>
#include "logic.h"

int main(){
	Luhn luhn;
	initscr();
	bool isRunnig = true;
	while (isRunnig){
		echo();
		clear();
		printw("Enter card number\n");
		luhn.fillArray();
		luhn.digitBypass();
		bool check = luhn.checkSum();
		curs_set(0);
		if (check)
			printw("This card is valid\n");
		else
			printw("This card isn't valid\n");
		noecho();
		printw("To continue?\n");
		printw("(y)es, (n)o\n");
		switch (getch()) {
			case 'y':
				luhn.sum = 0;
				curs_set(1);
				break;
			case 'n':
				isRunnig = false;
				break;
			default:
				printw("\nError!\n");
				isRunnig = false;
				getch();
				break;
		}
	}
	printw("\nGoodbye!\n");
	refresh();
	getch();
	endwin();

	return 0;
}
