#include "Tuile.h"
#include <iostream>

using namespace std;

// Constructeur par défaut
Tuile:: Tuile() : _nom(""), _x(0), _y(0), _propriete("")
{
}

// Constructeur
Tuile::Tuile(const string& nom, int x, int y, const string& propriete)
  : _nom(nom), _x(x), _y(y), _propriete(propriete)
{
}

// Afficher les attributs
void Tuile::afficher() const
{
  cout << _nom << ": x=" << _x << ", y=" << _y << ", " << _propriete << endl;
}

// Accesseurs
string Tuile::getNom() const
{
  return _nom;
}

int Tuile:: getX() const
{
  return _x;
}

int Tuile::getY() const
{
  return _y;
}

string Tuile:: getPropriete() const
{
  return _propriete;
}

// Modificateur
void Tuile::setPropriete(const string& propriete)
{
  _propriete = propriete;
}
