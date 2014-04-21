
/**
 * Fichier : koch_ihm.c
 * Description : Trace de fractales geometriques
                 Fonctions d'ihm du calcul du flocon de koch
 * Auteur : Léo Gouttefarde
 * Date : 21/04/2014
 */

#include "koch_ihm.h"

/* Initialisation des differents parametres de la fractale a partir
   des arguments du programme ou a defaut en mode interactif */
void init_parameters(struct parameters *parameters, int argc, char *argv[])
{

}

/* Affichage de controle sous forme texte de la liste des coordonnees
   des points du flocon de Koch */
void show_koch_list(struct list *koch)
{

}

/* Affichage de controle des differents parametres de la fractale */
void show_parameters(struct parameters parameters)
{

}

/* Creation de l'image ppm dans un fichier */
void create_image(uint32_t *picture, int32_t size_x, int32_t size_y,
		  char *filename)
{
	FILE *file = fopen(filename, "wb");

	if (file != NULL) {
		const int32_t LEN = size_x * size_y;
		uint32_t pixel;
		char buffer[3];

		fprintf(
				file,
				"P6\n"
				"%d %d\n"
				"255\n",
				size_x,
				size_y
				);

		for (int32_t i = 0; i < LEN; i++) {
			pixel = picture[i];

			/* Rouge */
			buffer[0] = pixel >> 16;

			/* Vert */
			buffer[1] = pixel >> 8;

			/* Bleu */
			buffer[2] = pixel;

			fwrite(buffer, 3, 1, file);
		}

		fclose(file);
	} else {
		TRACE(2, "PPM creation error");
	}

	return (file != NULL);
}
