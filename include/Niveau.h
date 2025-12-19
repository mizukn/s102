#ifndef NIVEAU_H
#define NIVEAU_H

#include <vector>
#include <string>
#include "Objet.h"
#include "Image.h"
#include "Dictionnaire.h"

class Niveau
{
private:
  std::vector<Objet> _objets;
  int _nbBonus;  // Nombre de bonus restants

  // Méthode privée pour factoriser le code (optionnel)
  // Renvoie l'indice de l'objet avec la propriété donnée aux coordonnées x, y
  // Renvoie -1 si aucun objet ne correspond
  int indiceObjet(int x, int y, const std::string& propriete) const;

public:
  // Constructeur
  Niveau(const Image& image, const std::string& nomFichier, Dictionnaire& dictionnaire);

  // Constructeur par défaut
  Niveau();

  // Méthode pour dessiner tous les objets du niveau
  void dessiner() const;

  // Méthode pour vérifier si une case est libre (pas d'objet solide)
  bool caseEstLibre(int x, int y) const;

  // Méthode pour tester si un bonus est présent et le prendre
  void testerBonusEtPrendre(int x, int y);

  // Méthode pour vérifier si on a gagné (tous les bonus collectés)
  bool gagne() const;
};

#endif // NIVEAU_H
