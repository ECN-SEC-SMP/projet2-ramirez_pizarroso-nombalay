#include <iostream>
#include "joueur.hpp"
#include "pioche.hpp"
#include "carte.hpp"
#include "plateau.hpp"
using namespace std;

int main() {
  int nb_joueur;
  int nb_joueur_ia;

  cout << "BIENVENUE SUR LE JEU DE LA TORTUE !" << endl;

  /***************
  Partie sur la demande du nombre de joueurs.
  On part du principe que on joue toujours à 5 joueurs, si il n'y a pas 5 joueurs réels on complète par des IAs.
  ***************/
  while((nb_joueur<2) || (nb_joueur>5))
  {
    cout << endl;
    cout << "Veuillez saisir le nombre de joueur:  ";
    cin >> nb_joueur;
    if(nb_joueur < 2 || nb_joueur > 5){
      cout << "Il y a trop peu ou trop de joueurs, min:2, max:5" << endl;
    }
    else{
      nb_joueur_ia = 5 - nb_joueur;
    }
  }
  
  cout << endl;

  /************
  Création des joueurs et attribution à chacun d'une couleur
  (red, blue, purple, yellow, green)
  ************/
  Joueur player1("r");
  Joueur player2("b");
  Joueur player3("p");
  Joueur player4("y");
  Joueur player5("g");
  
  /**************
  Création et mélange de la pioche
  **************/
  Pioche p;
  p.melanger();
  //cout << p << endl;
  
  /**************
  Création du plateau de jeu et positionnement de tous les joueurs sur la première case
  ***************/
  Plateau jeu;
  //jeu.affichePlateau();

  /**************
  Chaque joueur pioche 5 cartes
  **************/
  for(int i = 0; i < 5; i++) player1.ajoutCarte(p.piocher());
  for(int i = 0; i < 5; i++) player2.ajoutCarte(p.piocher());
  for(int i = 0; i < 5; i++) player3.ajoutCarte(p.piocher());
  for(int i = 0; i < 5; i++) player4.ajoutCarte(p.piocher());
  for(int i = 0; i < 5; i++) player5.ajoutCarte(p.piocher()); 
}
