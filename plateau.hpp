#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <iostream>
#include "carte.hpp"
#include "joueur.hpp"
#include "pioche.hpp"
using namespace std;

class Plateau{
private:
    string plateauJeu[10][5];
public:
    //constructeur
    Plateau();
    //méthodes
    void gestion(Carte c);        //effectue l'action de la carte jouée
};

#endif