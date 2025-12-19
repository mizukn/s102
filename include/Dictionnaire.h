#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <vector>
#include <string>
#include "Tuile.h"

class Dictionnaire
{
private:
  std::vector<Tuile> _tuiles;

public:
  // Constructeur qui charge le fichier
  Dictionnaire(const std:: string& nomFichier);

  // Constructeur par défaut
  Dictionnaire();

  // Méthode pour afficher toutes les tuiles
  void afficher() const;

  // Méthode de recherche (recherche dichotomique)
  // Renvoie true si trouvé, false sinon
  // Le résultat est retourné par référence dans le paramètre resultat
  bool recherche(const std::string& nom, Tuile& resultat) const;
};

#endif // DICTIONNAIRE_H
