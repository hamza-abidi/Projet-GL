#include "../include/Input.h"
#include <stdio.h>
#include <unistd.h>

Input::Input() {
	old_tio = new termios;
	tcgetattr(STDIN_FILENO, old_tio);

	struct termios new_tio;
	new_tio = *old_tio;
	new_tio.c_lflag &=(~ICANON & ~ECHO);
	tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
}

Input::~Input() {
	tcsetattr(STDIN_FILENO,TCSANOW,old_tio);
}

unsigned char Input::keyboard() {
	unsigned char c;
	do {
		c = getchar();
		if(c == 27) {
			if(getchar() == 91) {
				c = getchar();
				switch(c) {
				case 65:
					return UP;
					break;
				case 66:
					return DOWN;
					break;
				case 67:
					return RIGHT;
					break;
				case 68:
					return LEFT;
					break;
				}
			}
			else return ESC;
		}
		else if(c == UP || c == RIGHT || c == DOWN || c == LEFT || c == ENT) return c;
		else if(c == '/') {
			printf("\033[s");
			unsigned char s[15];
			char i = 0;
			printf("/");
			while(c != 10 && i != 14 && i >= 0) {
				c = getchar();
				if(c == 127) {
					printf("\033[1D \033[1D");
					s[i] = '\0';
					i--;
				}
				else {
					printf("%c",c);
					s[i] = c;
					i++;
				}
			}
			s[i] = '\0';
			printf("\033[u");
			if(s[0] == 's')
				return SAVE;
			if(s[0] == 'q')
				return QUIT;
		}
	} while(true);
}

Cord Input::getCursorPosition() {
	Cord cursor;
	printf("\033[6n");
	unsigned char c = getchar(); //ESC
	getchar();
	cursor.x = getchar() - '0';
	c = getchar();
	while(c != ';') {
		cursor.x = cursor.x*10 + (c - '0');
		c = getchar();
	}
	cursor.y = getchar() - '0';
	c = getchar();
	while(c != 'R') {
		cursor.y = cursor.y*10 + (c - '0');
		c = getchar();
	}
	return cursor;
}

void Input::setCursorPosition(Cord position) {
	printf("\033[%d;%dH",position.x, position.y);
}

void Input::setCursorPosition(int x, int y) {
	printf("\033[%d;%dH", x, y);
}

void Input::printCord(Cord cord) {
	printf("x:%d y:%d", cord.x, cord.y);
}
Cord Input::getTermSize() {
	Cord size;
	printf("\033[s");
	printf("\033[999;999H");
	size = getCursorPosition();
	printf("\033[u");
	return size;
}

int Input::inInt(){
	bool negative = false;
	int i = 0;
	int a =  0;
	unsigned char c = 0;
	
	c = getchar();
	do {
		if(i == 0 && c == '-') {
			negative = true;
			printf("-");
			i++;
		}
		if(a < 999999 && c >= '0' && c <= '9') {
			a = a*10 + (c -'0');
			printf("%c",c);
			i++;
		}
		if(c == 127 && i > 0) {
			if(i > 1 || negative == false) {
				a /= 10;
			}
			else {
				negative = false;
			}
			printf("\033[1D \033[1D");
			i--;
		}
		c = getchar();
	}while(c != ENT);
	if(negative) a *= -1;
	return a;
}
