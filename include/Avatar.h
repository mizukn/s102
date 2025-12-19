#ifndef AVATAR_H
#define AVATAR_H

#include "Personnage.h"
#include "Ennemi.h"

// Forward declaration pour éviter les dépendances circulaires
class Ennemi;

class Avatar
{
private:
  Personnage _perso;

public:
  // Constructeur
  Avatar(Image& image, int x, int y, Direction direction, int skin_x, int skin_y);

  // Constructeur par défaut
  Avatar();

  // Méthode pour dessiner l'avatar
  void dessiner() const;

  // Méthodes pour déplacer l'avatar
  void allerDroite();
  void allerGauche();
  void allerHaut();
  void allerBas();

  // Méthode pour vérifier si l'avatar touche un ennemi
  bool touche(const Ennemi& ennemi) const;

  // Accesseur pour obtenir le personnage
  const Personnage& getPersonnage() const;
};

#endif // AVATAR_H
