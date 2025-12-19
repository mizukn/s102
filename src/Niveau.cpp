#include "Niveau.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructeur par défaut
Niveau:: Niveau() : _nbBonus(0)
{
}

// Constructeur
Niveau::Niveau(const Image& image, const string& nomFichier, Dictionnaire& dictionnaire)
  : _nbBonus(0)
{
  ifstream fichier(nomFichier);

  if (!fichier.is_open())
  {
    throw runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
  }

  int nbObjets;
  fichier >> nbObjets;

  for (int i = 0; i < nbObjets; i++)
  {
    string nom;
    int x, y;

    fichier >> nom >> x >> y;

    // Convertir les coordonnées en pixels (multiplier par TAILLE_CASE)
    Objet objet(image, nom, dictionnaire, x * TAILLE_CASE, y * TAILLE_CASE);

    // Compter les bonus
    if (objet. getTuile().getPropriete() == "bonus")
    {
      _nbBonus++;
    }

    _objets.push_back(objet);
  }

  fichier.close();

  cout << "Niveau chargé :  " << nbObjets << " objets, " << _nbBonus << " bonus" << endl;
}

// Dessiner tous les objets
void Niveau::dessiner() const
{
  for (size_t i = 0; i < _objets.size(); i++)
  {
    // Ne pas dessiner les objets cachés
    if (_objets[i].getTuile().getPropriete() != "cache")
    {
      _objets[i].dessiner();
    }
  }
}

// Méthode privée pour factoriser le code
int Niveau::indiceObjet(int x, int y, const string& propriete) const
{
  for (size_t i = 0; i < _objets.size(); i++)
  {
    if (_objets[i].getTuile().getPropriete() == propriete &&
        _objets[i]. getX() == x &&
        _objets[i]. getY() == y)
    {
      return i;
    }
  }
  return -1;
}

// Vérifier si une case est libre
bool Niveau::caseEstLibre(int x, int y) const
{
  int indice = indiceObjet(x, y, "solide");
  return (indice == -1);  // Libre si aucun objet solide n'est trouvé
}

// Tester et prendre un bonus
void Niveau::testerBonusEtPrendre(int x, int y)
{
  int indice = indiceObjet(x, y, "bonus");

  if (indice != -1)
  {
    // Bonus trouvé !  On le cache et on décrémente le compteur
    _objets[indice].cacher();
    _nbBonus--;
    cout << "Bonus pris !  Reste : " << _nbBonus << endl;
  }
}

// Vérifier si on a gagné
bool Niveau:: gagne() const
{
  return (_nbBonus == 0);
}
