
#include <iostream>
#include "carte.hpp"
#include "plateau.hpp"
using namespace std;

Plateau::Plateau(){
  this->plateauJeu[0][0] = "R";
  this->plateauJeu[0][1] = "G";
  this->plateauJeu[0][2] = "P";
  this->plateauJeu[0][3] = "Y";
  this->plateauJeu[0][4] = "B";
}

bool Plateau::changerPositionTortue(int ligne, int colonne, int mouvement){
  int col = colonne;
  int nbTortuesEmpilees = 0;    //1 par défaut car forcément 1 tortue à bouger au minimum
  string couleur_tempo;
  bool win = false;

  if(ligne == 0 && mouvement < 0){
    cout << "Vous avez essayé de vous déplacer vers l'arrière alors que vous êtes case départ." << endl;
  }
  else{
    //regarde le nombre de tortues empilées à déplacer
    while(this->plateauJeu[ligne][col] != "" && nbTortuesEmpilees <= 5){
      nbTortuesEmpilees ++;
      col++;
    }

    //regarde si une tortue gagne le jeu
    if(ligne + mouvement > 9){
      win = true;
      mouvement --;
    }
    else if(ligne + mouvement == 9){
      win = true;
    }
    
    //regarde si des tortues sont déjà présentes sur la case de déplacement, si oui récupère l'index pour la colonne
    col = 0;
    int colonneMouvement = 0;    //colonne où placer la tortue en mouvement
    if(this->plateauJeu[ligne + mouvement][col] != ""){
      while(this->plateauJeu[ligne + mouvement][col] != "" && col < 5){
        colonneMouvement ++;
        col ++;
      }
    }
    
    //déplace la ou les tortues
    if((nbTortuesEmpilees + colonneMouvement) > 5)
      cout << "erreur fonction changement position" << endl;
    else{
      for(int i = 0; i < nbTortuesEmpilees; i++){
        this->plateauJeu[ligne + mouvement][colonneMouvement + i] = this->plateauJeu[ligne][colonne + i];
        this->plateauJeu[ligne][colonne + i] = "";
      }
    }
  }
  return win;
}

void Plateau::rechercherTortue(string couleur, int * ligne, int * colonne){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 5; j++){
      if(couleur == this->plateauJeu[i][j]){
        * ligne = i;
        * colonne = j;
      }
    }
  }
}

void Plateau::rechercherDerniereTortue(int * ligne){
  int i = 0;
  
  while(this->plateauJeu[i][0] == ""){
    i++;
  }
  
  * ligne = i;
}

bool Plateau::gestion(Carte c, Joueur j){
    int action=c.getAction();  
    string couleur=c.getCouleur();
    int ligne = 0;
    int colonne = 0;
    
    if(couleur != "N"){
    if(action==1){      //la couleur concernée avance de 2 cases
      this->rechercherTortue(couleur, &ligne, &colonne);
      //cout << "ligne:" << ligne << "; colonne: " << colonne << endl;
      if(this->changerPositionTortue(ligne, colonne, 2)){return true;}
      else{return false;}
    }
    else if(action==2){    //la couleur concernée avance de 1 case
      this->rechercherTortue(couleur, &ligne, &colonne);
      //cout << "ligne:" << ligne << "; colonne: " << colonne << endl;
      if(this->changerPositionTortue(ligne, colonne, 1)){return true;}
      else{return false;}
    }
    else if(action==3){    //la couleur concernée recule de 1 case
      this->rechercherTortue(couleur, &ligne, &colonne);
      //cout << "ligne:" << ligne << "; colonne: " << colonne << endl;
      //rajouter un test pour savoir si case départ ?
      if(this->changerPositionTortue(ligne, colonne, -1)){return true;}
      else{return false;}
    }else{
      cout << "Erreur ID Action carte ou couleur carte." << endl;
      return false;
    }
    }
    else{
    if(action==4){    //la dernière tortue avance de 2 cases
      this->rechercherDerniereTortue(&ligne);
      //cout << "ligne:" << ligne << "; colonne: " << colonne << endl;
      if(this->changerPositionTortue(ligne, 0, 2)){return true;}
      else{return false;}
    }
    else if(action==5){    //la dernière tortue avance de 1 case
      this->rechercherDerniereTortue(&ligne);
      //cout << "ligne:" << ligne << "; colonne: " << colonne << endl;
      if(this->changerPositionTortue(ligne, 0, 1)){return true;}
      else{return false;}
    }
    else if(action==6){    //la tortue de la couleur choisie par le joueur avance de 1 case   
      couleur = c.getChoixCouleur(j.getType(), j.getCouleurTortue());
      this->rechercherTortue(couleur, &ligne, &colonne);
      //cout << "ligne:" << ligne << "; colonne: " << colonne << endl;
      if(this->changerPositionTortue(ligne, colonne, 1)){return true;}
      else{return false;}
    }
    else if(action==7){     //la tortue de la couleur du joueur recule de 1 case
      couleur = c.getChoixCouleur(j.getType(), j.getCouleurTortue());
      this->rechercherTortue(couleur, &ligne, &colonne);
      //cout << "ligne:" << ligne << "; colonne: " << colonne << endl;
      if(this->changerPositionTortue(ligne, colonne, -1)){return true;}
      else{return false;}
    }else{
      cout << "Erreur ID Action carte ou couleur carte." << endl;
      return false;
    }
    }

}

void Plateau::affichePlateau(){
  for(int i = 0; i < 10; i++){    //lignes
    for(int j = 0; j < 5; j++){    //colonnes
      if(plateauJeu[i][j] != "")
        cout << "[" << this->plateauJeu[i][j] << "]";
      else
        cout << "[ ]";
    }
    cout << endl;
  }
}

string Plateau::getWinner() 
{
    string couleur;
    
    for (int i = 0; i < 5; i++) {
        if(plateauJeu[9][i] != "")
            couleur = plateauJeu[9][i];
            return Joueur::getVraiCouleur(couleur);
    }
}