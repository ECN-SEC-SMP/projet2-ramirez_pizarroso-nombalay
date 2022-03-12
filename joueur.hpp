#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <vector>
#include "carte.hpp"
using namespace std;

/***********************************************************
Classe Joueur:
Description: Un objet pour chaque joueur de la partie
Attributs: Vecteur de d'objets de type Carte, main, sert à stocker toutes les cartes de la main du joeur
           Variable couleurTortue de type string, garde la couleur de chaque joueur
Constructeur: Un constructeur vide, constructeur par défaut
              Un constructeur avec en paramètre la couleur du joueur
Méthodes:   - void ajoutCarte(Carte c): ajoute une carte à la main du joueur
            - Carte retraitCarte() : renvoie une carte que le joueur souhaite défausser
            - string getCouleurTortue() : retourne la couleur de la tortue du joueur
            - vector<int> getCarte() : retourne la main du joueur
***********************************************************/

class Joueur{
private:
  string couleurTortue;
  vector<Carte> main;
public:
  //constructeurs
  Joueur();
  Joueur(string couleur);
  //méthodes
  void ajoutCarte(Carte c);
  Carte retraitCarte(Carte c);
  //accesseurs
  string getCouleurTortue();
  vector<Carte> getCarte();
};

#endif