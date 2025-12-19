#include "Ennemi.h"

// Constructeur par défaut
Ennemi::Ennemi()
{
}

// Constructeur
Ennemi:: Ennemi(Image& image, int x, int y, Direction direction, int skin_x, int skin_y)
  : _perso(image, x, y, direction, skin_x, skin_y)
{
}

// Dessiner l'ennemi
void Ennemi::dessiner() const
{
  _perso.dessiner();
}

// Faire avancer l'ennemi automatiquement
void Ennemi::avancer()
{
  Direction dir = _perso.getDirection();

  // Si l'ennemi ne peut pas bouger dans sa direction, inverser
  if (!_perso.peutBougerVers(dir))
  {
    _perso.inverserDirection();
    dir = _perso.getDirection();
  }

  // Avancer dans la direction courante
  switch (dir)
  {
    case DROITE:
      _perso. deplacer(TAILLE_CASE, 0);
      break;
    case GAUCHE:
      _perso.deplacer(-TAILLE_CASE, 0);
      break;
    case HAUT:
      _perso.deplacer(0, -TAILLE_CASE);
      break;
    case BAS:
      _perso.deplacer(0, TAILLE_CASE);
      break;
  }
}

// Accesseur pour obtenir le personnage
const Personnage& Ennemi:: getPersonnage() const
{
  return _perso;
}
