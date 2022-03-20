#include <iostream>
#include <vector>
#include <unistd.h>
#include "joueur.hpp"
#include "pioche.hpp"
#include "carte.hpp"
#include "plateau.hpp"
using namespace std;

#define NBR_JOUEUR_TOTAL    5

using std::cout;
using std::endl;

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

int main() {
    int nb_joueur;
    int nb_joueur_ia;
    bool win = false;
    int nb_tour = 0;
    int choixJoueur = 0;
    vector<string> couleur;
    string winner;
    int posLigne;
    int posColonne;
    /************
    Création des joueurs et attribution à chacun d'une couleur
    (red, blue, purple, yellow, green)
    ************/
    vector<Joueur> listejoueur;
    /************
    Création de la pioche
    ************/
    Pioche p;
    /**************
    Création du plateau de jeu
    ***************/
    Plateau jeu;
    /**************
    Carte tampon, qui va servir à stocker la carte jouée
    ou la carte à défausser
    ***************/
    Carte c;

    
    cout << endl << "BIENVENUE SUR LE JEU DE LA TORTUE !" << endl;
    /***************
    Demande du nombre de joueurs.
    On part du principe que on joue toujours à 5 joueurs, 
    si il n'y a pas 5 joueurs réels on complète par des IAs.
    ***************/
    while ((nb_joueur < 1) || (nb_joueur > NBR_JOUEUR_TOTAL)) {
        cout << endl << "Veuillez saisir le nombre de joueurs:  " << endl;
        cin >> nb_joueur;
        if (nb_joueur > NBR_JOUEUR_TOTAL) {
            cout << endl << "Veuillez rentrer un nombre de joueur inférieur à 6" << endl;
        }else if (nb_joueur < 1) {
            cout << endl << "Il faut au moins 1 joueur pour ce jeu" << endl;
        } else {    
            nb_joueur_ia = NBR_JOUEUR_TOTAL - nb_joueur;
            cout << endl << "Vous êtes " << nb_joueur << " joueur(s) humain et " 
            << nb_joueur_ia << " joueur(s) IA" << endl;
            sleep(1);
        }
    }
    /************
    création des joueurs et initialisation de leurs couleurs de leurs couleurs aléatoirement
    ************/
    couleur = Joueur::initCouleur(couleur);
    Joueur player1(couleur[0]);
    Joueur player2(couleur[1]);
    Joueur player3(couleur[2]);
    Joueur player4(couleur[3]);
    Joueur player5(couleur[4]);
    /************
    Remplissage du vecteur de joueur
    ************/
    listejoueur.push_back(player1);
    listejoueur.push_back(player2);
    listejoueur.push_back(player3);
    listejoueur.push_back(player4);
    listejoueur.push_back(player5);
    /************
    Attribution du type IA ou humain en fonnction
    de la configuration de la partie décidée par les joueurs
    ************/
    for (int i = 0; i < nb_joueur; i++) {
        listejoueur[i].setType("humain");
    }
    for (int i = nb_joueur; i < NBR_JOUEUR_TOTAL; i++) {
        listejoueur[i].setType("IA");
    }
    /************
    Annonce à chaque joueur de sa couleur
    ************/
    cout << endl << "Annonce des couleurs, chaque joueur regarde sa couleur" << endl;
    cout << endl << "NE PAS REGARDER CELLE DES AUTRES !" << endl;
    sleep (2);
    Clear();
    for (int i = 0; i< nb_joueur; i++) {
        cout << endl << "JOUEUR " << i+1 << " | COULEUR: " <<         
        Joueur::getVraiCouleur(listejoueur[i].getCouleurTortue()) << endl;
        sleep(2);
        Clear();
    }
    /**************
    mélange de la pioche
    **************/
    p.melanger();
    /**************
    Chaque joueur pioche 5 cartes
    **************/
    for(int i = 0; i < NBR_JOUEUR_TOTAL; i++) {
        for(int y = 0; y < NB_CARTE_JOUEUR; y++) {    
            listejoueur[i].ajoutCarte(p.piocher());
        }
    }
    cout << endl << "QUE LE JEU COMMENCE !" << endl << endl;
    cout << endl << "Voici le plateau:" << endl;
    jeu.affichePlateau();
    //boucle principale du jeu, active tant qu'il n'y a pas un gagnant
    while (win == false) {
        nb_tour++;
        //on fait jouer chaque joueur tour à tour
        for (int i = 0; i < NBR_JOUEUR_TOTAL; i++ ) {
            if (win == true) continue;
            sleep(1);
            cout << endl << "[ TOUR N°" << nb_tour << " ]" << endl;
            cout << endl << "LES AUTRES JOUEUR NE DOIVENT PAS REGARDER !" << endl;
            cout << endl << "JOUEUR " << i+1 << ", C'EST A TON TOUR !" << endl;
            sleep(2);
            if (listejoueur[i].getType() == "humain") {
                // on affiche ses cartes au joueur si il est humain
                cout << endl << "Tu as les cartes suivantes: " << endl;                         
                listejoueur[i].afficherCarte();
                cout << endl << "Quelle carte comptes tu jouer ?" << endl;
            }
            // on recherce la position de la tortue(gestion de l'IA)
            jeu.rechercherTortue(listejoueur[i].getCouleurTortue(), &posLigne, &posColonne);
            c = listejoueur[i].jouerCarte(posLigne);
            Clear();
            //On joue la carte choisie
            if (jeu.gestion(c, listejoueur[i]) == true) {
                win = true;
                winner = jeu.getWinner();
            }
            //defausser la carte
            listejoueur[i].retraitCarte(c);
            p.defausse(c);
            // repiocher une carte
            c = p.piocher();
            listejoueur[i].ajoutCarte(c);
            //fin de tour
            cout << endl << "Le joueur " << i+1 << " à jouer sa carte" << endl;
            sleep(1);
            cout << "il est défaussé de celle ci et pioche une autre carte" << endl;
            sleep(1);
            cout << endl << "Voici le plateau:" << endl;
            jeu.affichePlateau();
        }
        cout << endl << "TOUR SUIVANT" << endl;
    }
    cout << endl << "FIN DE PARTIE" << endl;
    cout << endl << "VICTOIRE DE LA TORTUE " << winner << "!!!" << endl;
    return 0;
}