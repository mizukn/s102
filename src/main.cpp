#include <vector>

#include "Moteur.h"
#include "Image.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo");

  // Charger les images
  Image fond;
  Image coffreFerme;
  Image coffreOuvert;
  
  try {
    fond = Image(moteur, "assets/fond.png");
    coffreFerme = Image(moteur, "assets/coffre_ferme.png");
    coffreOuvert = Image(moteur, "assets/coffre_ouvert.png");
  }
  catch (const runtime_error& e) {
    cerr << "Erreur lors du chargement des images : " << e.what() << endl;
    return 1;
  }

  bool quitter = false;
  bool coffreEstOuvert = false; // État du coffre

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
        
        // Gérer l'ouverture du coffre avec la barre d'espace
        case ESPACE_APPUYE: 
          coffreEstOuvert = true;
          break;
        
        // Gérer la fermeture du coffre quand on relâche la barre d'espace
        case ESPACE_RELACHE:
          coffreEstOuvert = false;
          break;
        
        default:
          break;
      }

      evenement = moteur. evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    // TODO: faire bouger vos personnages, etc.

    // III.  Generation de l'image à afficher

    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    // Afficher le fond en premier (pour qu'il soit derrière tout le reste)
    fond.dessiner(0, 0);
    
    // Afficher le coffre selon son état
    if (coffreEstOuvert) {
      coffreOuvert.dessiner(0, 0);
    } else {
      coffreFerme.dessiner(0, 0);
    }

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur. finaliserRendu();
  }

  return 0;
}
