#ifndef _JOUEURIA_HPP
#define _JOUEURIA_HPP

#include <iostream>
#include <vector>
#include "joueur.hpp"
using namespace std;

/***********************************************************
Classe JoueurIA:
Description: Un objet pour chaque joueurIA de la partie, cette classe hérite de la classe Joueur
Attributs: 
Constructeur: Un constructeur vide, constructeur par défaut
              Un constructeur avec en paramètre la couleur du joueurIA
Méthodes:   - toutes les méthodes de la classe Joueur puisque JoueurIA hérite de Joueur
***********************************************************/

class JoueurIA : public Joueur {
private:
public:
  //constructeurs
  JoueurIA();
  JoueurIA(string couleur);
};

#endif
