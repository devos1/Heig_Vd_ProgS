#define _CRT_SECURE_NO_WARNINGS 1
/*
*****************************************************************************************
Date		: 19.03.2013																*
Auteur		: Oscar																		*
Nom			: Chapitre05Exo05															*
Description	: Tri d'un tableau en utilisant 2 boucles for imbriqu�es avec nombre MIN	*
*****************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

//PROTOTYPES DE FONCTIONS
//Imprime les nb �l�ments du tableau
void printTab(int tab[], int nb);

//Initialise le tableau avec des valeurs al�atoires
void initRandomTab(int tab[], int nb);

//Trie par ordre croissant le tableau
void triTabCroissant(int tab[], int nb);

void main()
{
	int tab[N];

	initRandomTab(tab, N);

	puts("Tableau sans tri: ");
	printTab(tab, N);

	triTabCroissant(tab, N);

	puts("");
	puts("Tableau avec tri: ");
	printTab(tab, N);

	system("pause");

}

//FONCTIONS
//Imprime les nb �l�ments du tableau
void printTab(int tab[], int nb){
	int i;

	for (i = 0; i < nb; i++)
	{
		printf("%d ", tab[i]);
	}
	puts("");
}

//Initialise le tableau avec des valeurs al�atoires
void initRandomTab(int tab[], int nb){
	int i;
	time_t t;

	srand((unsigned) time(&t));		//Initialisation des nombres al�atoires

	for (i = 0; i < nb; i++)
	{
		tab[i] = rand() % 101;		//Nombre al�atoire entre 
	}
	
}

//Trie par ordre croissant le tableau
void triTabCroissant(int tab[], int nb){
	int i, j, min, indiceMin;

	for (i = 0; i < nb-1; i++)
	{
		min = tab[i];						//On consid�re que le 1er nb est le plus petit
		indiceMin = i;						//Indice du nombre le plus petit
		for (j = i+1; j < nb; j++)			//Recherche du nombre min
		{
			if (tab[j] < min)
			{
				min = tab[j];				//Si trouv�, on le mets dans la variable min
				indiceMin = j;				//Mise � jour de l'indice du min
			}
		}

		if (i != indiceMin)					//Si trouv� un nombre plus petit, on a l'indice
		{
			tab[indiceMin] = tab[i];		//On place la valeur en cours dans la position de l'indice min
			tab[i] = min;					//Et le min � la position en cours
		}
	}
}
