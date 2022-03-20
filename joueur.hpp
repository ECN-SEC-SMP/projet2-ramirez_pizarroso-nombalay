#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <vector>
#include <unistd.h>

#include "carte.hpp"
using namespace std;

#define NB_CARTE_JOUEUR    5  

/***********************************************************
Classe Joueur:
Description: Un objet pour chaque joueur de la partie
Attributs: Vecteur de d'objets de type Carte, main, sert à stocker toutes les cartes de la main du joueur
            Variable couleurTortue de type string, garde la couleur de chaque joueur
            Variable "type" de type string, qui indique si le joueur est humain ou est une IA
Constructeur: Un constructeur vide, constructeur par défaut
              Un constructeur avec en paramètre la couleur du joueur
Méthodes:   - void ajoutCarte(Carte c): ajoute une carte à la main du joueur
            - void retraitCarte(Carte c) : retire la carte c de la main du joueur 
            - void afficherCarte() : affiche la main du joueur
            - jouerCarte() : retourne la carte jouée par le joueur humain ou IA
            - string getCouleurTortue() : retourne la couleur de la tortue du joueur
            - vector<int> getCarte() : retourne la main du joueur
            - string getType(): retourne le type du joueur (humain ou IA)
            - setType(string type): permet de définir le type du joueur
            - void afficherCarte() : affiche la main du joueur
            - static vector<string> initCouleur(vector<string> couleur) : randomise la couleur des joueurs au début de la partie
            - static string getVraiCouleur(string couleur) : retourne la couleur format une lettre en couleur française en toute lettre
***********************************************************/

class Joueur{
private:
    string couleurTortue;
    vector<Carte> main;
    string type;
public:
    //constructeurs
    Joueur();
    Joueur(string couleur);
    //méthodes
    void ajoutCarte(Carte c);
    void retraitCarte(Carte c);
    void afficherCarte();
    Carte jouerCarte(int position);
    //accesseurs
    string getCouleurTortue();
    vector<Carte> getCarte();
    string getType();
    //mutateur
    void setType(string type);
    //méthodes statiques
    static vector<string> initCouleur(vector<string> couleur);
    static string getVraiCouleur(string couleur);
};

#endif