#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include "Map.h"
#include "Input.h"


class Gameplay  : Input{
	public:
		Gameplay();
		Gameplay(string);
		//setMap(string);
		void play();
	private:
		Map* map;
		Cord player;
};

#endif
