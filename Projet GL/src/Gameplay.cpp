#include "../include/Gameplay.h"


Gameplay::Gameplay() : Input() {
	map = new Map("../maps/map1");
	srand(time(NULL));
	do{
		player.x = rand()%map->getHeight();
		player.y = rand()%map->getSegmentWidth();
	}while(map->accessible(player) == false);
}

Gameplay::Gameplay(string nameMap , int indJoueur) : Input() {
	map = new Map(nameMap);
	joueur = new Perso(indJoueur,false);

	ManageFile file("../personnages/monstres.txt","r");
	int n = file.getNumberLines();
	file.close();

	Perso* allMonsters = new Perso[n];
	for(int i = 0 ;i<n ; i++){
		allMonsters[i] = *(new Perso(i,true));
	}
	fight = new Fight(*joueur,allMonsters,n);

	srand(time(NULL));
	do{
		player.x = rand()%map->getHeight();
		player.y = rand()%map->getSegmentWidth();
	}while(map->accessible(player) == false);
}


void Gameplay::play() {
	char moving = 'A';
	Colors color;
	map->display(player);
	cout << "\033["<<player.x+1<<";"<<player.y+1<<"H";
	char c ;
	int radar;
	Cord cur ;
	while(true) {
		c = keyboard();
		if(c == UP) {
			moving = 'A';
			player.x -= 1;
			radar = map->move(player, moving);
			if(radar == BLOCK) player.x += 1;
			else if(radar == MONSTER){
				cur = getCursorPosition();
				if(fight->startBattle()){
					map->monsterDied(player);
					setCursorPosition({0,0});
					map->display(player);
					setCursorPosition(cur);
				}
				else{
					clear_screen();
					setCursorPosition({0,0});
					color.setColorText("Vous etes mort",'R');
					exit(1);
				}
			}
		}
		else if(c == DOWN) {
			moving = 'B';
			player.x += 1;
			radar = map->move(player, moving);
			if(radar == BLOCK) player.x -= 1;
			else if(radar == MONSTER){
				cur = getCursorPosition();
				if(fight->startBattle()){
					map->monsterDied(player);
					setCursorPosition({0,0});
					map->display(player);
					setCursorPosition(cur);
				}
				else{
					clear_screen();
					setCursorPosition({0,0});
					color.setColorText("Vous etes mort",'R');
					exit(1);
				}
			}
		}
		else if(c == RIGHT) {
			moving = 'C';
			player.y += 1;
			radar = map->move(player, moving);
			if(radar == BLOCK) player.y -= 1;
			else if(radar == MONSTER){
				cur = getCursorPosition();
				if(fight->startBattle()){
					map->monsterDied(player);
					setCursorPosition({0,0});
					map->display(player);
					setCursorPosition(cur);
				}
				else{
					clear_screen();
					setCursorPosition({0,0});
					color.setColorText("Vous etes mort",'R');
					exit(1);
				}
			}
		}
		else if(c == LEFT) {
			moving = 'D';
			player.y -= 1;
			radar = map->move(player, moving);
			if(radar == BLOCK) player.y += 1;
			else if(radar == MONSTER){
				cur = getCursorPosition();
				if(fight->startBattle()){
					map->monsterDied(player);
					setCursorPosition({0,0});
					map->display(player);
					setCursorPosition(cur);
				}
				else{
					clear_screen();
					setCursorPosition({0,0});
					color.setColorText("Vous etes mort",'R');
					exit(1);
				}
			}
		}


	}
}
