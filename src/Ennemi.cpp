#include "Ennemi.h"

// Constructeur par défaut
Ennemi::Ennemi() : Personnage()
{
}

// Constructeur
Ennemi::Ennemi(Image& image, int x, int y, Direction direction, int skin_x, int skin_y)
  : Personnage(image, x, y, direction, skin_x, skin_y)
{
}

// Faire avancer l'ennemi
void Ennemi::avancer(const Niveau& niveau)
{
  // Si l'ennemi peut bouger dans sa direction actuelle
  if (peutBougerVers(getDirection(), niveau))
  {
    // Avancer dans la direction actuelle
    switch (getDirection())
    {
      case GAUCHE:
        deplacer(-TAILLE_CASE, 0);
        break;
      case DROITE:
        deplacer(TAILLE_CASE, 0);
        break;
      case HAUT:
        deplacer(0, -TAILLE_CASE);
        break;
      case BAS:
        deplacer(0, TAILLE_CASE);
        break;
    }
  }
  else
  {
    // Sinon, inverser la direction
    inverserDirection();
  }
}
