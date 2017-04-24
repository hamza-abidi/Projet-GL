#define window_width 40
#define window_height 21


#include <string>
#include <iostream>
#include <time.h>
#include "../include/Map.h"
#include "../include/ManageFile.h"

using namespace std ;

Map::Map(string nameMap) : Colors(){
  map = nameMap ;
  matrixMap = new char*[window_height];
  ManageFile file(nameMap , "r");
  char c ;
  srand(time(NULL));
  for (int  i = 0 ; i < window_height ; i++){
  	matrixMap[i] = new Case[window_width];
  	for(int j = 0 ; j < window_width ; j++){
  		matrixMap[i][j].c = file.readChar();
      matrixMap[i][j].monster = rand()%1;
  	}
  }
}

Map::modify(Cord cord , string move){
  if(matrixMap[cord.x][cord.y].c != 'e' || matrixMap[cord.x][cord.y].c != 'a'){
    printf("%s T ", move );
    string move2 = move;
    switch (move[move.length()-1]) {
      case 'A': move2[move2.length()-1] = 'B';break;
      case 'B': move2[move2.length()-1] = 'A';break;
      case 'C': move2[move2.length()-1] = 'D';break;
      case 'D': move2[move2.length()-1] = 'C';break;
    }
    printf("%s   ", move2 );
    displayColor("   ",'V');
    printf("%s   ", move );
    return true;
  }
  else
    return false;
}

void Map::display(Cord cord){
	for (int  i = 0 ; i < window_height ; i++){
		for(int j = 0 ; j < window_width ; j++){
  			switch(matrixMap[i][j].c){
  				case 'h' : {
            if(cord.x != i && cord.y != y)
              displayColor("   ",'V');break;
            else
              displayColor(" T ",'V');break;
        }
  				case 'a' : {
            if(cord.x != i && cord.y != y)
              displayColor("   ",'R');break;
            else
              displayColor(" T ",'R');break;
          }
  				case 'e' : {
            if(cord.x != i && cord.y != y)
              displayColor("   ",'B');break;
            else
              displayColor(" T ",'B');break;
          }
  			}
      }
		}
		cout<<'\n';
	}
}
