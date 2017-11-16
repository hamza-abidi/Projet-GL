#ifndef _MENU_H_
#define _MENU_H_
#include "Input.h"
#include "Colors.h"
#include "ManageFile.h"
#include "Gameplay.h"
#include <dirent.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
#include <iostream>
#include <string.h>
#include <string>
class Menu : Input{
  public:
    Menu();
    ~Menu();
    void menuPrincipal();
    void parametresJeu();
    string MenuCreationMap();
    void sauvgarde();
  private:
    Colors color;
    int nbMaps ;
    int nbJoueurs;
    bool jouer = true;
    bool charger = false;
    bool quitter = false ;
    string* maps ;
    string** joueurs ;
    int choixMenuPricipal ;
    int personnage ;
    int map ;
};
#endif
