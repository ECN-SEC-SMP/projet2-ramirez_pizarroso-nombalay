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
Méthodes:   - bool gestion(Carte c, Joueur j): effectue l'action de la carte jouée, retourne vrai si un joueur a gagné
            - void affichePlateau() : affiche le plateau de jeu
            - bool changerPositionTortue(int ligne, int colonne, int mouvement) : change de position dans le tableau une tortue, renvoie true si une tortue arrive à la fin
            - void rechercherTortue(string couleur, int * ligne, int * colonne) : recherche dans le tableau une tortue en fonction de sa couleur
            - void rechercherDerniereTortue(int * ligne) : recherche la derniere tortue en course
            - string getWinner() : retourne le ou les gagnants de la partie en fonction des tortues arrivées
***********************************************************/

class Plateau{
private:
  string plateauJeu[10][5];
public:
    //constructeur
    Plateau();
    //méthodes
    bool gestion(Carte c, Joueur j);
    void affichePlateau();
    bool changerPositionTortue(int ligne, int colonne, int mouvement);
    void rechercherTortue(string couleur, int * ligne, int * colonne);
    void rechercherDerniereTortue(int * ligne);
    string getWinner();
};

#endif