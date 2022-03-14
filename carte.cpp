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
string Carte::getCouleur() {
  return this->couleur;
}

int Carte::getAction(){
  return this->action;
}

string Carte::getChoixCouleur(){
  return this->choixCouleur;
}