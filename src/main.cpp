#include <vector>
#include <ctime>   // Nécessaire pour time()
#include <cstdlib> // Nécessaire pour rand() et srand()

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Avatar.h"
#include "Ennemi.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**)
{
  // Initialisation du générateur de nombres aléatoires
  srand(time(0));

  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo", 8); // 8 FPS pour les animations

  // Charger les images
  Image personnages;
  Image objets;

  try {
    personnages = Image(moteur, "assets/personnages.png");
    objets = Image(moteur, "assets/objets.png");
  }
  catch (const runtime_error& e) {
    cerr << "Erreur lors du chargement des images : " << e.what() << endl;
    return 1;
  }

  // Charger le dictionnaire et le niveau
  Dictionnaire dictionnaire;
  Niveau niveau;

  try {
    dictionnaire = Dictionnaire("assets/dictionnaire.txt");
    niveau = Niveau(objets, "assets/niveau.txt", dictionnaire);
  }
  catch (const runtime_error& e) {
    cerr << "Erreur lors du chargement du niveau : " << e.what() << endl;
    return 1;
  }

  // Créer l'avatar (chevalier, skin en position 3,0)
  // Position initiale : (1, 2) en cases, soit (TAILLE_CASE, 2*TAILLE_CASE) en pixels
  Avatar chevalier(personnages, TAILLE_CASE, 2 * TAILLE_CASE, BAS, 3, 0);

  // Créer les ennemis
  Ennemi ennemi1(personnages, TAILLE_CASE, 5 * TAILLE_CASE, HAUT, 10, 0);
  Ennemi ennemi2(personnages, 5 * TAILLE_CASE, TAILLE_CASE, GAUCHE, 6, 4);

  bool quitter = false;

  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        case QUITTER_APPUYE:
          quitter = true;
          break;
        case GAUCHE_APPUYE:
          chevalier.allerGauche(niveau);
          // Tester si l'avatar a pris un bonus
          niveau.testerBonusEtPrendre(chevalier. getX(), chevalier.getY());
          break;
        case DROITE_APPUYE:
          chevalier. allerDroite(niveau);
          niveau.testerBonusEtPrendre(chevalier. getX(), chevalier.getY());
          break;
        case HAUT_APPUYE:
          chevalier. allerHaut(niveau);
          niveau.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
          break;
        case BAS_APPUYE:
          chevalier. allerBas(niveau);
          niveau.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
          break;
        default:
          break;
      }
      evenement = moteur. evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    // Déplacer les ennemis seulement quand il faut mettre à jour les animations
    if (moteur.animationsAmettreAjour())
    {
      ennemi1.avancer(niveau);
      ennemi2.avancer(niveau);
    }

    // Vérifier si l'avatar touche un ennemi
    if (chevalier.touche(ennemi1) || chevalier.touche(ennemi2))
    {
      cout << "Game Over !" << endl;
      quitter = true; // Game over !
    }

    // Vérifier si on a gagné
    if (niveau.gagne())
    {
      cout << "Bravo ! Vous avez gagné !" << endl;
      quitter = true;
    }

    // III. Generation de l'image à afficher

    moteur.initialiserRendu();

    // Afficher le niveau (avant les personnages)
    niveau.dessiner();

    // Afficher les personnages
    chevalier.dessiner();
    ennemi1.dessiner();
    ennemi2.dessiner();

    moteur.finaliserRendu();
  }

  return 0;
}
