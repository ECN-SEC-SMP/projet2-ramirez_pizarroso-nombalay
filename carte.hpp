#ifndef _CARTE_
#define _CARTE_

#include <iostream>
#include <vector>
using namespace std;

class Carte {
public:
    //constructeurs
    Carte(string couleur, int action);
    //accesseurs
    string getCouleur();
    int getAction();
    //mutateurs
    void setChoixCouleur(string couleur);
private:
    string couleur;
    int action;
    string choixCouleur;
};
#endif