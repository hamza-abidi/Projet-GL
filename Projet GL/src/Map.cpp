#define window_width 40
#define window_height 21

#include <string>
#include <iostream>
#include "../include/Map.h"
#include "../include/ManageFile.h"
using namespace std ;

Map::Map(string nameMap) : Colors(){
  map = nameMap ;
  matrixMap = new char*[window_height];
  ManageFile file(nameMap , "r");
  char c ;
  for (int  i = 0 ; i < window_height ; i++){
  	matrixMap[i] = new char[window_width];
  	for(int j = 0 ; j < window_width ; j++){
  		matrixMap[i][j] = file.readChar();
  	}
  }
}

void Map::display(){
	for (int  i = 0 ; i < window_height ; i++){
		for(int j = 0 ; j < window_width ; j++){
			switch(matrixMap[i][j]){
				case 'h' : displayColor("  ",'V');break;
				case 'a' : displayColor("  ",'R');break;
				case 'e' : displayColor("  ",'B');break;
			}
		}
		cout<<'\n';
	}
}
