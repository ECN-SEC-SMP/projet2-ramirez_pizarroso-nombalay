#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include "carte.hpp"
#include "joueur.hpp"
using namespace std;

/***********************************************************
Classe Plateau:
Description: Simule le plateau de jeu
Attributs: Tableau d'entiers plateauJeu d'une taille de 10 x 5 : positionne les joueurs sur une case, possible d'avoir plusieurs joueurs sur une case, d'où les 5 cases supplémentaires en ordonnée du tableau
Constructeur: Un seul constructeur vide, pas d'initialisation d'attribut à la création du plateau
Méthodes:   - void gestion(Carte c): effectue l'action de la carte jouée
            - void affichePlateau() : affiche le plateau de jeu
***********************************************************/

class Plateau{
private:
  string plateauJeu[10][5];
public:
  //constructeur
  Plateau();
  //méthodes
  void gestion(Carte c);
  void affichePlateau();
};

#endif