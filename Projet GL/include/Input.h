#ifndef __INPUT_H__
#define __INPUT_H__
#define UP 'z'
#define RIGHT 'd'
#define DOWN 's'
#define LEFT 'q'
#define ESC 27;
#include <termios.h>

class Input {
	public:
		Input();
		~Input();
		unsigned char keyboard();
	private:
		struct termios* old_tio;
};

#endif
