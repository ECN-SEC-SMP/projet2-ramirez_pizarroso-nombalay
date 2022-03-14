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
    this->pioche.push_back(Carte("R", 1));
    this->pioche.push_back(Carte("R", 2));
    this->pioche.push_back(Carte("R", 2));
    this->pioche.push_back(Carte("R", 2));
    this->pioche.push_back(Carte("R", 2));
    this->pioche.push_back(Carte("R", 2));
    this->pioche.push_back(Carte("R", 3));
    this->pioche.push_back(Carte("R", 3));
    //inialisation couleur jaune
    this->pioche.push_back(Carte("Y", 1));
    this->pioche.push_back(Carte("Y", 2));
    this->pioche.push_back(Carte("Y", 2));
    this->pioche.push_back(Carte("Y", 2));
    this->pioche.push_back(Carte("Y", 2));
    this->pioche.push_back(Carte("Y", 2));
    this->pioche.push_back(Carte("Y", 3));
    this->pioche.push_back(Carte("Y", 3));
    //inialisation couleur bleue
    this->pioche.push_back(Carte("B", 1));
    this->pioche.push_back(Carte("B", 2));
    this->pioche.push_back(Carte("B", 2));
    this->pioche.push_back(Carte("B", 2));
    this->pioche.push_back(Carte("B", 2));
    this->pioche.push_back(Carte("B", 2));
    this->pioche.push_back(Carte("B", 3));
    this->pioche.push_back(Carte("B", 3));
    //inialisation couleur verte
    this->pioche.push_back(Carte("G", 1));
    this->pioche.push_back(Carte("G", 2));
    this->pioche.push_back(Carte("G", 2));
    this->pioche.push_back(Carte("G", 2));
    this->pioche.push_back(Carte("G", 2));
    this->pioche.push_back(Carte("G", 2));
    this->pioche.push_back(Carte("G", 3));
    this->pioche.push_back(Carte("G", 3));
    //inialisation couleur violette
    this->pioche.push_back(Carte("P", 1));
    this->pioche.push_back(Carte("P", 2));
    this->pioche.push_back(Carte("P", 2));
    this->pioche.push_back(Carte("P", 2));
    this->pioche.push_back(Carte("P", 2));
    this->pioche.push_back(Carte("P", 2));
    this->pioche.push_back(Carte("P", 3));
    this->pioche.push_back(Carte("P", 3));
    //inialisation couleur neutre
    this->pioche.push_back(Carte("N", 4));
    this->pioche.push_back(Carte("N", 4));
    this->pioche.push_back(Carte("N", 5));
    this->pioche.push_back(Carte("N", 5));
    this->pioche.push_back(Carte("N", 5));
    this->pioche.push_back(Carte("N", 6));
    this->pioche.push_back(Carte("N", 6));
    this->pioche.push_back(Carte("N", 6));
    this->pioche.push_back(Carte("N", 6));
    this->pioche.push_back(Carte("N", 6));
    this->pioche.push_back(Carte("N", 7));
    this->pioche.push_back(Carte("N", 7));
}


// SENS DU PIOCHAGE ET DEFAUSSAGE ?


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

vector<Carte> Pioche::getPioche(){
    return this->pioche;
}

std::ostream& operator<<(std::ostream &o, Pioche &p){
    vector<Carte> cartes = p.getPioche();

    for(vector<Carte>::iterator it = cartes.begin(); it != cartes.end(); it++){
        o << "Couleur carte : " << it->getCouleur() << ", ID action carte: " << it->getAction() << endl;
    }
    o << "Taille pioche: " << cartes.size() << endl;
    return o;
}
