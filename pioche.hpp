#ifndef PIOCHE_HPP
#define PIOCHE_HPP

#include <iostream>
#include <vector>
#include "carte.hpp"
#include "joueur.hpp"
using namespace std;

class Pioche{
private:
    vector<Carte> pioche;
public:
    //constructeur
    Pioche();
    //méthodes
    Carte piocher();                //renvoie une carte piochée par un joueur
    void defausse(Carte c);        //un joueur défausse une carte et la rajoute dans la pioche
    void melanger();         //mélange aléatoirement la pioche à l'initialisation de la partie
};

#endif