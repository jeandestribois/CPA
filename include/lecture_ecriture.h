#ifndef LECTURE_ECRITURE_H
#define LECTURE_ECRITURE_H



/* Fonction permettant de charger les données contenues dans
un fichier et les stocker dans une structure CONFIGURATION. */
int lecture_configuration(CONFIGURATION *conf, char *nom_fichier);

/* Fonction afichant les données contenues dans la structure CONFIGURATION */
void afficher_conf(CONFIGURATION conf);

#endif