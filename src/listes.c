/*!
 * \file listes.c
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 31 mars 2020
 *
 * \brief code des méthodes relatives aux listes
 *
 *
 */

// Inclusion des entêtes de librairies
#include "listes.h"


// Code des méthodes

s_liste* initListe(void)
{
  s_liste* liste; //la liste créée
  liste = malloc(sizeof(s_liste));
  if (liste == NULL) {
      exit(EXIT_FAILURE);
  }
  liste->premier = NULL;
  return(liste);
}

void insertion(s_liste* liste, int nbr)
{
  s_element* nvElement; //le nouvel élément
  nvElement = malloc(sizeof(s_element));
  if (liste == NULL || nvElement == NULL) {
      exit(EXIT_FAILURE);
  }
  nvElement->valeur = nbr;
  nvElement->suivant = liste->premier;
  liste->premier = nvElement;
}

void afficherListe(s_liste* liste)
{
  s_element* actuel; //l'élément actuel
  if (liste == NULL) {
      exit(EXIT_FAILURE);
  }
  actuel = liste->premier;
  while (actuel != NULL)  {
    printf("%d -> ", actuel->valeur);
    actuel = actuel->suivant;
  }
  printf("fin\n");
}
