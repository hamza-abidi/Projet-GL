#include "../include/Gameplay.h"
#include "../include/Input.h"
#include <iostream>
#include <time.h>

Gameplay::Gameplay() : Input() {
	map = new Map("../maps/map1");
	srand(time(NULL));
	do{
		player.x = rand()%map->getHeight();
		player.y = rand()%map->getSegmentWidth();
	}while(map->accessible(player) == false);
}

Gameplay::Gameplay(string nameMap) : Input() {
	map = new Map(nameMap);
	srand(time(NULL));
	do{
		player.x = rand()%map->getHeight();
		player.y = rand()%map->getSegmentWidth();
	}while(map->accessible(player) == false);
}


void Gameplay::play() {
	char moving = 'A';
	map->display(player);
	cout << "\033["<<player.x+1<<";"<<player.y+1<<"H";
	while(true) {
		char c = keyboard();
		if(c == UP) {
			moving = 'A';
			player.x -= 1;
			if(map->move(player, moving) == BLOCK) player.x += 1;
		}
		else if(c == DOWN) {
			moving = 'B';
			player.x += 1;
			if(map->move(player, moving) == BLOCK) player.x -= 1;
		}
		else if(c == RIGHT) {
			moving = 'C';
			player.y += 1;
			if(map->move(player, moving) == BLOCK) player.y -= 1;
		}
		else if(c == LEFT) {
			moving = 'D';
			player.y -= 1;
			if(map->move(player, moving) == BLOCK) player.y += 1;
		}
	}
}
