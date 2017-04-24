#include "../include/Gameplay.h"

Gameplay::Gameplay() : Input() {
	map = new Map("map1");
	player.x = 0;
	player.y = 0;
}

Gameplay::Gameplay(string nameMap) : Input() {
	map = new Map(nameMap);
	player.x = 0;
	player.y = 0;
}


Gameplay::play() {
	string move = "\033[XA";
	map.display(player);
	while(true) {
		keyboard();
		if(c == UP) {
			move[6] = 'A';
			player.x -= 1;
			if(!map.modify(player, move) player.x += 1;
		}
		else if(c == DOWN) {
			move[6] = 'B';
			player.x += 1;
			if(!map.modify(player, move) player.x -= 1;
		}
		else if(c == RIGHT) {
			move[6] = 'C';
			player.y += 1;
			if(!map.modify(player, move) player.y -= 1;
		}
		else if(c == LEFT) {
			move[6] = 'D';
			player.y -= 1;
			if(!map.modify(player, move) player.y += 1;
		}
	}
