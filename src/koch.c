
/**
 * Fichier : koch.c
 * Description : Trace de fractales geometriques
                 Programme principal
 * Auteur : Léo Gouttefarde
 * Date : 21/04/2014
 */

#include "koch_common.h"
#include "koch_fonctions.h"
#include "koch_ihm.h"

/* Programme "Flocon de Koch" */
int main(int argc, char *argv[])
{
	struct parameters parameters;
	struct list *koch = NULL;
	uint32_t *picture = NULL;
	char *outfile = NULL;

	/* Initialisations */
	init_parameters(&parameters, argc, argv);
	show_parameters(parameters);
	init_koch(&koch, parameters.image_size, parameters.segment_length);
	outfile = malloc(3 + strlen(parameters.outfile) + 1);

	/* Génération de chaque flocon */
	for (uint32_t i = 0; i <= parameters.nb_iterations; ++i)
	{
		sprintf(outfile, "%02d_%s", i, parameters.outfile);
		generer_koch(koch, i);
		//show_koch_list(koch);

		/* Ne générer l'image que si c'est la dernière ou qu'on les génère toutes */
		if (parameters.all_images || i == parameters.nb_iterations)
		{
			init_picture(&picture, parameters.image_size, parameters.bg_color);
			render_image_bresenham(picture, koch, parameters.image_size, parameters.fg_color);
			create_image(picture, parameters.image_size, parameters.image_size, outfile);
		}
	}

	/* Libérations mémoire */
	free_koch(koch);
	SAFE_FREE(outfile);
	SAFE_FREE(picture);
	SAFE_FREE(parameters.outfile);

	return EXIT_SUCCESS;
}
