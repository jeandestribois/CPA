#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#include "../include/structure.h"
#include "../include/enregistrement_traces.h"


/* Fonction générant un nombre aléatoire de 128 sous forme de chaine de carractère */
char *alea_int_128(char entree[32]) {
	uint32_t aleatoire;
	char char_aleatoire[9];

	// On concatène 4 int aléatoire pour former un nombre de 128 bits dans la chaine de caractère entree;
	entree[0] = '\0';
	for(int j=0; j<4; j++) {
		aleatoire = rand();
		sprintf(char_aleatoire, "%08x", aleatoire);
		strcat(entree, char_aleatoire);
	}
	return entree;
}






/*Fonction permettant d'enregistrer des traces de divers
execution du programme à attaquer*/
int enregistrement_traces(CONFIGURATION conf) {
	// Initialisation de rand
	srand(time(NULL));

	char entree[32];
	char sortie[32];
	char commande[300] = "\0";

	FILE *retour_commande = NULL;

	// Boucle principale pour l'enregistrement des traces
	for(int i=0; i<conf.nbr_traces; i++) {
		printf("[ENREGISTREMENT] %d/%d\n", i+1, conf.nbr_traces);

		// Génération de l'entrée aléatoire.
		alea_int_128(entree);
		printf("[ENREGISTREMENT] entree = %s\n", entree);

		// On prépare la commande à executer
		sprintf(commande, "valgrind --quiet --tool=tracergrind --filter=%lx-%lx --output=trace%d.grind %s %s",\
			conf.adr_debut, conf.adr_fin, i, conf.nom_executable, entree);
		printf("[ENREGISTREMENT] %s\n", commande);

		// On execute l'enregistrement et on récupère la sortie (le chiffré)
		retour_commande = popen(commande, "r");
		fgets(sortie, 32, retour_commande);
		if(sortie[0] == '\0') {
			printf("[ERREUR] Impossible d'executer %s\n", commande);
			pclose(retour_commande);
			return -1;
		}
		pclose(retour_commande);
		printf("[ENREGISTREMENT] sortie = %s\n\n", sortie);

		// On change le format des traces (bin -> texte)
		sprintf(commande, "texttrace trace%d.grind trace%d.txt", i, i);
		retour_commande=popen(commande, "r");
		pclose(retour_commande);

		// Puis on supprime la trace en binaire
		sprintf(commande, "rm trace%d.grind", i);
		retour_commande=popen(commande, "r");
		pclose(retour_commande);
	}


	return 0;
}