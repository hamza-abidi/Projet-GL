#define window_width 121 // \brief La largeur maximale de la map (la longueur des lignes du fichier texte qui represente la map)
#define window_height 21 // \brief La hauteur maximale de la map (le nombre des lignes du fichier texte qui represente la map)
#define map_width 40 // \brief La largeur du segment qui sera affiché sur l'ecran 

#include <string>
#include <iostream>
#include <time.h>
#include "../include/Map.h"
#include "../include/ManageFile.h"
#include "../include/ClearSrc.h"

using namespace std ;

Map::Map(string nameMap) : Colors(){
  map = nameMap ;
  beginIndex = 0;
  matrixMap = new Case*[window_height];
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

bool Map::modify(Cord cord , char move){
  if((cord.y - beginIndex) == map_width){
    beginIndex = cord.y ;
    clear_screen();
    cout << "\033[0;0H";
    display(cord);
    cout << "\033["<<cord.x+1<<";"<<0<<"H";
    return true;
  }
  else if(cord.y < window_width && cord.x < window_height && cord.y >= 0 && cord.x >= 0 && matrixMap[cord.x][cord.y].c != 'e' && matrixMap[cord.x][cord.y].c != 'a' ){
    if(cord.y < beginIndex && beginIndex != 0){
      beginIndex -= map_width ;
      clear_screen();
      cout << "\033[0;0H";
      display(cord);
      cout << "\033["<<cord.x+1<<";"<<map_width<<"H";
      return true;
    }
    switch (move) {
      case 'A': cout << "\033[A" ;displayColor("T",'V');cout << "\033[D" ;cout << "\033[B" ;break;
      case 'B': cout << "\033[B" ;displayColor("T",'V');cout << "\033[D" ;cout << "\033[A" ;break;
      case 'C': cout << "\033[C" ;displayColor("T",'V');cout << "\033[D" ;cout << "\033[D" ;break;
      case 'D': cout << "\033[D" ;displayColor("T",'V');cout << "\033[D" ;cout << "\033[C" ;break;
    }
    displayColor(" ",'V');cout << "\033[D" ;
    switch (move) {
      case 'A': cout << "\033[A" ;break;
      case 'B': cout << "\033[B" ;break;
      case 'C': cout << "\033[C" ;break;
      case 'D': cout << "\033[D" ;break;
    }
    return true;
  }
  else
    return false;
}

void Map::display(Cord cord){
	for (int  i = 0 ; i < window_height ; i++){
		for(int j = beginIndex ; j < beginIndex+map_width; j++){
  			switch(matrixMap[i][j].c){
  				case 'h' : {
            if(cord.x != i || cord.y != j)
              displayColor(" ",'V');
             else
               displayColor("T",'V');
            break;
        }
  				case 'a' :
              displayColor(" ",'R');
            break;
  				case 'e' :
              displayColor(" ",'B');
            break;
  			}
      }
      cout << '\n';
		}
	}
