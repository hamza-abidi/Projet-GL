#include "../include/Menu.h"
#include "../include/ClearSrc.h"
using namespace std ;

Menu::Menu() : Input(){
  DIR *dr;
  dr=opendir("../maps/"); // j'accède au dossier
  struct dirent* drnt ; // je enregistre son contenu dans le tableau de dirent drnt (structure)
  nbMaps = 10 ;
  maps = new string[nbMaps];
  int i = 0 ;
   while (i<10 && (drnt=readdir(dr)) !=NULL){ // je parcours le dossier fichier par fichier
     if(strcmp(drnt->d_name,".") != 0 && strcmp(drnt->d_name,"..") != 0){
       maps[i] = drnt->d_name; // je récupère les noms des fichiers
       i++;
     }

  }
  nbMaps = i;
  closedir(dr);

  ManageFile* file = new ManageFile("../personnages/personnages.txt","r");
  nbJoueurs = file->getNumberLines();

  joueurs = new string*[nbJoueurs];
  for(int i = 0 ; i < nbJoueurs ; i++){
    joueurs[i] = new string[12];
    string* tmp = file->readWordsOfLine('|');
    for (int j = 0 ; j < 12 ; j++){
      joueurs[i][j] = tmp[j];
    }
  }
}

Menu::~Menu(){
  delete maps;
  delete* joueurs;
}
void Menu::menuPrincipal(){
  char c ;
  do{
    if(jouer){
      clear_screen();
      color.setColorText("Jouer\n",'R');
      std::cout << "Charger" << '\n';
      std::cout << "Quitter" << '\n';
    }
    else if(charger){
      clear_screen();
      std::cout << "Jouer" << '\n';
      color.setColorText("Charger\n",'R');
      std::cout << "Quitter" << '\n';
    }
    else{
      clear_screen();
      std::cout << "Jouer" << '\n';
      std::cout << "Charger" << '\n';
      color.setColorText("Quitter\n",'R');
    }
    c = keyboard();
    if(jouer && c == DOWN){
      jouer = false;
      charger = true;
    }
    else if(charger){
      if(c == DOWN){
        charger = false;
        quitter = true;
      }
      else if(c == UP){
        charger = false;
        jouer = true;
      }
    }
    else if(quitter && c == UP){
      quitter = false;
      charger = true;
    }
  }while(c != ENT);

  clear_screen();
  if(jouer){
    parametresJeu();
  }
  else if(charger){
    sauvgarde();
  }
  else if(quitter){
    exit(1);
  }
}

void Menu::parametresJeu(){
  int indMap = 0;
  int indJoueur = 0 ;
  int choix = 0 ;
  char c ;
  bool continuer = true;
  while(continuer){

   for (int i = 0 ; i < nbMaps ; i++){
     if(indMap == i){
      color.setColorText(maps[i]+"    ",'R');
     }
     else{
         std::cout << maps[i] << "    ";
     }
   }

   std::cout << '\n'<< '\n'<< '\n'<< '\n'<< '\n';

     for(int i = 0 ; i < nbJoueurs ; i++){
       if(choix == 1 && indJoueur == i){
        color.setColorText(joueurs[i][0]+"  ",'R');
       }
       else{
           std::cout << joueurs[i][0] << "  ";
       }
       std::cout << " | ";
     }
     std::cout << '\n';

     for(int i = 0 ; i < nbJoueurs ; i++){
       if(choix == 1 && indJoueur == i){
        color.setColorText(joueurs[i][1]+"  ",'R');
       }
       else{
           std::cout <<joueurs[i][1] << "  ";
       }
       std::cout << " | ";
     }
     std::cout << '\n';
     for(int i = 0 ; i < nbJoueurs ; i++){
       if(choix == 1 && indJoueur == i){
        color.setColorText(joueurs[i][2]+"  ",'R');
       }
       else{
           std::cout << joueurs[i][2] << "  ";
       }
       std::cout << " | ";
     }
     std::cout << '\n';
     for(int i = 0 ; i < nbJoueurs ; i++){
       if(choix == 1 && indJoueur == i){
        color.setColorText(joueurs[i][3]+"  ",'R');
       }
       else{
           std::cout << joueurs[i][3] << "  ";
       }
       std::cout << " | ";
     }
     std::cout << '\n';

   c = keyboard();

  switch(c){
    case RIGHT : {
      if(choix == 0 && indMap < nbMaps-1)
        indMap++;
      else if(choix == 1 && indJoueur < nbJoueurs-1 )
        indJoueur++;
      break;
    }
    case LEFT : {
      if(choix == 0 && indMap>0)
        indMap--;
      else if(choix == 1 && indJoueur > 0 )
        indJoueur--;
      break;
    }
    case ENT :{
      if(choix == 1 )
        continuer = false ;
      else
        choix++;
      break;
    }
  }
  clear_screen();
 }
 map = indMap ;
 personnage = indJoueur;
 Gameplay gameplay(maps[map]);
 gameplay.play();
}

void Menu::sauvgarde(){
   for (int i = 0 ; i < nbMaps ; i++)
     std::cout << maps[i] << '\n';

  // for (int i = 0 ; i < nbJoueurs ; i++)
  //   std::cout << joueurs[i][0] << '\n';
}
