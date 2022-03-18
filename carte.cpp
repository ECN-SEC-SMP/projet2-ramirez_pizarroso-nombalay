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
  cout << "Quelle couleur voulez-vous selectionner ?" << endl;
  while(this->choixCouleur != "R" && this->choixCouleur != "G" && this->choixCouleur != "B" && this->choixCouleur != "Y" && this->choixCouleur != "P"){
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
  
  return this->choixCouleur;
}