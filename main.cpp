#include <iostream>
#include "joueur.hpp"
#include "pioche.hpp"
#include "carte.hpp"
using namespace std;

int main() {
    int nb_joueur;
    int nb_joueur_ia;

    cout << "BIENVENUE SUR LE JEU DE LA TORTUE !" << endl;
    while((nb_joueur<2) || (nb_joueur>5))
      {
        cout << "Veuillez saisir le nombre de joueur:" << endl;
        cin >> nb_joueur;
        if(nb_joueur < 2 || nb_joueur > 5){
          cout << "Il y a trop peu ou trop de joueurs, min:2, max:5" << endl;
          exit(1);
        }
        else{
          nb_joueur_ia = 5 - nb_joueur;
        }
      }

    cout << "nombre de joueur: " << nb_joueur << endl;
    cout << "nombre de joueur IA: " << nb_joueur_ia << endl;
    Joueur player1("r");
    Joueur player2("b");
    Joueur player3("p");
    Joueur player4("y");
    Joueur player5("g");
    Pioche p;
    p.melanger();
    cout << p << endl;
}
