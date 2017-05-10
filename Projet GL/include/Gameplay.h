#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include "Map.h"
#include "Input.h"
#include "Perso.h"
#include "Fight.h"
#include <iostream>
#include <time.h>


class Gameplay  : Input{
	public:
		Gameplay();
		Gameplay(string,int);
		void play();
	private:
		Map* map;
		Cord player;
		Perso* joueur;
		Perso** monstres;
		Fight* fight;
};

#endif
