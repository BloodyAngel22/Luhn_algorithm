#include "logic.h"
#include <curses.h>

void Luhn::fillArray(){	
	for (int i = 0; i < 16 ;i++){
	int a = getch();
	if ((i+1) % 4 == 0)
		printw(" ");
	a -= 48;
	arr[i] = a;
	}
	printw("\n");
}

void Luhn::printArr(){
	for (int i = 0; i < 16 ;i++){
		printw("%d", arr[i]);
		if ((i+1) % 4 == 0)
			printw(" ");
	}
}

void Luhn::digitBypass(){
	for (int i = 0; i < 16; i++){
		if (i % 2 == 1)
			sum += arr[i];
		else
			sum += odd(arr[i]);
	}
}

int Luhn::odd(int number){
	if (number < 5){
		return number*2;
	}
	else {
		number *= 2;
		int tmp = (number % 10) + 1;
		return tmp;
	}
}

bool Luhn::checkSum(){
	if (sum % 10 == 0)
		return true;
	return false;
}
