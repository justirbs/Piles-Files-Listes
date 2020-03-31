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
  s_liste* liste; //la liste
  int n; //le nombre d'élément de la liste
  int i;
  liste = initListe();
  printf("Combien d'éléments contient la liste ?\n");
  n=saisirEntier();
  for(i=0; i<n; i++){
    insertion(liste, saisirEntier());
  }
  afficherListe(liste);
  free(liste);
  return(0);
}
