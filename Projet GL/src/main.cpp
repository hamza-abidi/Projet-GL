#include "../include/Input.h"
#include <stdio.h>
using namespace std;
int main(){
	unsigned char c;
	while(true) {
		Input put;
		c = put.keyboard();
		printf("%d\n",c);
	}
	// Gameplay gameplay("../maps/map1");
	// gameplay.play();
	return 0;
}
