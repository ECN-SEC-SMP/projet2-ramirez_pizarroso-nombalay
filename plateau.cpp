#include <iostream>
#include "carte.hpp"
#include "plateau.hpp"
using namespace std;

Plateau::Plateau(){
  this->plateauJeu[0][0] = "r";
  this->plateauJeu[0][1] = "g";
  this->plateauJeu[0][2] = "p";
  this->plateauJeu[0][3] = "y";
  this->plateauJeu[0][4] = "b";
}

void Plateau::gestion(Carte c)
{
  int action=c.getAction();  
  string couleur=c.getCouleur();
  if(couleur == "r")
  {
    if(action==1)
    {}
    if(action==2)
    {}
    if(action==3)
    {}
  }
  if(couleur == "y")
  {
    if(action==1)
    {}
    if(action==2)
    {}
    if(action==3)
    {}
  }
  if(couleur == "b")
  {
    if(action==1)
    {}
    if(action==2)
    {}
    if(action==3)
    {}
  }
  if(couleur == "g")
  {
    if(action==1)
    {}
    if(action==2)
    {}
    if(action==3)
    {}
  }
  if(couleur == "p")
  {
    if(action==1)
    {}
    if(action==2)
    {}
    if(action==3)
    {}
  }
  if(couleur == "n")
  {
    if(action==4)
    {}
    if(action==5)
    {}
    if(action==6)
    {}
    if(action==7)
    {}
  }
}

void Plateau::affichePlateau(){
  for(int i = 0; i < 10; i++){    //lignes
    for(int j = 0; j < 5; j++){    //colonnes
      if(plateauJeu[i][j] != "")
        cout << "[" << this->plateauJeu[i][j] << "]";
      else
        cout << "[ ]";
    }
    cout << endl;
  }
}