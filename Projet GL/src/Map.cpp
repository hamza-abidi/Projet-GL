
#define window_width 121 // \brief La largeur maximale de la map (la longueur des lignes du fichier texte qui represente la map)
#define window_height 21 // \brief La hauteur maximale de la map (le nombre des lignes du fichier texte qui represente la map)
#define segment_width 40 // \brief La largeur du segment qui sera affiché sur l'ecran

#include <string>
#include <iostream>
#include <time.h>
#include "../include/Map.h"
#include "../include/ManageFile.h"
#include "../include/ClearSrc.h"

using namespace std ;

Map::Map(string nameMap) : Colors(){
  map = nameMap ;
  beginIndex = monstersNumber = 0;
  matrixMap = new Case*[window_height];
  ManageFile file(nameMap , "r");
  srand(time(NULL));
  for (int  i = 0 ; i < window_height ; i++){
  	matrixMap[i] = new Case[window_width];
  	for(int j = 0 ; j < window_width ; j++){
  		matrixMap[i][j].c = file.readChar();
      if(matrixMap[i][j].c == 'h'){
        matrixMap[i][j].monster = rand()%1;
        if(matrixMap[i][j].monster == true)
          monstersNumber++;
      }
      else
        matrixMap[i][j].monster = false ;
  	}
  }
}

int Map::move(Cord cord , char moving){
  if((cord.y - beginIndex) == segment_width){
    beginIndex = cord.y ;
    cout << "\033[0;0H";
    display(cord);
    cout << "\033["<<cord.x+1<<";"<<0<<"H";
    return MOVE;
  }
  else if(cord.y < window_width && cord.x < window_height && cord.y >= 0 && cord.x >= 0 && matrixMap[cord.x][cord.y].c != 'e' && matrixMap[cord.x][cord.y].c != 'a' ){
    if(cord.y < beginIndex && beginIndex != 0){
      beginIndex -= segment_width ;
      clear_screen();
      cout << "\033[0;0H";
      display(cord);
      cout << "\033["<<cord.x+1<<";"<<segment_width<<"H";
      return MOVE;
    }
    switch (moving) {
      case 'A': cout << "\033[A" ;displayColor("T",'V');cout << "\033[D" ;cout << "\033[B" ;break;
      case 'B': cout << "\033[B" ;displayColor("T",'V');cout << "\033[D" ;cout << "\033[A" ;break;
      case 'C': cout << "\033[C" ;displayColor("T",'V');cout << "\033[D" ;cout << "\033[D" ;break;
      case 'D': cout << "\033[D" ;displayColor("T",'V');cout << "\033[D" ;cout << "\033[C" ;break;
    }
    displayColor(" ",'V');cout << "\033[D" ;
    switch (moving) {
      case 'A': cout << "\033[A" ;break;
      case 'B': cout << "\033[B" ;break;
      case 'C': cout << "\033[C" ;break;
      case 'D': cout << "\033[D" ;break;
    }
    return MOVE;
  }
  else{
    if(matrixMap[cord.x][cord.y].monster)
      return MONSTER ;
    else
      return BLOCK;
  }
}

void Map::display(Cord cord){
<<<<<<< HEAD
  clear_screen();
=======
	clear_screen();
>>>>>>> 8642fb27936cd1f00bfb75089e26897d740d4b4e
	for (int  i = 0 ; i < window_height ; i++){
		for(int j = beginIndex ; j < beginIndex+segment_width; j++){
  			switch(matrixMap[i][j].c){
  				case 'h' : {
            if(cord.x != i || cord.y != j)
              displayColor(" ",'V');
             else
               displayColor("T",'V');
            break;
        }
  				case 'a' :
              displayColor(" ",'J');
            break;
  				case 'e' :
              displayColor(" ",'B');
            break;
  			}
      }
      cout << '\n';
		}
	}

  int Map::getWidth(){
    return window_width ;
  }

  int Map::getHeight(){
    return window_height ;
  }

  int Map::getSegmentWidth(){
    return segment_width ;
  }

  bool Map::accessible(Cord cord){
    return !matrixMap[cord.x][cord.y].monster && matrixMap[cord.x][cord.y].c != 'e' && matrixMap[cord.x][cord.y].c != 'a';
  }
