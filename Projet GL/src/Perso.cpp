#include "../include/Perso.h"

using namespace std;



Perso::Perso(int line, bool Ia) : Input()
{
	if (Ia==false)
	{
		ManageFile file ("../personnages/personnages.txt","r");

		file.setPosition(line);

		perso= new string [12];
		perso= file.readWordsOfLine('|');
		file.close();
	}
	else
	{
		ManageFile file ("../personnages/monstres.txt","r");

		file.setPosition(line);

		perso= new string [12];
		perso= file.readWordsOfLine('|');
		file.close();
	}

	ia=Ia;
	name=perso[0];
 	pv= atoi (perso[1].c_str());
 	pvMax=pv;
 	mana=atoi (perso[2].c_str());
 	manaMax=mana;
 	armor=atoi (perso[3].c_str());
 	armorMax=armor;

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




Perso::Perso()  : Input()
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
	//delete * skill ;
	//delete perso;
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
		answer=inString();
		cout<<endl;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			cout<<"new name : ";
			answer=inString();
			cout<<endl;
			modifName(answer);
			answer="no";
		}

		cout<<"modif Pv ? ";
		answer=inString();
		cout<<endl;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			cout<<"new Pv : ";
			answer=inString();
			cout<<endl;
			modifPv(atoi(answer.c_str()));
			answer="no";
		}

		cout<<"modif Mana ? ";
		answer=inString();
		cout<<endl;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			cout<<"new Mana : ";
			answer=inString();
			cout<<endl;
			modifMana(atoi(answer.c_str()));
			answer="no";
		}

		cout<<"modif Armor ? ";
		answer=inString();
		cout<<endl;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			cout<<"new Armor : ";
			answer=inString();
			cout<<endl;
			modifArmor(atoi(answer.c_str()));
			answer="no";
		}

		cout<<"modif skill ? ";
		answer=inString();
		cout<<endl;
		if (answer.compare("yes")==0 || answer.compare("y")==0)
		{
			for (int i=0;i<4;i++)
			{
				cout<<"new skill "<<i<<" damage : ";
				answer=inString();
				cout<<endl;
				modifSkillDam(i,atoi(answer.c_str()));

				cout<<"new skill "<<i<<" cost : ";
				answer=inString();
				cout<<endl;
				modifSkillCost(i,atoi(answer.c_str()));
			}

			answer="no";
		}

		cout<<" modif completed ? ";
		answer=inString();
		cout<<endl;
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
	//if (dam<0)
		pv-=dam;
//	else if ( dam-armor > 0)
	//	pv-= dam-armor;
}


void Perso::displayStat()
{
	Colors color ;
	Cord cur = getCursorPosition();
	Cord cord = cur;
	color.displayColor(" name : "+name+'\n','V');
	cord.x++;
	setCursorPosition(cord);
	color.displayColor(" PV   : ",'V');
	for(int i = 0 ; i<pvMax;i++){
		if(i<pv)
			color.displayColor("+",'V');
		else
			color.displayColor(" ",'V');
	}
	cout<<endl;
	cord.x++;
	setCursorPosition(cord);
	color.displayColor(" Mana : ",'V');
	for(int i = 0 ; i<manaMax;i++){
		if(i<mana)
			color.displayColor("+",'V');
		else
			color.displayColor(" ",'V');
	}
	cout<<endl;
	cord.x++;
	setCursorPosition(cord);
	color.displayColor(" Armor: ",'V');
	for(int i = 0 ; i<armorMax;i++){
		if(i<armor)
			color.displayColor("+",'V');
		else
			color.displayColor(" ",'V');
	}
	cout<<endl;
	setCursorPosition(cur);
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


int Perso::displaySkill()
{
/*	for (int i=0; i<4; i++)
	{
		cout<<"skill "<<i<<" : damage : "<< getSkillDam(i)<<" mana cost : "<<getSkillCost(i)<<endl;
	}
*/

	bool tab [4];
	tab[0]=1;
	tab[1]=0;
	tab[2]=0;
	tab[3]=0;


	int pointeur=0;
	char c ='.';

	int numSize=0;
	int tmp=0;

	while (c!=ENT)
	{



		clear_screen();
		displayStat();
		tmp=0;
		numSize=0;
		for (int x=0;x<4;x++)
		{
			tmp=numbSize(x);
			if (tmp>numSize)
				numSize=tmp;
		}
		numSize+=18;

		for (int x=0;x<4;x++)
		{
			displayFrame(tab[x],x,numSize);
		}

		c= keyboard();

		if(c == DOWN) {
			if( pointeur < 3)
			{
				tab[pointeur]=0;
				pointeur+=1;
				tab[pointeur]=1;
			}
		}
		else if(c == UP) {
			if( pointeur > 0)
			{
				tab[pointeur]=0;
				pointeur-=1;
				tab[pointeur]=1;
			}
		}



	}
	return pointeur;

}

void Perso::displayFrame(bool choice, int numSkill, int numSize)
{

	if( choice)
	{


		cout<<endl<<"\e["<<31<<"m"<<'|'<<"\e[0m"

		<<"   dammage : "<<getSkillDam(numSkill)<<"  "	;

		for (int j=0;j<numSize-(17+damSize(numSkill)); j++)
		{
			cout<<" ";
		}

		cout<<"\e["<<31<<"m"<<'|'<<endl<<'|'<<"\e[0m"

		<<"      cost : "<<getSkillCost(numSkill)<<"  ";

		for (int j=0;j<numSize-(17+costSize(numSkill)); j++)
		{
			cout<<" ";
		}

		cout<<"\e["<<31<<"m"<<'|'<<endl<<"\e[0m";


	}
	else
	{
		cout<<endl<<'|'
		<<"   dammage : "<<getSkillDam(numSkill)<<"  "	;

		for (int j=0;j<numSize-(17+damSize(numSkill)); j++)
		{
			cout<<" ";
		}

		cout<<'|'<<endl<<'|'

		<<"      cost : "<<getSkillCost(numSkill)<<"  ";

		for (int j=0;j<numSize-(17+costSize(numSkill)); j++)
		{
			cout<<" ";
		}


		cout<<'|'<<endl;
	}
}

int Perso::damSize( int numSkill)
{
	int dam=getSkillDam(numSkill);
	int cpt=1;
	if (dam<0)
		dam+=1;
	while(dam>9 || dam<-9)
	{
		cpt+=1;
		dam=dam/10;
	}
	return cpt;
}

int Perso::costSize(int numSkill)
{
	int cost=getSkillCost(numSkill);
	int cpt=1;
	if (cost<0)
		cpt+=1;
	while(cost>9 || cost<-9)
	{
		cpt+=1;
		cost=cost/10;
	}
	return cpt;
}
int Perso::numbSize( int numSkill)
{
	int dam=damSize(numSkill);
	int cost=costSize(numSkill);

	if (dam>cost)
		return dam;
	return cost;
}
