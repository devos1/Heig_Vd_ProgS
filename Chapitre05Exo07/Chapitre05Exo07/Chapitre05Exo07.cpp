#define _CRT_SECURE_NO_WARNINGS 1
/*
*****************************************************************************************
Date		: 24.03.2013																*
Auteur		: Oscar																		*
Nom			: Chapitre05Exo07															*
Description	: Recherche d'une valeur dans un tableau									*
*****************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>

#define TAILLE 8
#define MAX_LIGNE 10
#define VRAI 1
#define FAUX 0

//PROTOTYPES DE FONCTIONS
//Saisie d'une valeur entière
int saisieInt();

//Imprime les nb éléments du tableau
void printTab(int tab[], int nb);

int main(void){

	int tab[TAILLE] = { 10, 22, 0, 18, 19, 21, 2, 999 };
	int scan = 0, nb, i = 0, trouve = FAUX;

	printf("Tableau: ");
	printTab(tab, TAILLE);
	puts("");

	printf("Valeur: ");
	nb = saisieInt();

	while (trouve == FAUX && i < TAILLE)
	{
		if (tab[i] == nb){
			trouve = VRAI;
		}
		else
		{
			trouve = FAUX;
		}
		i++;
	}

	if (trouve == VRAI)
	{
		printf("%d est a la position %d \n", nb, i);
	}
	else
	{
		printf("%d n'est pas dans ce tableau\n\n", nb);
	}

	puts("");
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

//Imprime les nb éléments du tableau
void printTab(int tab[], int nb){
	int i;

	for (i = 0; i < nb; i++)
	{
		printf("%d ", tab[i]);
	}
	puts("");
}
