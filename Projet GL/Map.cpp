#include "../include/Map.h"
#include "../include/ClearSrc.h"


using namespace std ;

Map::Map(string nameMap , bool withMonsters , bool toCreate) : Colors(){
  map = nameMap ;
  int r = 50;

  // Initialisation du curseur de Map
  cursor = new Input() ;

  if (toCreate){ // si toCreate est vrai donc il faut creer la map avant de mappser à la suite
    creerMap();
  }

  srand(time(0));
  beginIndex = monstersNumber = 0;
  matrixMap = new Case*[window_height];
  ManageFile file(nameMap , "r");
  for (int  i = 0 ; i < window_height ; i++){
  	matrixMap[i] = new Case[window_width];
  	for(int j = 0 ; j < window_width ; j++){
  		matrixMap[i][j].c = file.readChar();
      if(matrixMap[i][j].c == 'h' && withMonsters){
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
  if(cord.y != window_width-1 && (cord.y - beginIndex) == segment_width && matrixMap[cord.x][cord.y+1].c != 'e' && matrixMap[cord.x][cord.y].c != 'a' ){
    beginIndex += segment_width ;
    cursor->setCursorPosition(1,1);
    display(cord);
    cursor->setCursorPosition(cord.x+1,1);
    if(matrixMap[cord.x][cord.y].monster)
      return MONSTER ;
    else
      return MOVE;

  }
  else if(cord.y < window_width-1 && cord.x < window_height && cord.y >= 0 && cord.x >= 0){
    if(matrixMap[cord.x][cord.y].c != 'e' && matrixMap[cord.x][cord.y].c != 'a' ){
      bool changeMap = false;
      if(cord.y < beginIndex && beginIndex != 0){
        beginIndex -= segment_width ;
        cursor->setCursorPosition(1,1);
        display(cord);
        cursor->setCursorPosition(cord.x+1,segment_width);
        changeMap = true;
      }
      if(changeMap == false){
        Cord position = cursor->getCursorPosition() , newPosition;
        displayColor(" ",'V');
        switch (moving) {
          case 'A': cursor->setCursorPosition(position.x-1,position.y);displayColor("T",'V');
                    newPosition.x = position.x-1; newPosition.y = position.y;
                    break;
          case 'B': cursor->setCursorPosition(position.x+1,position.y);displayColor("T",'V');
                    newPosition.x = position.x+1; newPosition.y = position.y;
                    break;
          case 'C': cursor->setCursorPosition(position.x,position.y+1) ;displayColor("T",'V');
                    newPosition.x = position.x; newPosition.y = position.y+1;
                    break;
          case 'D': cursor->setCursorPosition(position.x,position.y-1);displayColor("T",'V');
                    newPosition.x = position.x; newPosition.y = position.y-1;
                    break;
        }
        cursor->setCursorPosition(newPosition);

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

void Map::display(Case** m,int begin){
  clear_screen();
  for (int  i = 0 ; i < window_height ; i++){
    for(int j = begin ; j < begin+segment_width; j++){
        switch(m[i][j].c){
          case 'h' : {
               displayColor(" ",'V');
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

  void Map::creerMap(){
    clear_screen();
    Case** m = new Case*[window_height];
    for (int  i = 0 ; i < window_height ; i++){
      m[i] = new Case[window_width];
      for(int j = 0 ; j < window_width-1 ; j++){
      	m[i][j].c = 'h';
      }
    }
    int begin = 0 ;
    cursor->setCursorPosition(1,1);
    display(m,begin);
    cursor->setCursorPosition(1,1);
    Cord position;position.x = position.y = 1 ;
    Cord indMat{0,0};
    char c ;
    bool continuer = true;
    while(continuer) {
  		c = cursor->keyboard();
      if(c == ENT)
        continuer = false;
      else
    		switch(c){
          case UP :
            if(position.x>1){
              position.x--;
              indMat.x--;
            }
          break ;

          case DOWN :
            if(position.x<window_height){
              position.x++;
              indMat.x++;
            }
          break ;

          case RIGHT :
            if(position.y<segment_width){
              position.y++;
              indMat.y++;
            }
            else if (begin < window_width - segment_width-1){
              begin+= segment_width ;
              indMat.y ++;
              cursor->setCursorPosition(1,1);
              display(m,begin);
              position.y = 1 ;
            }
          break ;

          case LEFT :
            if(position.y>1){
              position.y--;
              indMat.y--;
            }
            else if (begin != 0){
              begin-= segment_width ;
              indMat.y --;
              cursor->setCursorPosition(1,1);
              display(m,begin);
              position.y = segment_width;
            }
          break ;

          case E :
            m[indMat.x][indMat.y].c = 'e';
            displayColor(" ",'B');
            break ;
          case H :
            m[indMat.x][indMat.y].c = 'h';
            displayColor(" ",'V');
            break ;
          case A :
            m[indMat.x][indMat.y].c = 'a';
            displayColor(" ",'J');
            break ;
        }
      cursor->setCursorPosition(position);
    }

    ManageFile file(map , "w");
    for (int  i = 0 ; i < window_height ; i++){
      for(int j = 0 ; j < window_width-1 ; j++){
        file.write(m[i][j].c);
      }
      file.write('\n');
    }
    file.close();
    cursor->setCursorPosition(1,1);
  }
