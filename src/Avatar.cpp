#include "Avatar.h"
#include "Ennemi.h"

// Constructeur par défaut
Avatar::Avatar()
{
}

// Constructeur
Avatar::Avatar(Image& image, int x, int y, Direction direction, int skin_x, int skin_y)
  : _perso(image, x, y, direction, skin_x, skin_y)
{
}

// Dessiner l'avatar
void Avatar::dessiner() const
{
  _perso.dessiner();
}

// Aller à droite
void Avatar::allerDroite()
{
  _perso.regarderDroite();
  if (_perso.peutBougerVers(DROITE))
  {
    _perso.deplacer(TAILLE_CASE, 0);
  }
}

// Aller à gauche
void Avatar::allerGauche()
{
  _perso.regarderGauche();
  if (_perso.peutBougerVers(GAUCHE))
  {
    _perso. deplacer(-TAILLE_CASE, 0);
  }
}

// Aller en haut
void Avatar::allerHaut()
{
  _perso.regarderHaut();
  if (_perso.peutBougerVers(HAUT))
  {
    _perso.deplacer(0, -TAILLE_CASE);
  }
}

// Aller en bas
void Avatar::allerBas()
{
  _perso.regarderBas();
  if (_perso.peutBougerVers(BAS))
  {
    _perso.deplacer(0, TAILLE_CASE);
  }
}

// Vérifier si l'avatar touche un ennemi
bool Avatar::touche(const Ennemi& ennemi) const
{
  return _perso.getX() == ennemi.getPersonnage().getX() &&
         _perso.getY() == ennemi.getPersonnage().getY();
}

// Accesseur pour obtenir le personnage
const Personnage& Avatar::getPersonnage() const
{
  return _perso;
}
