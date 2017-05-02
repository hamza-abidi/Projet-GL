#ifndef __INPUT_H__
#define __INPUT_H__
#define UP 'z'
#define RIGHT 'd'
#define DOWN 's'
#define LEFT 'q'
#define ESC 27
#define SAVE 1
#define QUIT 0
#define window_width 121 // \brief La largeur maximale de la map (la longueur des lignes du fichier texte qui represente la map)
#define window_height 21 // \brief La hauteur maximale de la map (le nombre des lignes du fichier texte qui represente la map)
#define map_width 40 // \brief La largeur du segment qui sera affiché sur l'ecran 
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
