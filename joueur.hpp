#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <vector>
#include "carte.hpp"

using namespace std;

class Joueur{
private:
  string couleurTortue;
  vector<Carte> main;
public:
  Joueur();
  Joueur(string couleur);
  void addCartes(Carte c);
  Carte removeCartes(Carte c);

  vector<Carte> getCarte();
};

#endif