



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/structure.h"
#include "../include/lecture_ecriture.h"
#include "../include/enregistrement_traces.h"




int main(int argc, char *argv[])
{
	// Vérification des arguments
	if (argc != 2) {
		printf("[ERREUR] Entrée attendu : ./cpa fichier_configuration\n");
		exit(0);
	}

	// Lecture du fichier de configuration
	CONFIGURATION conf;
	if (lecture_configuration(&conf, argv[1]) == -1)
		exit(0);

	// Enregistrement des traces
	if (enregistrement_traces(conf) == -1)
		exit(0);


	return 0;
}