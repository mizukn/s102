#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Avatar.h"
#include "Ennemi.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo", 8); // 8 FPS pour les animations

  // Charger les images
  Image fond;
  Image personnages;

  try {
    fond = Image(moteur, "assets/fond.png");
    personnages = Image(moteur, "assets/personnages.png");
  }
  catch (const runtime_error& e) {
    cerr << "Erreur lors du chargement des images :  " << e.what() << endl;
    return 1;
  }

  // Créer l'avatar (chevalier, skin en position 3,0)
  Avatar chevalier(personnages, 0, 0, BAS, 3, 0);

  // Créer les ennemis
  // Ennemi 1 :  squelette (skin 10,2), se déplace verticalement
  Ennemi ennemi1(personnages, TAILLE_CASE, 5 * TAILLE_CASE, HAUT, 10, 2);

  // Ennemi 2 : fantôme (skin 6,4), se déplace horizontalement
  Ennemi ennemi2(personnages, 5 * TAILLE_CASE, TAILLE_CASE, GAUCHE, 6, 4);

  bool quitter = false;

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        // QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
          quitter = true;
          break;

        // Déplacer l'avatar avec les flèches
        case GAUCHE_APPUYE:
          chevalier.allerGauche();
          break;

        case DROITE_APPUYE:
          chevalier.allerDroite();
          break;

        case HAUT_APPUYE:
          chevalier.allerHaut();
          break;

        case BAS_APPUYE:
          chevalier.allerBas();
          break;

        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    // Déplacer les ennemis seulement quand il faut mettre à jour les animations
    if (moteur.animationsAmettreAjour())
    {
      ennemi1.avancer();
      ennemi2.avancer();
    }

    // Vérifier si l'avatar touche un ennemi
    if (chevalier.touche(ennemi1) || chevalier.touche(ennemi2))
    {
      quitter = true; // Game over !
    }

    // III. Generation de l'image à afficher

    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    // Afficher le fond en premier (pour qu'il soit derrière tout le reste)
    fond.dessiner(0, 0);

    // Afficher les personnages
    chevalier.dessiner();
    ennemi1.dessiner();
    ennemi2.dessiner();

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();
  }

  return 0;
}
