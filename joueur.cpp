#include <algorithm>
#include "joueur.hpp"

Joueur::Joueur()
{
}

Joueur::Joueur(string couleur){
    this->couleurTortue = couleur;
}

string Joueur::getCouleurTortue(){
    return this->couleurTortue;
}

void Joueur::ajoutCarte(Carte c){
    main.push_back(c);
}

void Joueur::retraitCarte(Carte c){
  for(int i = 0; i < this->main.size(); i++){
    if(this->main[i] == c){
      this->main.erase(this->main.begin()+i);
    }
  }
}

vector<Carte> Joueur::getCarte(){
    vector<Carte> c;
    for(vector<Carte>::iterator it = this->main.begin(); it != this->main.end(); it++ ){
        c.push_back(*it);
    }
    return c;
}

void Joueur::afficherCarte() 
{
    vector<Carte> main;
    string action_reelle;
    string couleur_reelle;
    int action;
    string couleur;
    
    main = this->getCarte();
    for (int i = 0; i < NB_CARTE_JOUEUR; i++){
        action = main[i].getAction();
        couleur = main[i].getCouleur();
        if (action == 1) action_reelle = "++";
        if (action == 2) action_reelle = "+";
        if (action == 3) action_reelle = "-";
        if (action == 4) action_reelle = "=>=>";
        if (action == 5) action_reelle = "=>";
        if (action == 6) action_reelle = "+";
        if (action == 7) action_reelle = "-";
        couleur_reelle = Joueur::getVraiCouleur(couleur);
        cout << endl << "CARTE: " << i+1 << " | COULEUR: " << couleur_reelle <<
        " | ACTION: " << action_reelle << endl;
    }
}

void Joueur::setType(string type)
{
    if(type == "humain" || type == "IA") {
        this->type = type;
    } else {
        cout << "mauvais type" << endl;   
    }
}

string Joueur::getType()
{
    return this->type;
}

Carte Joueur::jouerCarte(int position)
{
    int choixJoueur = 0;
    
    if (this->getType() == "humain") {
        cin >> choixJoueur;
        while (choixJoueur < 1 || choixJoueur > NB_CARTE_JOUEUR) {
            cout << endl << "Tu dois choisir un chiffre entre 1 et 5 !" << endl;
            cout << endl << "Quelle carte comptes tu jouer ?" << endl;
            cin >> choixJoueur;
            return this->getCarte()[choixJoueur - 1];
        }
        return this->getCarte()[choixJoueur - 1];
    } else if (this->getType() == "IA") {
        sleep(1);
        //Gestion de l'intelligence IA
        // On check d'abord si la tortue gérée par l'IA
        //est dans les deux dernières cases avant l'arrivée
        if (position == 7 || position == 8){
            //On check si il a une carte de sa couleur
            for(int i = 0; i<NB_CARTE_JOUEUR; i++) {
                if (this->getCarte()[i].getCouleur() == this->getCouleurTortue()) {
                    //Si on trouve une carte de cette couleur, alors on la joue
                    return this->getCarte()[i];
                }
            }
            for(int i = 0; i<NB_CARTE_JOUEUR; i++) {  
                //Sinon on check si il possède une carte neutre qui fait avancer                    les tortues
                if (this->getCarte()[i].getCouleur() == "N") {
                    if(this->getCarte()[i].getAction() == 6) {
                        return this->getCarte()[i];
                    } 
                }
            }
            //sinon on randomise sur sa main
            choixJoueur = rand() % NB_CARTE_JOUEUR;
            return this->getCarte()[choixJoueur];
        //Si le joueur IA n'est pas dans les deux dernières cases avant la fin
        } else {
            //Il regarde si il a une carte de sa couleur et il joue
            for(int i = 0; i<NB_CARTE_JOUEUR; i++) {
                if (this->getCarte()[i].getCouleur() == this->getCouleurTortue()) {
                    //Si on trouve une carte de cette couleur, alors on la joue
                    return this->getCarte()[i];
                }
            }
            //sinon on randomise sur sa main
            choixJoueur = rand() % NB_CARTE_JOUEUR;
            return this->getCarte()[choixJoueur];
        }
    }
}

vector<string> Joueur::initCouleur(vector<string> couleur)
{
    vector<string> melange_couleur;
    int choix;
    srand(time(NULL));

    couleur.push_back("Y");
    couleur.push_back("R");
    couleur.push_back("B");
    couleur.push_back("G");
    couleur.push_back("P");
    while(couleur.size() != 0) {
        choix = rand() % (couleur.size());
        melange_couleur.push_back(couleur.at(choix));
        couleur.erase(couleur.begin()+choix);
    } 
    couleur = melange_couleur;
    return couleur;
}

string Joueur::getVraiCouleur(string couleur) 
{
    string couleur_reelle;
    
    if (couleur == "N") couleur_reelle = "NEUTRE";
    if (couleur == "Y") couleur_reelle = "JAUNE";
    if (couleur == "R") couleur_reelle = "ROUGE";
    if (couleur == "B") couleur_reelle = "BLEU";
    if (couleur == "G") couleur_reelle = "VERT";
    if (couleur == "P") couleur_reelle = "VIOLET";
    return couleur_reelle;
}

