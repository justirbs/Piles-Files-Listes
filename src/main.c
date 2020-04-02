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
  int n; //le nombre d'élément de la liste1
  int i;

  liste = initListe();
  printf("\n\nCombien d'éléments contient la liste 1 ?\n");
  n=saisirEntier();
  printf("\n\nSaisie des éléments de la liste 1 :\n");
  for(i=0; i<n; i++){
    cons(liste, saisirEntier());
  }
  afficherListe(liste);
  printf("La somme des éléments de cette liste est %d\n", listSum(liste));
  printf("Le minimum des éléments de cette liste est %d\n", listMin(liste));
  printf("Quel nombre voulez vous supprimer ?\n");
  removeFirst(liste, saisirEntier());
  afficherListe(liste);
  printf("\n\nVoici sa liste mirroir :\n");
  listeInv = mirror(liste);
  afficherListe(listeInv);
  free(liste);
  free(listeInv);
  return(0);
}
