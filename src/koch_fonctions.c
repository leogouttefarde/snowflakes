
/**
 * Fichier : koch_fonctions.c
 * Description : Trace de fractales geometriques - fonctions de calcul du flocon de koch
 * Auteur : Léo Gouttefarde
 * Date : 21/04/2014
 */

#include "koch_fonctions.h"

/* Initialisation de la liste chainee koch correspondant au triangle
   de Koch initial */
void init_koch(struct list **koch, uint32_t size, uint32_t segment_length)
{
	
}

/* Initialisation de l'image avec la couleur de fond definie dans les
   parametres */
void init_picture(uint32_t **picture, uint32_t size, uint32_t bg_color)
{
	
}

/* Calcul de la fractale de Koch apres un nombre d'iterations donne ;
   generation de la liste chainee koch correspondante */
void generer_koch(struct list *koch, uint32_t nb_iterations)
{
	
}

/* Rendu image via algorithme bresehem - version generalisee
   simplifiee */
void render_image_bresenham(uint32_t *picture, struct list *koch,
			    uint32_t size, uint32_t fg_color)
{
	
}

/* Liberation de la memoire allouee a la liste chainee */
void free_koch(struct list *koch)
{
	
}
