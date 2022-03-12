#ifndef PIOCHE_HPP
#define PIOCHE_HPP

#include <iostream>
#include <vector>
#include "carte.hpp"
using namespace std;

/***********************************************************
Classe Pioche:
Description: Regroupe toutes les cartes présentent dans la pioche
Attributs: Vecteur de d'objets de type Carte, pioche, sert à stocker toutes les cartes de la pioche
Constructeur: Un seul constructeur vide, pas d'initialisation d'attribut à la création de la pioche
Méthodes:   - void getPioche(): retourne la pioche
            - Carte piocher() : renvoie une carte piochée par un joueur, prend la carte du dessus de la pioche
            - void defausse(Carte c) : quand un joueur défausse une carte et la remet en bas de la pioche
            - void melanger() : mélange aléatoirement la pioche à l'initialisation de la partie
Surcharge d'opérateur: surcharge de l'opérateur <<
***********************************************************/

class Pioche{
private:
  vector<Carte> pioche;
public:
  //constructeur
  Pioche();
  //méthodes
  Carte piocher();
  void defausse(Carte c);
  void melanger();
  //accesseur
  vector<Carte> getPioche();
  //surcharge d'opérateurs
  friend std::ostream& operator<< (std::ostream &, Pioche &);
};

#endif
