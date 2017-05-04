#ifndef __FIGHT_H__
#define __FIGHT_H__

#include <iostream>

#include <stdlib.h>

#include <string>
#include <fstream>
#include <time.h>

#include "Input.h"
#include "Perso.h"


class Fight : Input{
	private:
		Perso* entity;		//tableau de toutes les entités dans ce combat
		int numbOfEntity;
		int turn;			// loto, à qui le tour


	public:

		Fight (Perso*, int);
		~Fight();

		void startBattle();			//appel tout

		bool onlyOneFighter();	//vefifie si le combat est fini (=true)

		int chooseSkill();
		void chooseFighter(int);

		int autoChooseTarget();
		int autoChooseSkill();


		int manualChooseTarget();
		int manualChooseSkill();
};


#endif
