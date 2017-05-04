// \autor Gautier Bastien
// \date 22 avril 2017

///
/// ... Documentation ...
///

#include "Perso.h"


class Fight
{
	private:
		Perso * entity;		//tableau de toutes les entités dans ce combat
		int numbOfEntity;	
		int turn;			// loto, à qui le tour
		
			
	public:
		
		Fight (Perso * entityC, int numbOfEntityC);
		~Fight();
		
		void battle();			//appel tout
		
		bool onlyOneFighter();	//vefifie si le combat est fini (=true)
		
		int chooseSkill();
		void chooseFighter(int);
		
		int autoChooseTarget();
		int autoChooseSkill();
		

		int manualChooseTarget();
		int manualChooseSkill();
};

