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


/*Initialiser une liste */
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


/*Ajouter un noeud en début de liste*/
void cons(s_liste* liste, int nbr)
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


/*Ajouter un noeud en fin de liste*/
void rcons(s_liste* liste, int nbr)
{
  s_element* nvElement; //le nouvel élément
  s_element* actuel; //l'élément actuel
  nvElement = malloc(sizeof(s_element));
  if (liste == NULL || nvElement == NULL) {
      exit(EXIT_FAILURE);
  }
  nvElement->suivant = NULL;
  nvElement->valeur = nbr;
  if (liste->premier != NULL){
    actuel = liste->premier;
    while(actuel->suivant != NULL) {
      actuel = actuel->suivant;
    }
    actuel->suivant = nvElement;
  } else {
    liste->premier = nvElement;
  }
}


/*Ajouter un élément à une position donnée*/
void ajouter(s_liste* liste, int nbr, int position)
{
  s_element* nvElement; //le nouvel élément
  s_element* actuel; //l'élément actuel
  s_element* suivant; //l'élément suivant
  int i;
  nvElement = malloc(sizeof(s_element));
  if (liste == NULL || nvElement == NULL) {
      exit(EXIT_FAILURE);
  }
  nvElement->valeur = nbr;
  if (position == 0){
    nvElement = liste->premier;
  } else {
    i = 0;
    actuel = liste->premier;
    suivant = actuel->suivant;
    while (i < position-1) {
      i++;
      actuel = actuel->suivant;
      suivant = suivant->suivant;
    }
    actuel->suivant = nvElement;
    nvElement->suivant = suivant;
  }
}


/*Afficher une liste*/
void afficherListe(s_liste* liste)
{
  s_element* actuel; //l'élément actuel
  if (liste == NULL) {
      exit(EXIT_FAILURE);
  }
  printf("\nVoici votre liste : \n");
  actuel = liste->premier;
  while (actuel != NULL)  {
    printf("%d -> ", actuel->valeur);
    actuel = actuel->suivant;
  }
  printf("fin\n");
}


/*Renvoie la somme de la liste*/
int listSum(s_liste* liste)
{
  int somme; //la somme des éléments
  s_element* actuel; //l'élément actuel
  somme = 0;
  actuel = liste->premier;
  while (actuel != NULL) {
    somme = somme + actuel->valeur;
    actuel = actuel->suivant;
  }
  return(somme);
}


/*Renvoie le minimum de la liste*/
int listMin(s_liste* liste)
{
  int min; //le minimum de la liste
  s_element* actuel; //l'élément actuel
  if (liste == NULL) {
    min = 0;
  } else {
    actuel = liste->premier;
    min = actuel->valeur;
    while (actuel != NULL) {
      if (actuel->valeur < min){
        min = actuel->valeur;
      }
      actuel = actuel->suivant;
    }
  }
  return(min);
}


/*Vérifie si deux listes sont égales*/
int isEqual(s_liste* liste1, int n1, s_liste* liste2, int n2)
{
  s_element* actuel1; //l'élément actuel de liste1
  s_element* actuel2; //l'élément actuel de liste2
  int estIdentique; //variable booléenne pour vérifier si les deux listes sont égales
  if (n1 != n2) {
    estIdentique = 0;
  } else {
    estIdentique = 1;
    actuel1 = liste1->premier;
    actuel2 = liste2->premier;
    while (actuel1 != NULL) {
      if (actuel1->valeur != actuel2->valeur){
        estIdentique = 0;
      }
      actuel1 = actuel1->suivant;
      actuel2 = actuel2->suivant;
    }
  }
  return(estIdentique);
}


/*Supprime la première occurence d'une valeur*/
void removeFirst(s_liste* liste, int nbr)
{
  s_element* actuel; //l'élément actuel
  s_element* suivant; //l'élément suivant
  if (liste == NULL) {
      exit(EXIT_FAILURE);
  }
  actuel = liste->premier;
  if (actuel->valeur == nbr){
    liste->premier = actuel->suivant;
  } else {
    suivant = actuel->suivant;
    while (suivant->valeur != nbr){
      actuel = suivant;
      suivant = suivant->suivant;
    }
    actuel->suivant = suivant->suivant;
    free(suivant);
  }
}


/*Renvoie la liste inverse*/
s_liste* mirror(s_liste* liste)
{
  s_liste* listeInv; //liste inverse
  s_element* actuel; //l'élément actuel
  listeInv = initListe();
  actuel = liste->premier;
  while (actuel != NULL) {
    cons(listeInv, actuel->valeur);
    actuel = actuel->suivant;
  }
  return(listeInv);
}


/*Supprime l'élément en tête de liste*/
void suppDeb(s_liste* liste)
{
  s_element* actuel; //l'élément actuel
  if (liste->premier == NULL) {
    exit(EXIT_FAILURE);
  }
  actuel = liste->premier;
  liste->premier = actuel->suivant;
  free(actuel);
}


/*Supprime l'élément en fin de liste*/
void suppFin(s_liste* liste)
{
  s_element* actuel; //l'élément actuel
  s_element* suivant; //l'élément suivant
  if (liste->premier == NULL) {
    exit(EXIT_FAILURE);
  }
  actuel =liste->premier;
  if(actuel->suivant == NULL){
    suppDeb(liste);
  } else {
    suivant = actuel->suivant;
    while (suivant->suivant != NULL) {
      actuel = actuel->suivant;
      suivant = suivant->suivant;
    }
    free(suivant);
    actuel->suivant = NULL;
  }
}


/*Supprime l'élément à une position donnée*/
void supprimer(s_liste* liste, int indice)
{
  s_element* actuel; //l'élément actuel
  s_element* suivant; //l'élément suivant
  int i;
  if (liste == NULL ) {
      exit(EXIT_FAILURE);
  }
  if (indice == 0){
    suppDeb(liste);
  } else {
    actuel = liste->premier;
    suivant = actuel->suivant;
    i=0;
    while (i < indice-1){
      actuel = suivant;
      suivant = suivant->suivant;
      i++;
    }
    actuel->suivant = suivant->suivant;
    free(suivant);
  }
}
