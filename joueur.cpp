#include "joueur.hpp"

Joueur::Joueur(){
}

Joueur::Joueur(string couleur){
  this->couleurTortue = couleur;
}

void Joueur::addCartes(Carte c){
  main.push_back(c);
}

Carte Joueur::removeCartes(Carte c){
  return c;
}

vector<Carte> Joueur::getCarte(){
  vector<Carte> c;
  for(vector<Carte>::iterator it = this->main.begin(); it != this->main.end(); it++ ){
    c.push_back(*it);
  }
  return c;
}