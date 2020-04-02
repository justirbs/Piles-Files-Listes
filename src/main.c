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
  int nbr;
  int position;
  liste = initListe();
  do {
    printf("Que voulez-vous faire ?\n1-Ajouter un élément dans la liste\n2-Supprimer un élément de la liste\n3-Rechercher un élément de la liste\n4-Quitter le programme\n\n\n");
    do {
      action = saisirEntier();
    } while (action != 1 && action != 2 && action != 3 && action != 4);
    switch (action) {
      case 1 : printf("Quel élément voulez-vous insérer ?\n");
      nbr = saisirEntier();
      printf("L'élément sera inséré :\n1-En tête de liste\n2-En fin de liste\n3-A une position donnée de la liste\n");
      do {
        action = saisirEntier();
      } while (action != 1 && action != 2 && action != 3);
      switch (action) {
        case 1 : cons(liste, nbr);
        afficherListe(liste);
        break;
        case 2 : rcons(liste, nbr);
        afficherListe(liste);
        break;
        case 3 : printf("A quelle position voulez vous ajouter cet élément ?\n");
        do {
          position = saisirEntier();
        } while (position < 0);
        ajouter(liste, nbr, position);
        afficherListe(liste);
        break;
        default : printf("erreur\n");
      }
    }
  } while (action != 4);
  free(liste);
  return(0);
}
