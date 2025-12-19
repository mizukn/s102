#include "Personnage.h"

// Constructeur par défaut
Personnage:: Personnage() : _x(0), _y(0), _direction(BAS), _skin_x(0), _skin_y(0)
{
}

// Constructeur
Personnage::Personnage(Image& image, int x, int y, Direction direction, int skin_x, int skin_y)
  : _image(image), _x(x), _y(y), _direction(direction), _skin_x(skin_x), _skin_y(skin_y)
{
}

// Dessiner le personnage
void Personnage::dessiner() const
{
  int sprite_x = _skin_x;
  int sprite_y = _skin_y;

  // Sélectionner le bon sprite selon la direction
  switch (_direction)
  {
    case BAS:
      sprite_y += 0;  // Ligne 0 relative au skin
      break;
    case GAUCHE:
      sprite_y += 1;  // Ligne 1 relative au skin
      break;
    case DROITE:
      sprite_y += 2;  // Ligne 2 relative au skin
      break;
    case HAUT:
      sprite_y += 3;  // Ligne 3 relative au skin
      break;
  }

  // Dessiner uniquement la partie de l'image correspondant au sprite
  _image.dessiner(_x, _y,
                  sprite_x * TAILLE_CASE, sprite_y * TAILLE_CASE,
                  TAILLE_CASE, TAILLE_CASE);
}

// Méthodes pour changer la direction
void Personnage::regarderDroite()
{
  _direction = DROITE;
}

void Personnage::regarderGauche()
{
  _direction = GAUCHE;
}

void Personnage::regarderHaut()
{
  _direction = HAUT;
}

void Personnage::regarderBas()
{
  _direction = BAS;
}

// Déplacer le personnage
void Personnage::deplacer(int dx, int dy)
{
  _x += dx;
  _y += dy;
}

// Vérifier si le personnage peut bouger dans une direction
bool Personnage::peutBougerVers(Direction dir) const
{
  switch (dir)
  {
    case GAUCHE:
      return _x > 0;
    case HAUT:
      return _y > 0;
    case DROITE:
      return _x + TAILLE_CASE < LARGEUR_FENETRE;
    case BAS:
      return _y + TAILLE_CASE < HAUTEUR_FENETRE;
  }
  return false;
}

// Inverser la direction
void Personnage::inverserDirection()
{
  switch (_direction)
  {
    case GAUCHE:
      _direction = DROITE;
      break;
    case DROITE:
      _direction = GAUCHE;
      break;
    case HAUT:
      _direction = BAS;
      break;
    case BAS:
      _direction = HAUT;
      break;
  }
}

// Accesseurs
int Personnage::getX() const
{
  return _x;
}

int Personnage::getY() const
{
  return _y;
}

Direction Personnage::getDirection() const
{
  return _direction;
}
