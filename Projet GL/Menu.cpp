#include "../include/Menu.h"
#include "../include/ClearSrc.h"
using namespace std ;

Menu::Menu() : Input(){
  DIR *dr;
  dr=opendir("../maps/"); // j'accède au dossier
  struct dirent* drnt ; // je enregistre son contenu dans le tableau de dirent drnt (structure)
  nbMaps = 10 ;
  maps = new string[nbMaps+1];
  int i = 0 ;
   while (i<10 && (drnt=readdir(dr)) !=NULL){ // je parcours le dossier fichier par fichier
     if(strcmp(drnt->d_name,".") != 0 && strcmp(drnt->d_name,"..") != 0 && strcmp(drnt->d_name,"terrainDesCombats.txt") !=0){
       maps[i] = drnt->d_name; // je récupère les noms des fichiers
       i++;
     }

  }
  maps[i] = "Construire une map";
  nbMaps = i+1;
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
  int colonne ;
  int ligne ;
  do{
    colonne = getTermSize().y / 2 - 5 ;
    ligne = 2;
    if(jouer){
      clear_screen();
      setCursorPosition(ligne,colonne);
      color.setColorText("Jouer\n",'R');

      ligne+=2;
      setCursorPosition(ligne,colonne);
      std::cout << "Charger" << '\n';

      ligne+=2;
      setCursorPosition(ligne,colonne);
      std::cout << "Quitter" << '\n';
    }
    else if(charger){
      clear_screen();
      setCursorPosition(ligne,colonne);
      std::cout << "Jouer" << '\n';

      ligne+=2;
      setCursorPosition(ligne,colonne);
      color.setColorText("Charger\n",'R');

      ligne+=2;
      setCursorPosition(ligne,colonne);
      std::cout << "Quitter" << '\n';
    }
    else{
      clear_screen();
      setCursorPosition(ligne,colonne);
      std::cout << "Jouer" << '\n';

      ligne+=2;
      setCursorPosition(ligne,colonne);
      std::cout << "Charger" << '\n';

      ligne+=2;
      setCursorPosition(ligne,colonne);
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
  unsigned width_colomn = 0;
  char c ;
  bool continuer = true;
  for(int i = 0 ; i < nbJoueurs ; i++){
    if(joueurs[i][0].length() > width_colomn)
     width_colomn = joueurs[i][0].length() ;
   }
   width_colomn++;
   int posCursorColomn;

  while(continuer){

    color.setColorText("Choisir une map\n",'V');
   for (int i = 0 ; i < nbMaps ; i++){
     if(indMap == i){
      color.setColorText(maps[i]+"    ",'R');
     }
     else{
         std::cout << maps[i] << "    ";
     }
   }

   std::cout << '\n'<< '\n'<< '\n'<< '\n'<< '\n';

   color.setColorText("Choisir un personnage\n",'V');

    Cord position = getCursorPosition();
    posCursorColomn = 0;
    for(int i = 0 ; i < nbJoueurs ; i++){
       if(choix == 1 && indJoueur == i){
        color.setColorText(joueurs[i][0],'R');
       }
       else{
           std::cout << joueurs[i][0] ;
       }
       posCursorColomn+= width_colomn ;
       if (i != 0)
        posCursorColomn+= 2 ;
       setCursorPosition(position.x , posCursorColomn);
       std::cout << " | ";
     }
     std::cout << '\n';
     position.x++;

     posCursorColomn = 0;
     for(int i = 0 ; i < nbJoueurs ; i++){
       if(choix == 1 && indJoueur == i){
        color.setColorText(joueurs[i][1],'R');
       }
       else{
           std::cout <<joueurs[i][1] ;
       }
       posCursorColomn+= width_colomn ;
       if (i != 0)
        posCursorColomn+= 2 ;
        setCursorPosition(position.x , posCursorColomn);
       std::cout << " | ";
     }
     std::cout << '\n';
     position.x++;

     posCursorColomn = 0;
     for(int i = 0 ; i < nbJoueurs ; i++){
       if(choix == 1 && indJoueur == i){
        color.setColorText(joueurs[i][2],'R');
       }
       else{
           std::cout << joueurs[i][2];
       }
       posCursorColomn+= width_colomn ;
       if (i != 0)
        posCursorColomn+= 2 ;
        setCursorPosition(position.x , posCursorColomn);
       std::cout << " | ";
     }
     std::cout << '\n';
     position.x++;

     posCursorColomn = 0;
     for(int i = 0 ; i < nbJoueurs ; i++){
       if(choix == 1 && indJoueur == i){
        color.setColorText(joueurs[i][3],'R');
       }
       else{
           std::cout << joueurs[i][3] ;
       }
       posCursorColomn+= width_colomn ;
       if (i != 0)
        posCursorColomn+= 2 ;
        setCursorPosition(position.x , posCursorColomn);
       std::cout << " | ";
     }
     position.x-= 3 ;

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
 string newMapName ;
 map = indMap ;
 personnage = indJoueur;
 if(indMap == nbMaps-1){
   newMapName = MenuCreationMap();
   Gameplay gameplay("../maps/"+newMapName,indJoueur,true);
   gameplay.play();
 }
 else{
  Gameplay gameplay("../maps/"+maps[map],indJoueur);
  gameplay.play();
 }
}

void Menu::sauvgarde(){
   for (int i = 0 ; i < nbMaps ; i++)
     std::cout << maps[i] << '\n';

  // for (int i = 0 ; i < nbJoueurs ; i++)
  //   std::cout << joueurs[i][0] << '\n';
}

string Menu::MenuCreationMap(){
  Colors color ;
  string mapName ;
  bool v = false ;
  do{
    clear_screen();
    setCursorPosition(1,1);
    color.setColorText("Nom de la nouvelle map\n",'V');
    mapName = inString();
    v = false;
    DIR *dr;
    dr=opendir("../maps/"); // j'accède au dossier
    struct dirent* drnt ; // je enregistre son contenu dans le tableau de dirent drnt (structure)
     while ((drnt=readdir(dr)) !=NULL){ // je parcours le dossier fichier par fichier
       if(strcmp(drnt->d_name,".") != 0 && strcmp(drnt->d_name,"..") != 0 && strcmp(drnt->d_name,"terrainDesCombats.txt") !=0 && strcmp(drnt->d_name,mapName.c_str()) == 0){
         v = true;
       }
     }
  }while(v == true);
  return mapName ;
}
