#ifndef OBJET_H
#define OBJET_H

#include "Image.h"
#include "Tuile.h"
#include "Dictionnaire.h"

class Objet
{
private:
  Image _image;
  int _x;  // Coordonnées dans le niveau (où afficher)
  int _y;
  Tuile _tuile;  // Tuile utilisée pour représenter cet objet

public:
  // Constructeur
  Objet(const Image& image, const std::string& nom, Dictionnaire& dictionnaire, int x, int y);

  // Constructeur par défaut
  Objet();

  // Méthode pour dessiner l'objet
  void dessiner() const;

  // Méthode pour cacher l'objet (change la propriété à "cache")
  void cacher();

  // Accesseurs
  int getX() const;
  int getY() const;
  Tuile getTuile() const;
};

#endif // OBJET_H
