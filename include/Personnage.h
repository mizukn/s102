#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Moteur.h"
#include "Image.h"

// Forward declaration to avoid circular dependency
class Niveau;

// Énumération pour les directions
enum Direction {
  GAUCHE,
  DROITE,
  HAUT,
  BAS
};

class Personnage
{
private:
  Image _image;
  int _x;
  int _y;
  Direction _direction;
  int _skin_x;
  int _skin_y;

public:
  // Constructeur
  Personnage(Image& image, int x, int y, Direction direction, int skin_x, int skin_y);

  // Constructeur par défaut
  Personnage();

  // Méthode pour dessiner le personnage
  void dessiner() const;

  // Méthodes pour changer la direction
  void regarderDroite();
  void regarderGauche();
  void regarderHaut();
  void regarderBas();

  // Méthode pour déplacer le personnage
  void deplacer(int dx, int dy);

  // Méthode pour vérifier si le personnage peut bouger dans une direction
  bool peutBougerVers(Direction dir, const Niveau& niveau) const;

  // Méthode pour inverser la direction
  void inverserDirection();

  // Accesseurs
  int getX() const;
  int getY() const;
  Direction getDirection() const;
};

#endif // PERSONNAGE_H
