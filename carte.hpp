#ifndef _CARTE_
#define _CARTE_

#include <iostream>
#include <vector>
using namespace std;

/***********************************************************
Classe Carte:
Description: regroupe tous les attributs de chaque carte du jeu
Attributs: Une variable de type string couleur, correspond à la couleur de la carte (r, y, g, p, g, n)
           Une variable de type entier action, correspond à l'ID de l'action à effectuer
           Variable de type string choixCouleur, correspond à la couleur que le joueur choisi si la carte est neutre
Constructeur: Un constructeur vide, constructeur par défaut
              Un constructeur avec en paramètres la couleur de la carte (neutre compris) et l'id de l'action de la carte
Méthodes:   - string getCouleur(): retourne la couleur de la carte
            - int getAction() : retourne l'ID de l'action à effectuer
            - string getChoixCouleur() : retourne le choix de la couleur effectué par le joueur si la carte est neutre
            - void setChoixCouleur() : défini la couleur de la carte que le joueur choisi si la carte est neutre
***********************************************************/

class Carte {
private:
  string couleur;
  int action;
  string choixCouleur;
public:
  //constructeurs
  Carte();
  Carte(string couleur, int action);
  //accesseurs
  string getCouleur();
  int getAction();
  string getChoixCouleur();
  //mutateurs
  void setChoixCouleur(string couleur);
};

#endif
