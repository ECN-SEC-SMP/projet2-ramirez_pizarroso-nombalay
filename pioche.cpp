#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "pioche.hpp"
#include "carte.hpp"
using namespace std;

Pioche::Pioche(){
    /*nom des couleurs avec la première lettre du mot anglais
    numéro d'action:    1 -> carte couleur et action ++
                        2 -> carte couleur et action +
                        3 -> carte couleur et action -
                        4 -> carte neutre et action =>=>
                        5 -> carte neutre et action =>
                        6 -> carte neutre et action +
                        7 -> carte neutre et action -
    inialisation couleur rouge*/
    this->pioche.push_back(Carte("r", 1));
    this->pioche.push_back(Carte("r", 2));
    this->pioche.push_back(Carte("r", 2));
    this->pioche.push_back(Carte("r", 2));
    this->pioche.push_back(Carte("r", 2));
    this->pioche.push_back(Carte("r", 2));
    this->pioche.push_back(Carte("r", 3));
    this->pioche.push_back(Carte("r", 3));
    //inialisation couleur jaune
    this->pioche.push_back(Carte("y", 1));
    this->pioche.push_back(Carte("y", 2));
    this->pioche.push_back(Carte("y", 2));
    this->pioche.push_back(Carte("y", 2));
    this->pioche.push_back(Carte("y", 2));
    this->pioche.push_back(Carte("y", 2));
    this->pioche.push_back(Carte("y", 3));
    this->pioche.push_back(Carte("y", 3));
    //inialisation couleur bleue
    this->pioche.push_back(Carte("b", 1));
    this->pioche.push_back(Carte("b", 2));
    this->pioche.push_back(Carte("b", 2));
    this->pioche.push_back(Carte("b", 2));
    this->pioche.push_back(Carte("b", 2));
    this->pioche.push_back(Carte("b", 2));
    this->pioche.push_back(Carte("b", 3));
    this->pioche.push_back(Carte("b", 3));
    //inialisation couleur verte
    this->pioche.push_back(Carte("g", 1));
    this->pioche.push_back(Carte("g", 2));
    this->pioche.push_back(Carte("g", 2));
    this->pioche.push_back(Carte("g", 2));
    this->pioche.push_back(Carte("g", 2));
    this->pioche.push_back(Carte("g", 2));
    this->pioche.push_back(Carte("g", 3));
    this->pioche.push_back(Carte("g", 3));
    //inialisation couleur violette
    this->pioche.push_back(Carte("p", 1));
    this->pioche.push_back(Carte("p", 2));
    this->pioche.push_back(Carte("p", 2));
    this->pioche.push_back(Carte("p", 2));
    this->pioche.push_back(Carte("p", 2));
    this->pioche.push_back(Carte("p", 2));
    this->pioche.push_back(Carte("p", 3));
    this->pioche.push_back(Carte("p", 3));
    //inialisation couleur neutre
    this->pioche.push_back(Carte("n", 4));
    this->pioche.push_back(Carte("n", 4));
    this->pioche.push_back(Carte("n", 5));
    this->pioche.push_back(Carte("n", 5));
    this->pioche.push_back(Carte("n", 5));
    this->pioche.push_back(Carte("n", 6));
    this->pioche.push_back(Carte("n", 6));
    this->pioche.push_back(Carte("n", 6));
    this->pioche.push_back(Carte("n", 6));
    this->pioche.push_back(Carte("n", 6));
    this->pioche.push_back(Carte("n", 7));
    this->pioche.push_back(Carte("n", 7));
}

Carte Pioche::piocher(){
    Carte c = this->pioche.front();
    this->pioche.erase(pioche.begin());
    return c;
}

void Pioche::defausse(Carte c){
    this->pioche.push_back(c);
}

void Pioche::melanger(){
    vector<Carte> pioche_bis;
    srand(time(NULL));

    int nbCartes = 52;
    while(nbCartes != 0){
        int num = rand() % nbCartes;
        pioche_bis.push_back(this->pioche.at(num));
        this->pioche.erase(this->pioche.begin()+num);
        nbCartes--;
    }
    this->pioche = pioche_bis;
}