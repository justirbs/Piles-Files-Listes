/*!
 * \file main.c
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 31 mars 2020
 *
 * \brief fonction principale
 *
 *
 */

// Inclusion des entêtes de librairies
#include "saisie.h"
#include "listes.h"

// Fonction principale
int main (void)
{
  s_liste* liste;
  s_liste* listeInv;
  int action; //action choisie par l'utilisateur
  int choix; //le choix parmi les différentes actions
  int nbr;
  int position;
  int taille;
  liste = initListe();
  taille = 0;
  do {
    printf("\nQue voulez-vous faire ?\n1-Ajouter un élément dans la liste\n2-Supprimer un élément de la liste\n3-Rechercher un élément de la liste\n4-Quitter le programme\n\n\n");
    action = saisirEntier();
    switch (action) {

      /*Ajout d'un élément*/
      case 1 : printf("\nQuel élément voulez-vous insérer ?\n");
      nbr = saisirEntier();
      printf("L'élément sera inséré :\n1-En tête de liste\n2-En fin de liste\n3-A une position donnée de la liste\n");
      choix = saisirEntier();
      switch (choix) {
        /*En tête*/
        case 1 : cons(liste, nbr);
        afficherListe(liste);
        taille++;
        break;
        /*A la fin*/
        case 2 : rcons(liste, nbr);
        afficherListe(liste);
        taille++;
        break;
        /*Position donnée*/
        case 3 : printf("\nA quelle position voulez vous ajouter cet élément ?\n");
        do {
          position = saisirEntier();
        } while (position < 0  &&  position > taille);
        ajouter(liste, nbr, position);
        afficherListe(liste);
        taille++;
        break;
        default : printf("erreur\n");
      }
      break;

      /*Suppression d'un élément*/
      case 2 : printf("\nOù voulez-vous supprimer un élément ?\n1-En tête de liste\n2-En fin de liste\n3-A une position donnée\n");
      choix = saisirEntier();
      switch (choix) {
        /*En tête*/
        case 1 : suppDeb(liste);
        afficherListe(liste);
        taille--;
        break;
        /*En fin*/
        case 2 : suppFin(liste);
        afficherListe(liste);
        taille--;
        break;
        /*A une position donnée*/
        case 3 : printf("\nA quelle position voulez vous supprimer élément ?\n");
        do {
          position = saisirEntier();
        } while (position < 0  &&  position > taille-1);
        supprimer(liste, position);
        afficherListe(liste);
        taille--;
        break;
      }

      /*Recherche d'un élément*/
      break;
    }
  } while (action != 4);
  free(liste);
  return(0);
}
