
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
	if (parameters)
	{
		char input[6][MAX_ARG_SIZE], *temp = NULL;
		const uint32_t COUNT = argc-1;
		bool error;

		for (uint32_t i = 0; i < COUNT; ++i)
		{
			strncpy(input[i], argv[i+1], MAX_ARG_SIZE);
			input[i][MAX_ARG_SIZE-1] = '\0';
		}

		for (uint32_t i = COUNT; i < 6; ++i)
		{
			do {
				error = false;

				switch(i) {
				case 0:
					printf("Taille segment ? ");
					break;
				case 1:
					printf("Nombre d'itérations ? ");
					break;
				case 2:
					printf("Couleur de trace ? (0xRRVVBB) ");
					break;
				case 3:
					printf("Couleur de fond ? (0xRRVVBB) ");
					break;
				case 4:
					printf("Nom de sortie ? ");
					break;
				case 5:
					printf("Générer toutes les images intermédiaires ? (o/n) ");
					break;
				}

				fgets(input[i], MAX_ARG_SIZE, stdin);

				if (strlen(input[i]) < 1) {
					error = true;
					printf("Saisie invalide.\n\n");
				}
			} while (error);
		}
		if (COUNT < 6)
			putchar('\n');

		parameters->segment_length = strtoul(input[0], NULL, 10);
		parameters->image_size = 2 * BORDER_CALC(parameters->segment_length) + parameters->segment_length;
		parameters->nb_iterations = strtoul(input[1], NULL, 10);
		parameters->fg_color = strtoul(input[2], NULL, 0);
		parameters->bg_color = strtoul(input[3], NULL, 0);

		temp = input[4];
		parameters->outfile = malloc(strlen(temp) + 1);
		strcpy(parameters->outfile, temp);

		temp = input[5];
		parameters->all_images = !strcasecmp(temp, "all") |
									!strcasecmp(temp, "1") |
									!strcasecmp(temp, "y") |
									!strcasecmp(temp, "o") |
									!strcasecmp(temp, "yes") |
									!strcasecmp(temp, "oui") |
									!strcasecmp(temp, "ok");
	}
}

/* Affichage de controle sous forme texte de la liste des coordonnees
   des points du flocon de Koch */
void show_koch_list(struct list *koch)
{
	while (koch) {
		printf("x = %d, y = %d\n", koch->x, koch->y);
		koch = koch->next;
	}

	putchar('\n');
}

/* Affichage de controle des differents parametres de la fractale */
void show_parameters(struct parameters parameters)
{
	printf(
			"segment_length : %d\n"
			"image_size : %d\n"
			"nb_iterations : %d\n"
			"fg_color : 0x%06X\n"
			"bg_color : 0x%06X\n"
			"all_images : %d\n"
			"outfile : %s\n",
			parameters.segment_length,
			parameters.image_size,
			parameters.nb_iterations,
			parameters.fg_color,
			parameters.bg_color,
			parameters.all_images,
			parameters.outfile
			);
}

/* Creation de l'image ppm dans un fichier */
void create_image(uint32_t *picture, int32_t size_x, int32_t size_y,
		  char *filename)
{
	FILE *file = fopen(filename, "wb");

	if (file != NULL) {
		const uint32_t LEN = size_x * size_y;
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

		for (uint32_t i = 0; i < LEN; i++) {
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
		TRACE(2, "Erreur de la generation PPM");
	}
}
