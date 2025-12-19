#include "Dictionnaire.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructeur par défaut
Dictionnaire:: Dictionnaire()
{
}

// Constructeur qui charge le fichier
Dictionnaire:: Dictionnaire(const string& nomFichier)
{
  ifstream fichier(nomFichier);

  if (!fichier.is_open())
  {
    throw runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
  }

  int nbTuiles;
  fichier >> nbTuiles;

  for (int i = 0; i < nbTuiles; i++)
  {
    string nom, propriete;
    int x, y;

    fichier >> nom >> x >> y >> propriete;

    Tuile tuile(nom, x, y, propriete);
    _tuiles.push_back(tuile);
  }

  fichier. close();
}

// Afficher toutes les tuiles
void Dictionnaire::afficher() const
{
  for (size_t i = 0; i < _tuiles.size(); i++)
  {
    _tuiles[i].afficher();
  }
}

// Recherche dichotomique (binary search)
// Le fichier est trié par ordre alphabétique, on peut donc utiliser cet algorithme efficace
bool Dictionnaire::recherche(const string& nom, Tuile& resultat) const
{
  int gauche = 0;
  int droite = _tuiles.size() - 1;

  while (gauche <= droite)
  {
    int milieu = (gauche + droite) / 2;

    if (_tuiles[milieu].getNom() == nom)
    {
      // Trouvé !
      resultat = _tuiles[milieu];
      return true;
    }
    else if (_tuiles[milieu].getNom() < nom)
    {
      // Chercher dans la moitié droite
      gauche = milieu + 1;
    }
    else
    {
      // Chercher dans la moitié gauche
      droite = milieu - 1;
    }
  }

  // Pas trouvé
  return false;
}
