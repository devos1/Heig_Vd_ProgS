#define _CRT_SECURE_NO_WARNINGS 1
/*
*****************************************************************************************
Date		: 26.03.2013																*
Auteur		: Oscar																		*
Nom			: Chapitre05Exo08															*
Description	: Recherche d'une valeur dans un tableau trié (Dichotomique)				*					
*****************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 8
#define VRAI 1
#define FAUX 0
#define MAX_LIGNE 10

//PROTOTYPES DE FONCTION
int saisieInt();
void initTab(int tab[], int maxTab);
void triTab(int tab[], int maxTab);
void afficheTab(int tab[], int maxTab);
void trouveVal(int tab[], int maxTab, int valeur);


void main(){

	int tab[MAX];
	int nb;

	initTab(tab, MAX);

	printf("Tableau avant le tri : ");
	afficheTab(tab, MAX);

	triTab(tab, MAX);

	printf("Tableau apres le tri : ");
	afficheTab(tab, MAX);

	//RECHERCHE D'UNE VALEUR DANS UN TABLEAU TRIEE, CE QUI VEUT DIRE QU'IL FAUT UTILISER LA RECHERCHE DICHOTOMIQUE (Plus performant)
	printf("Entrer la valeur a trouver : ");
	nb = saisieInt();
	trouveVal(tab, MAX, nb);

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

//FONCTION POUR INITIALISER LE TABLEAU
void initTab(int tab[], int maxTab){

	time_t t;						//Variable qui permet de stocker l'heure
	int i;

	srand((unsigned) time(&t));		//Initialiser le générateur de nombre selon l'heure courante

	for (i = 0; i < maxTab; i++)
	{
		tab[i] = rand() % 101;		//Génère un nombre aléatoire entre 0 et 100;
	}
}

//FONCTION POUR TRIER LE TABLEAU PAR ORDRE CROISSANTE
void triTab(int tab[], int maxTab){

	int i, j, min, posMin;

	for (i = 0; i < maxTab - 1; i++)
	{
		min = tab[i];
		for (j = i + 1; j < maxTab; j++)
		{
			if (tab[j] < min)
			{
				min = tab[j];
				posMin = j;
			}
		}
		if (min < tab[i])
		{
			tab[posMin] = tab[i];
			tab[i] = min;
		}
	}
}

//FONCTION POUR AFFICHER UN TABLEAU
void afficheTab(int tab[], int maxTab){

	for (int i = 0; i < maxTab; i++)
	{
		printf("%d ", tab[i]);
	}
	puts("");
}

//FONCTION POUR RECHERCHER UNE VALEUR (DYCHOTOMIQUE)
void trouveVal(int tab[], int maxTab, int valeur){

	int debut = 0, fin = maxTab - 1, median, trouve = FAUX, iTab = 0;

	//Tant que le nombre n'a pas été trouvé ou le début n'est pas plus grand que la fin
	while (!trouve && debut <= fin)
	{
		median = (debut + fin) / 2;
		if (valeur == tab[median])
		{
			trouve = VRAI;
			iTab = median;
		}
		else
		{
			if (valeur < tab[median])
			{
				fin = median - 1;
			}
			else
			{
				debut = median + 1;
			}
		}
	}

	if (!trouve)
	{
		printf("Le nombre %d n'est pas dans ce tableau\n", valeur);
	}
	else
	{
		printf("Le nombre %d se trouve a la position %d\n", valeur, iTab + 1);
	}


}



