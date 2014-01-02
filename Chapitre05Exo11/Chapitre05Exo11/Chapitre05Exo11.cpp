#define _CRT_SECURE_NO_WARNINGS 1
/*
*****************************************************************************************
Date		: 09.04.2013																*
Auteur		: Oscar																		*
Nom			: Chapitre05Exo11															*
Description	: Initialisation d'un tableau à 2 dimensions avec des valeurs aléatoires	*
			  Afficher les valeur du tableau ainsi que les sommes par ligne et colonne	*			
*****************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NBLIGNES 3
#define NBCOLONNES 3

//Prototypes de fonction
void initTab(int tab[NBLIGNES][NBCOLONNES]);
void printTab(int tab[NBLIGNES][NBCOLONNES]);

void main(){

	int tab2D[NBCOLONNES][NBCOLONNES];

	printf("Taille du tableau %d octets\n", sizeof(tab2D));

	initTab(tab2D);		//Init tableau
	printTab(tab2D);	//Affichage du résultat

	system("pause");
}


//FONCTIONS
//Initialiser un tableau 2 dimensions aléatoirement
void initTab(int tab[NBLIGNES][NBCOLONNES]){

	time_t t;
	srand((unsigned) time(&t));

	int ligne, colonne;

	for (ligne = 0; ligne < NBLIGNES; ligne++)
	{
		for (colonne = 0; colonne < NBCOLONNES; colonne++)
		{
			tab[ligne][colonne] = rand() % 101;
		}
	}
}


//Affichage du tableau avec les sommes par ligne et par colonne
void printTab(int tab[NBLIGNES][NBCOLONNES]){

	int ligne, colonne, sommeL, sommeC, i;
	int	tabSommeColonnes[NBCOLONNES];

	//Boucle pour parcourir les colonnes par ligne en mettant les valeurs du tableau et la somme à la fin (à droite)
	for (ligne = 0; ligne < NBLIGNES; ligne++)
	{
		tabSommeColonnes[ligne] += tab[ligne][0];
		sommeL = 0;
		printf("| ");
		for (colonne = 0; colonne < NBCOLONNES; colonne++)
		{
			printf("%4d | ", tab[ligne][colonne]);
			sommeL += tab[ligne][colonne];
		}

		printf("%4d\n", sommeL);
	}

	printf("| ");

	//Boucle pour parcourir les lignes par colonne en mettant la somme à la fin (en bas)
	for (colonne = 0; colonne < NBCOLONNES; colonne++)
	{
		sommeC = 0;
		for (ligne = 0; ligne < NBLIGNES; ligne++)
		{
			sommeC += tab[ligne][colonne];
		}

		printf("%4d | ", sommeC);
	}

	puts(" N/A ");
	
}