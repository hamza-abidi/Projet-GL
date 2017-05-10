#include "../include/Map.h"
#include "../include/ClearSrc.h"


using namespace std ;

Map::Map(string nameMap , bool widthMonsters) : Colors(){
  map = nameMap ;
  int r = 50;
  srand(time(0));
  beginIndex = monstersNumber = 0;
  matrixMap = new Case*[window_height];
  ManageFile file(nameMap , "r");
  for (int  i = 0 ; i < window_height ; i++){
  	matrixMap[i] = new Case[window_width];
  	for(int j = 0 ; j < window_width ; j++){
  		matrixMap[i][j].c = file.readChar();
      if(matrixMap[i][j].c == 'h' && widthMonsters){
        r = rand()%100;
        if(r == rand()%100)
          matrixMap[i][j].monster = true;
        else
          matrixMap[i][j].monster = false ;

        if(matrixMap[i][j].monster == true)
          monstersNumber++;
      }
      else
        matrixMap[i][j].monster = false ;
  	}
  }
}

Map::~Map(){
  delete* matrixMap ;
}

int Map::move(Cord cord , char moving ){
  if((cord.y - beginIndex) == segment_width && matrixMap[cord.x][cord.y+1].c != 'e' && matrixMap[cord.x][cord.y].c != 'a'){
    beginIndex += segment_width ;
    cout << "\033[0;0H";
    display(cord);
    cout << "\033["<<cord.x+1<<";"<<0<<"H";
    if(matrixMap[cord.x][cord.y].monster)
      return MONSTER ;
    else
      return MOVE;

  }
  else if(cord.y < window_width && cord.x < window_height && cord.y >= 0 && cord.x >= 0){
    if(matrixMap[cord.x][cord.y].c != 'e' && matrixMap[cord.x][cord.y].c != 'a' ){
      bool changeMap = false;
      if(cord.y < beginIndex && beginIndex != 0){
        beginIndex -= segment_width ;
        cout << "\033[0;0H";
        display(cord);
        cout << "\033["<<cord.x+1<<";"<<segment_width<<"H";
        changeMap = true;
      }if(changeMap == false){
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
    }
      if(matrixMap[cord.x][cord.y].monster)
        return MONSTER ;
      else
        return MOVE;
    }
  }
  return BLOCK;
}

void Map::display(Cord cord ){
	clear_screen();
	for (int  i = 0 ; i < window_height ; i++){
		for(int j = beginIndex ; j < beginIndex+segment_width; j++){
  			switch(matrixMap[i][j].c){
  				case 'h' : {
            if(matrixMap[i][j].monster)
              displayColor("M",'V');
            else if(cord.x != i || cord.y != j)
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

  void Map::monsterDied(Cord cord){
    matrixMap[cord.x][cord.y].monster = false;
    monstersNumber--;
  }
