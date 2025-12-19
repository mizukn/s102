#ifndef TUILE_H
#define TUILE_H

#include <string>

class Tuile
{
private:
  std::string _nom;
  int _x;
  int _y;
  std::string _propriete;

public:
  // Constructeur
  Tuile(const std::string& nom, int x, int y, const std::string& propriete);

  // Constructeur par défaut
  Tuile();

  // Méthode pour afficher les attributs
  void afficher() const;

  // Accesseurs
  std::string getNom() const;
  int getX() const;
  int getY() const;
  std::string getPropriete() const;

  // Modificateur
  void setPropriete(const std::string& propriete);
};

#endif // TUILE_H
