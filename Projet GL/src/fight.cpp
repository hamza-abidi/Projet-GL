#include <iostream>

#include <stdlib.h>

#include <string>
#include <fstream>
#include <time.h>

#include "../include/Fight.h"
#include "../include/Perso.h"


using namespace std;

	Fight::Fight (Perso * entityC, int numbOfEntityC)
	{
		numbOfEntity=numbOfEntityC;
		entity= entityC;
		
		turn=0;
	}
	
	Fight::~Fight()
	{
		delete [] entity;
	}
	
	void Fight::battle()
	{
		int damage=0;
		turn-=1;
		while ( onlyOneFighter()==false)
		{
		cout<<endl<<endl;
						
			
			turn=(turn+1)%numbOfEntity;
			while (entity[turn].getPv()<1)
			{
				turn=(turn+1)%numbOfEntity;
			}
			
			cout<<"tour du joueur "<<turn<<" : "<<endl<<endl;
			entity[turn].displayStat();
			damage=chooseSkill();
			
			if (damage<=0)
			{
				entity[turn].takeDamage(damage);
			}
			else
			{	
				chooseFighter(damage);
			}

			
			cout<<endl<<endl;

		}
		
		cout<< " the winner is : "<<turn<<endl;
	}


	int Fight::chooseSkill()
	{
		int skillNum=0;

		if ( entity[turn].isIa()==true )
		{
			skillNum=autoChooseSkill();
		}
		else
		{
			skillNum=entity[turn].displaySkill();  //---------------------
	//		cout<<endl;
	//		skillNum=manualChooseSkill();  //-----------------------interface
		}	
		

		
		if (entity[turn].manaCost(skillNum)==false)
		{
			cout<<" no enought mana : "<<entity[turn].getMana()<<endl;
			return chooseSkill();
		}
		else
		{
			cout<<"skill : "<<skillNum<<" joueur : "<<turn<<endl;
			return entity[turn].useSkill (skillNum);
		}
	}
	
	
	bool Fight::onlyOneFighter()
	{
		int cpt=0;
						
		for (int i=0; i<numbOfEntity; i++)
		{
			if (entity[i].getPv() >0)
			{
				cout<<"joueur "<<i<<" en vie avec "<<entity[i].getPv()<<" pv"<<endl;
				cpt+=1;
			}
			else
				cout<<"joueur "<<i<<" mort"<<endl;
	
		}
		if (cpt >= 2)
			{
				return false;
			}
		return true;
		
	}
	
	
	void Fight::chooseFighter(int damage)
	{
		int target=turn;

		while (target==turn || target<0 || target>=numbOfEntity)
		{
		if (numbOfEntity>2)
		{
			if ( entity[turn].isIa()==true )
			{
				target=autoChooseTarget();
			}
			else
			{
				target=manualChooseTarget();
    //-----------------------interface
			}	
		}
		else
		{
			target=(turn+1)%numbOfEntity;
		}	
			      //--------------------------------------interface
			if (entity[target].getPv()<1)
			{
				target=-1;
			}
		}
		//-----------------------------------------------------------
		cout<<"combat : "<<entity[target].getPv()<<" target : " <<target<<endl;
		entity[target].takeDamage (damage);
		cout<<"combat : "<<entity[target].getPv()<<endl;
		//------------------------------------------------------------
	}
	
	
	int Fight::autoChooseTarget()
	{
		srand(time(NULL));
		return rand()%(numbOfEntity);
	}
	
	int Fight::autoChooseSkill()
	{
		srand(time(NULL));
		return rand()%(4);
	}
	
	int Fight::manualChooseTarget()
	{
		int choice;
		cout<<"quel perso : ";
		cin>>choice;
		cout<<endl;
		choice-=1;
		if (choice>numbOfEntity || choice<0)
		{
			cout<<"ce perso n'existe pas"<<endl;
			choice=manualChooseSkill();
		}
		return choice;
	}
	
	int Fight::manualChooseSkill()
	{
		int choice;
		cout<<"quel skill : ";
		cin>>choice;
		cout<<endl;
		if (choice>3 || choice<0)
		{
			cout<<"error"<<endl;
			choice=manualChooseSkill();
		}
		return choice;
	}


	
	
