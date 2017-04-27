#include "../include/Input.h"
#include <stdio.h>
#include <unistd.h>

//
//
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
		else if(c == '/') {
			printf("ok");
			printf("\033[s");
			printf("\n\n\n");
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
		else if(c == UP | c == RIGHT | c == DOWN | c == LEFT)
			return c;
	} while(true);

}
