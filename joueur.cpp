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

Carte Joueur::retraitCarte(Carte c){
    return c;
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