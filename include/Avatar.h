#ifndef AVATAR_H
#define AVATAR_H

#include "Personnage.h"
#include "Niveau.h"

class Avatar :  public Personnage
{
public:
  // Constructeur
  Avatar(Image& image, int x, int y, Direction direction, int skin_x, int skin_y);

  // Constructeur par défaut
  Avatar();

  // Méthodes pour déplacer l'avatar avec les touches
  void allerGauche(const Niveau& niveau);
  void allerDroite(const Niveau& niveau);
  void allerHaut(const Niveau& niveau);
  void allerBas(const Niveau& niveau);

  // Méthode pour tester si l'avatar touche un autre personnage
  bool touche(const Personnage& autre) const;
};

#endif // AVATAR_H
