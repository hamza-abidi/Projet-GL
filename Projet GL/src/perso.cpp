#include <iostream>

#include <stdlib.h>

#include <string>
#include <fstream>

#include "../include/perso.h"

using namespace std;



Perso::Perso(int line, bool Ia)
{
/*	File file ("perso");
	
	file.setPosition(line);

	string * perso= file.readWordOfLine('|');
*/
	string *perso= new string [12];
	if (line==1)
	{
	
	perso[0]="bob";	//nom
	perso[1]="25";	//pv
	perso[2]="10";	//mana
	perso[3]="0";	//armor
	perso[4]="1";	//comp1 degat
	perso[5]="-1";	//comp1 mana cost
	perso[6]="4";	//comp2 degat
	perso[7]="4";	//comp2	mana cost
	perso[8]="7";	//comp3 degat
	perso[9]="5";	//comp3 mana cost
	perso[10]="10";	//comp4 degat
	perso[11]="6";	//comp4 mana cost
	}
	
	if (line==2)
	{
	perso[0]="monst";
	perso[1]="20";
	perso[2]="10";
	perso[3]="1";
	perso[4]="1";
	perso[5]="0";
	perso[6]="4";
	perso[7]="4";
	perso[8]="7";
	perso[9]="5";
	perso[10]="10";
	perso[11]="6";
	}
	
	if (line==3)
	{
	perso[0]="yolo";
	perso[1]="16";
	perso[2]="10";
	perso[3]="3";
	perso[4]="1";
	perso[5]="-1";
	perso[6]="4";
	perso[7]="4";
	perso[8]="6";
	perso[9]="6";
	perso[10]="8";
	perso[11]="8";
	}
	

	ia=Ia;
	name=perso[0];
 	pv= atoi (perso[1].c_str());
 	pvMax=pv;
 	mana=atoi (perso[2].c_str());
 	manaMax=mana;
 	armor=atoi (perso[3].c_str());

	skill= new int *[4];
	for(int i=0;i<4;i++)
	{
		skill[i]=new int [2];
	} 


	skill[0][0]=atoi (perso[4].c_str());
	skill[0][1]=atoi (perso[5].c_str());
	
	skill[1][0]=atoi (perso[6].c_str());
	skill[1][1]=atoi (perso[7].c_str());
	
	
	skill[2][0]=atoi (perso[8].c_str());
	skill[2][1]=atoi (perso[9].c_str());
	
	
	skill[3][0]=atoi (perso[10].c_str());
	skill[3][1]=atoi (perso[11].c_str());
    

}




Perso::Perso()
{

	ia=true;
	name="";
	pv=0;
	mana=0;
	armor=0;
	
	skill= new int* [4];
	for(int i=0;i<4;i++)
	{
		skill[i]=new int [2];
	} 

	skill[0][0]=0;
	skill[0][1]=0;
			
	skill[1][0]=0;
	skill[1][1]=0;
			
	skill[2][0]=0;
	skill[2][1]=0;
			
	skill[3][0]=0;
	skill[3][1]=0;
	

}

Perso::~Perso()
{
	delete * skill ;
}

bool Perso::isIa()
{
	return ia;
}

string Perso::getName()
{
	return name;
}

int Perso::getPv()
{
	return pv;
}

int Perso::getPvMax()
{
	return pvMax;
}

int Perso::getMana()
{
	return manaMax;
}

int Perso::getManaMax()
{
	return mana;
}

int Perso::getArmor()
{
	return armor;
}

int Perso::getSkillDam(int num)
{
	return skill [num][0];
}

int Perso::getSkillCost(int num)
{
	return skill [num][1];
}

void Perso::modifName(string newName)
{
	name=newName;
}

void Perso::modifPv(int Pv)
{
	if (Pv==0)
	{
		pv=10;
		pvMax=pv;
	}
	else if (Pv<0)
	{
		pv=Pv*(-1);
		pvMax=pv;
	}
	else
	{
		pv=Pv;
		pvMax=pv;
	}
}

void Perso::modifMana(int Mana)
{
	if (Mana<0)
	{
		mana=Mana*(-1);
		if (mana==0)
		{
			manaMax=10;
		}
		else
		{
			manaMax=mana;
		}
	}
	else
	{
		manaMax=mana;
		mana=Mana;
	}
}

void Perso::modifArmor(int Armor)
{
	if (Armor<0)
	{
		armor=Armor*(-1);
	}
	else
	{
	armor=Armor;
	}
}

void Perso::modifSkillDam(int num, int newDam)
{
	skill[num][0]=newDam;
}
void Perso::modifSkillCost(int num, int newCost)
{
	skill[num][1]=newCost;
}


void Perso::modifPerso()
{
	string answer = "no";
	while (answer.compare("yes")!=0 && answer.compare("y")!=0)
	{
		displayClasse();
		cout<<"modif name ? ";
		cin>>answer;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			cout<<"new name : ";
			cin>>answer;
			modifName(answer);
			answer="no";
		}
		
		cout<<"modif Pv ? ";
		cin>>answer;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			cout<<"new Pv : ";
			cin>>answer;
			modifPv(atoi(answer.c_str()));
			answer="no";
		}
		
		cout<<"modif Mana ? ";
		cin>>answer;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			cout<<"new Mana : ";
			cin>>answer;
			modifMana(atoi(answer.c_str()));
			answer="no";
		}
		
		cout<<"modif Armor ? ";
		cin>>answer;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			cout<<"new Armor : ";
			cin>>answer;
			modifArmor(atoi(answer.c_str()));
			answer="no";
		}
		
		cout<<"modif skill ? ";
		cin>>answer;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			for (int i=0;i<4;i++)
			{
				cout<<"new skill "<<i<<" damage : ";
				cin>>answer;
				modifSkillDam(i,atoi(answer.c_str()));
				
				cout<<"new skill "<<i<<" cost : ";
				cin>>answer;
				modifSkillCost(i,atoi(answer.c_str()));
			}

			answer="no";
		}
		
		cout<<" modif completed ? ";
		cin>>answer;
	}
}

void Perso::regenPv(int Pv)
{
	if ( Pv >0)
	{
		if (pv+Pv<pvMax)
		{
			pv+=Pv;
		}
		else
		{
			regenFullPv();
		}
	}
}
void Perso::regenMana(int Mana)
{
	if ( Mana >0)
	{
		if (mana+Mana<manaMax)
		{	
			mana+=Mana;
		}
		else
		{
			regenFullMana();	
		}
	}
}

void Perso::regenFullPv()
{
	pv=pvMax;

}
void Perso::regenFullMana()
{
	mana=manaMax;
}


bool Perso::manaCost( int num)
{
	if (mana < skill [num][1])
	{
		return false;
	}
	return true;
	
}
int Perso::useSkill (int num)
{
	mana -= skill [num][1];
	return skill [num][0];
}

void Perso::takeDamage (int dam)
{
	if (dam<0)
		pv-=dam;
	else if ( dam-armor > 0)
		pv-= dam-armor;
}


void Perso::displayStat()
{
	cout<<" name : "<<name<<" | pv : "<<pv<<" | mana  : "<<mana<<" | armor : "<<armor<<endl;
}

void Perso::displayClasse()
{
	cout<<"name  : "<<name<<endl
		<<" pv : "<< pv <<" | mana  : "<<mana<<" | armor : "<<armor<<endl
		<<"skill  : dam    cost"<<endl
		<<"skill 0:  "<< skill[0][0] <<"     "<< skill[0][1] <<endl
		<<"skill 1:  "<< skill[1][0] <<"     "<< skill[1][1] <<endl
		<<"skill 2:  "<< skill[2][0] <<"     "<< skill[2][1] <<endl
		<<"skill 3:  "<< skill[3][0] <<"     "<< skill[3][1]<<endl<<endl;
}


void Perso::displaySkill()
{
	for (int i=0; i<4; i++)
	{
		cerr<<"skill "<<i<<" : damage : ";cerr<< getSkillDam(i)<<" mana cost : "<<getSkillCost(i)<<endl;
	}
}



