#include "carte.hpp"

//constructeurs
Carte::Carte() {
}

Carte::Carte(string couleur, int action) {
  this->couleur = couleur;
  this->action = action;
  this->choixCouleur = couleur;
}

//mutateur
void Carte::setChoixCouleur(string couleur) {
  if(this->couleur != "n")
    this->choixCouleur = couleur;
}

//accesseur
string Carte::getCouleur(){
  return this->couleur;
}

int Carte::getAction(){
  return this->action;
}

string Carte::getChoixCouleur(string type, string couleurJoueur){
    vector<string> couleur;
    int choix;
    
    if (type == "humain") {
        cout << "Quelle couleur voulez-vous selectionner ?" << endl;
        while(this->choixCouleur != "R" && this->choixCouleur != "G" && this->choixCouleur != "B" &&    this->choixCouleur != "Y" && this->choixCouleur != "P"){
        cin >> this->choixCouleur;
        if(this->choixCouleur == "r" || this->choixCouleur == "R")
        this->choixCouleur = "R";
        else if(this->choixCouleur == "g" || this->choixCouleur == "G")
        this->choixCouleur = "G";
        else if(this->choixCouleur == "y" || this->choixCouleur == "Y")
        this->choixCouleur = "Y";
        else if(this->choixCouleur == "p" || this->choixCouleur == "P")
        this->choixCouleur = "P";
        else if(this->choixCouleur == "b" || this->choixCouleur == "B")
        this->choixCouleur = "B";
        else
        cout << "Choisir entre les couleurs: R, Y, B, G, P." << endl;
        }
    } else if (type == "IA") {
        // SI on est sur une IA et une carte neutre "+", alors l'IA          
        //joue la carte pour sa tortue
        if (this->getAction() == 6 ) {
            this->choixCouleur = couleurJoueur;
        //si on est sur une carte neutre "-"
        // alors l'IA fait un choix random entre ses adversaires
        } else if (this->getAction() == 7) {
            couleur.push_back("Y");
            couleur.push_back("R");
            couleur.push_back("B");
            couleur.push_back("G");
            couleur.push_back("P");
            for (int i = 0; i<5; i++) {
                if (couleur[i] == couleurJoueur) {
                    couleur.erase(couleur.begin()+i);
                }
            }
            choix = rand() % (couleur.size());
            this->choixCouleur = couleur[choix];
        }
    }
return this->choixCouleur;
}

bool operator==(Carte &a, Carte &b){
  if(a.getAction() == b.getAction() && a.getCouleur() == b.getCouleur())
    return true;
  else
    return false;
}