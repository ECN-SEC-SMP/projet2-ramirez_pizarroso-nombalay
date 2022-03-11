#include <iostream>
#include "carte.hpp"
#include "plateau.hpp"
using namespace std;

Plateau::Plateau()
{
  //RAND_MAX = 4;
  //randCouleur = rand();
  
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