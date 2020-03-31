/*!
 * \file listes.h
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 31 mars 2020
 *
 * \brief définition des méthodes relatives aux listes
 *
 *
 */

 #ifndef __LISTES_H__
 #define __LISTES_H__

// Inclusion des entêtes de librairies
#include "saisie.h"

// Déclaration des structures

/*! \struct s_element
 * Structure qui défini chaque élément de la liste associé au pointeur de l'élément suivant
 */
typedef struct s_element s_element;
struct s_element
{
	int valeur; /*!< la valeur l'élément de la liste */
	s_element* suivant; /*!< le pointeur vers l'élément suivant */
};

/*! \struct s_liste
 * Structure qui défini une liste avec les pointeurs des éléments
 */
typedef struct
{
	s_element* premier; /*!< le pointeur de l'élément de la liste */
} s_liste;


// Déclaration des méthodes

/**
 *\fn s_liste* initListe(void)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 31 mars 2020
 *
 *\brief permet d'initialiser la liste
 *
 *
 *\return la liste
 *
 */
s_liste* initListe(void);

/**
 *\fn void insertion(s_liste* liste, int nbr)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 31 mars 2020
 *
 *\brief permet d'insérer un élément dans la liste
 *
 *
 *\param liste la liste dans laquelle on insère un nouvel élément
 *\param nbr la valeur du nouvel élément
 *
 */
void insertion(s_liste* liste, int nbr);

/**
 *\fn void afficherListe(s_liste* liste)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 31 mars 2020
 *
 *\brief permet d'afficher la liste
 *
 *
 *\param liste la liste à afficher
 *
 */
void afficherListe(s_liste* liste);

#endif
