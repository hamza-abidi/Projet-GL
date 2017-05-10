// \autor Gautier Bastien
// \date 20 avril 2017

///
/// ... Documentation ...
///

#ifndef PERSO_H
#define PERSO_H


#include <iostream>

#include <stdlib.h>

#include <string>
#include <fstream>


#include "ClearSrc.h"
#include "Input.h"
#include "ManageFile.h"
#include "Colors.h"


class Perso : Input
{
	private:
		bool ia;
		string* perso;
		std::string name;
		int pv;
		int pvMax;
		int mana;
		int manaMax;
		int armor;
		int ** skill;		//skill[][0]=damage skill[][1]=cost

	public:
		Perso();

		Perso(int line, bool Ia);

		Perso(int line, int x, int y);
		~Perso();

		bool isIa();
		std::string getName();
		int getPv();
		int getPvMax();
		int getMana();
		int getManaMax();
		int getArmor();
		int getSkillDam(int);
		int getSkillCost(int);

		void modifPerso();
		void modifName(std::string newName);
		void modifPv(int);
		void modifMana(int);
		void modifArmor(int);
		void modifSkillDam(int num, int newDam);
		void modifSkillCost(int num, int newCost);

		void regenPv(int);
		void regenMana(int);

		void regenFullPv();
		void regenFullMana();

		bool manaCost( int num);

		int useSkill (int);		//reduit le mana et retourne les degats
		void takeDamage (int);	//inflige les degats compte de l'armure

		void displayStat();
		void displayClasse();

		int displaySkill();
		void displayFrame(bool choice, int numSkill, int numSize);

		int numbSize( int numSkill);
		int costSize(int numSkill);
		int damSize( int numSkill);


};

#endif
