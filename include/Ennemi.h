#ifndef ENNEMI_H
#define ENNEMI_H

#include "Personnage.h"
#include "Niveau.h"

class Ennemi :  public Personnage
{
public:
  // Constructeur
  Ennemi(Image& image, int x, int y, Direction direction, int skin_x, int skin_y);

  // Constructeur par défaut
  Ennemi();

  // Méthode pour faire avancer l'ennemi
  void avancer(const Niveau& niveau);
};

#endif // ENNEMI_H
