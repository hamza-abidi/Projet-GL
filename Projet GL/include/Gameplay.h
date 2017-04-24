#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include "Map.h"
#include "Input.h"

struct Cord
{
	int x;
	int y;
}Cord;

class Gameplay  : Input{
	public:
		Gameplay();
		Gameplay(string);
		setMap(string);
		play();
	private;
		Map* map;
		Cord player;
};

#endif
	
