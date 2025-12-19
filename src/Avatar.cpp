#include "Avatar.h"

// Constructeur par défaut
Avatar::Avatar() : Personnage()
{
}

// Constructeur
Avatar:: Avatar(Image& image, int x, int y, Direction direction, int skin_x, int skin_y)
  : Personnage(image, x, y, direction, skin_x, skin_y)
{
}

// Aller à gauche
void Avatar::allerGauche(const Niveau& niveau)
{
  regarderGauche();
  if (peutBougerVers(GAUCHE, niveau))
  {
    deplacer(-TAILLE_CASE, 0);
  }
}

// Aller à droite
void Avatar::allerDroite(const Niveau& niveau)
{
  regarderDroite();
  if (peutBougerVers(DROITE, niveau))
  {
    deplacer(TAILLE_CASE, 0);
  }
}

// Aller en haut
void Avatar::allerHaut(const Niveau& niveau)
{
  regarderHaut();
  if (peutBougerVers(HAUT, niveau))
  {
    deplacer(0, -TAILLE_CASE);
  }
}

// Aller en bas
void Avatar::allerBas(const Niveau& niveau)
{
  regarderBas();
  if (peutBougerVers(BAS, niveau))
  {
    deplacer(0, TAILLE_CASE);
  }
}

// Tester si l'avatar touche un autre personnage
bool Avatar::touche(const Personnage& autre) const
{
  return (getX() == autre.getX() && getY() == autre.getY());
}
