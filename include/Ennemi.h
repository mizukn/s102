#ifndef ENNEMI_H
#define ENNEMI_H

#include "Personnage.h"

class Ennemi
{
private:
  Personnage _perso;

public:
  // Constructeur
  Ennemi(Image& image, int x, int y, Direction direction, int skin_x, int skin_y);

  // Constructeur par défaut
  Ennemi();

  // Méthode pour dessiner l'ennemi
  void dessiner() const;

  // Méthode pour faire avancer l'ennemi automatiquement
  void avancer();

  // Accesseur pour obtenir le personnage
  const Personnage& getPersonnage() const;
};

#endif // ENNEMI_H
