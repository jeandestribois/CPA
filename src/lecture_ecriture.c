#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/structure.h"
#include "../include/lecture_ecriture.h"


/* Fonction afichant les données contenues dans la structure CONFIGURATION */
void afficher_conf(CONFIGURATION conf) {
	printf("\n*******************************************************\n\n");
	printf("[CONFIGURATION] Executable : %s\n", conf.nom_executable);
	printf("[CONFIGURATION] Nombre de traces : %d\n", conf.nbr_traces);
	printf("[CONFIGURATION] Adresse de début : 0x%lx\n", conf.adr_debut);
	printf("[CONFIGURATION] Adresse de fin : 0x%lx\n", conf.adr_fin);
	printf("[CONFIGURATION] Adresse de début de la pile : 0x%lx\n", conf.adr_debut_pile);
	printf("[CONFIGURATION] Adresse de fin de la pile : 0x%lx\n", conf.adr_fin_pile);
	printf("\n*********************************************************\n");
}


/* Fonction permettant de charger les données contenues dans
un fichier et les stocker dans une structure CONFIGURATION. */
int lecture_configuration(CONFIGURATION *conf, char *nom_fichier) {
	FILE *fichier = fopen(nom_fichier, "r");

	if(fichier == NULL) {
		printf("[ERREUR] Impossible d'ouvrir le fichier %s\n", nom_fichier);
		return -1;
	}
	if(fscanf(fichier, "%s", conf->nom_executable) == EOF) {
		printf("[ERREUR] Lecture de l'executable\n");
		return -1;
	}
	if(fscanf(fichier, "%d", &conf->nbr_traces) == EOF) {
		printf("[ERREUR] Lecture du nombre de traces\n");
		return -1;
	}
	if(fscanf(fichier, "%lx", &conf->adr_debut) == EOF) {
		printf("[ERREUR] Lecture de l'adresse de début\n");
		return -1;
	}
	if(fscanf(fichier, "%lx", &conf->adr_fin) == EOF) {
		printf("[ERREUR] Lecture de l'adresse de fin\n");
		return -1;
	}
	if(fscanf(fichier, "%lx", &conf->adr_debut_pile) == EOF) {
		printf("[ERREUR] Lecture de l'adresse de début de la pile\n");
		return -1;
	}
	if(fscanf(fichier, "%lx", &conf->adr_fin_pile) == EOF) {
		printf("[ERREUR] Lecture de l'adresse de fin de la pile\n");
		return -1;
	}

	fclose(fichier);

	afficher_conf(*conf);

	return 0;
}