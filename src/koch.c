
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

/* Lancement du programme */
int main(int argc, char *argv[])
{
	struct parameters parameters;
	struct list *koch = NULL;
	uint32_t *picture = NULL;

	TRACE( 3, "Started" );

	init_parameters(&parameters, argc, argv);
	//show_parameters(parameters);
	init_koch(&koch, parameters.image_size, parameters.segment_length);

	char *outfile = malloc(3 + strlen(parameters.outfile) + 1);
	for (uint32_t i = 0; i <= parameters.nb_iterations; ++i)
	{
		sprintf(outfile, "%02d_%s", i, parameters.outfile);
		generer_koch(koch, i);
		//show_koch_list(koch);
		init_picture(&picture, parameters.image_size, parameters.bg_color);
		render_image_bresenham(picture, koch, parameters.image_size, parameters.fg_color);
		create_image(picture, parameters.image_size, parameters.image_size, outfile);
	}

	/* Libérations mémoire */
	free_koch(koch);
	SAFE_FREE(outfile);
	SAFE_FREE(picture);
	SAFE_FREE(parameters.outfile);

	return EXIT_SUCCESS;
}
