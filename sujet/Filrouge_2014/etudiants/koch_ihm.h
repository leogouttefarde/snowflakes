
/**
 * Fichier : koch_ihm.h
 * Description : Trace de fractales geometriques
                 Fonctions d'ihm du calcul du flocon de koch
 * Auteur : <prenom> <nom>
 * Date : jj/mm/2014
 */

#ifndef _KOCH_IHM_H_
#define _KOCH_IHM_H_

/* Initialisation des differents parametres de la fractale a partir
   des arguments du programme ou a defaut en mode interactif */
void init_parameters(struct parameters *parameters, int argc, char *argv[]);

/* Affichage de controle sous forme texte de la liste des coordonnees
   des points du flocon de Koch */
void show_koch_list(struct list *koch);

/* Affichage de controle des differents parametres de la fractale */
void show_parameters(struct parameters parameters);

/* Creation de l'image ppm dans un fichier */
void create_image(uint32_t *picture, int32_t size_x, int32_t size_y,
		  char *filename);

#endif
