#include "../include/Gameplay.h"
#include "../include/Input.h"
#include <iostream>

Gameplay::Gameplay() : Input() {
	map = new Map("../maps/map1");
	player.x = 10;
	player.y = 0;
}

Gameplay::Gameplay(string nameMap) : Input() {
	map = new Map(nameMap);
	player.x = 10;
	player.y = 0;
}


void Gameplay::play() {
	char move = 'A';
	map->display(player);
	cout << "\033["<<player.x+1<<";"<<player.y<<"H";
	while(true) {
		char c = keyboard();
		if(c == UP) {
			move = 'A';
			player.x -= 1;
			if(!map->modify(player, move)) player.x += 1;
		}
		else if(c == DOWN) {
			move = 'B';
			player.x += 1;
			if(!map->modify(player, move)) player.x -= 1;
		}
		else if(c == RIGHT) {
			move = 'C';
			player.y += 1;
			if(!map->modify(player, move)) player.y -= 1;
		}
		else if(c == LEFT) {
			move = 'D';
			player.y -= 1;
			if(!map->modify(player, move)) player.y += 1;
		}
	}
}
