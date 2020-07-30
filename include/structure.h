#ifndef STRUCTURE_H
#define STRUCTURE_H


/* Structure stockant les informations de la configuration */
struct configuration {
	char nom_executable[100];
	int nbr_traces;
	uint64_t adr_debut;
	uint64_t adr_fin;
	uint64_t adr_debut_pile;
	uint64_t adr_fin_pile;
}; typedef struct configuration CONFIGURATION;


#endif