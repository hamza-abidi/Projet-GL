/// \file Map.cpp
/// \author Abidi Hamza
/// \date 20 Avril 2017
///
/// La classe Map va s'occuper de la construction , l'affichage , la modification d'une map
///
/// une map est construite par un ensemble des lettres dans un fichier texte (a : arbre , h : herbe , e : eau)
///

#define window_width 121 // \brief La largeur maximale de la map (la longueur des lignes du fichier texte qui represente la map)
#define window_height 21 // \brief La hauteur maximale de la map (le nombre des lignes du fichier texte qui represente la map)
#define map_width 40 // \brief La largeur du segment qui sera affiché sur l'ecran 

#include <string>
#include "Colors.h"
#include "Cord.h"
using namespace std ;

/// \class Map
/// \bried La classe Map herite la classe Colors
class Map : public Colors  {
  public :
    /// \brief initialiser la map avec un le nom d'un fichier texte qui contient les éléments de la map
    Map(string map);

    /// \brief modifier la map
    bool modify(Cord,char);

    /// \brief afficher la map
    void display(Cord);

  private:
    string map;
    int beginIndex;
    typedef struct Case{
      char c;
      bool monster ;
    }Case ;

    Case** matrixMap ;
};
