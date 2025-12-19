#include "Objet.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructeur par défaut
Objet:: Objet() : _x(0), _y(0)
{
}

// Constructeur
Objet::Objet(const Image& image, const string& nom, Dictionnaire& dictionnaire, int x, int y)
  : _image(image), _x(x), _y(y)
{
  // Rechercher la tuile dans le dictionnaire
  if (! dictionnaire.recherche(nom, _tuile))
  {
    throw runtime_error("Objet non trouvé dans le dictionnaire :  " + nom);
  }
}

// Dessiner l'objet
void Objet:: dessiner() const
{
  // Dessiner la tuile aux coordonnées de l'objet
  // _tuile.getX() et _tuile.getY() sont les coordonnées dans la feuille de sprites
  // _x et _y sont les coordonnées à l'écran
  _image.dessiner(_x, _y,
                  _tuile.getX() * TAILLE_CASE, _tuile.getY() * TAILLE_CASE,
                  TAILLE_CASE, TAILLE_CASE);
}

// Cacher l'objet
void Objet::cacher()
{
  _tuile.setPropriete("cache");
}

// Accesseurs
int Objet::getX() const
{
  return _x;
}

int Objet::getY() const
{
  return _y;
}

Tuile Objet::getTuile() const
{
  return _tuile;
}
