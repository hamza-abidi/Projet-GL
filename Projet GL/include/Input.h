#ifndef __INPUT_H__
#define __INPUT_H__

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
