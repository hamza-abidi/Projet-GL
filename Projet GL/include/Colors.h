/// \file Color.cpp
/// \author Abidi Hamza
/// \date 20 Avril 2017
///
/// La classe Color se base sur une bibliothèque qui nous permet de colorer des chaine de caractéres données et/ou leurs arrières-plan,
/// Color va nous permettre d'afficher des couleurs à partir d'un caractére donnée.
/// [R : ROUGE , B : BLEU , V : VERT , J : JAUNE ]
#include <string>
using namespace std ;

class Colors{
public:
	/// \brief constructeur Colors
	Colors();
	/// \brief activer la coloration de tout ce qu'on affiche sur l'écran.
	void activerTermcolor(char);

	/// \brief désactiver la coloration
	void desactiverTermcolor();

	/// \brief afficher une couleure
	void displayColor(char);

	/// \brief afficher une chaine de caractéres colorée RQ: le curseur reste sur la meme ligne
	void displayColor(string,char);
};
