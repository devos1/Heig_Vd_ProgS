#define _CRT_SECURE_NO_WARNINGS 1
/*
*****************************************************************************************
Date		: 09.04.2013																*
Auteur		: Oscar																		*
Nom			: Chapitre05Exo10															*
Description	: Remplir un tableau 2D avec des valeurs saisies au clavier					*	
			  Ensuite chercher si le tableau contient au moins une valeur à 0			*
*****************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>

//#define TailleTab 48
#define MAX_LIGNE 10
#define NBLIGNES 3
#define NBCOLONNES 4

//PROTOTYPES DE FONCTION
int saisieInt();

void main(){

	int ligne, colonne, nb = 0, nbNul = 0;
	int tab2D[NBLIGNES][NBCOLONNES];
	printf("Taille du tableau = %d octets\n", sizeof(tab2D));

	//Insertion dans le tableau des nombres
	for (ligne = 0; ligne < NBLIGNES; ligne++)
	{
		for (colonne = 0; colonne < NBCOLONNES; colonne++)
		{
			nb++;
			printf("Entrer la valeur no : %2d (table[%d][%d])",(ligne * NBCOLONNES) + colonne + 1, ligne, colonne);
			tab2D[ligne][colonne] = saisieInt();
		}
	}

	//Recherche d'une valeur à 0
	for (ligne = 0; ligne < NBLIGNES; ligne++)
	{
		for (colonne = 0; colonne < NBCOLONNES; colonne++)
		{
			if (tab2D[ligne][colonne] == 0)
			{
				nbNul++;
			}
		}
	}

	if (nbNul > 0)
	{
		printf("La table contient %d valeur(s) nulle(s)\n", nbNul);
	}
	else
	{
		printf("La table ne contient aucune valeur nulle\n");
	}

	system("pause");
}

//FONCTIONS
//Saisie d'une valeur entière
int saisieInt() {
	int valeur, n;
	char ligne[MAX_LIGNE];

	fgets(ligne, MAX_LIGNE, stdin);
	n = sscanf(ligne, "%d", &valeur);
	while (n != 1) {
		printf("Erreur entrer une valeur entiere : ");
		fgets(ligne, MAX_LIGNE, stdin);
		n = sscanf(ligne, "%d", &valeur);
	}
	return valeur;
}

