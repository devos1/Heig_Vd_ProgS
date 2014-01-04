#define _CRT_SECURE_NO_WARNINGS 1
/*
*****************************************************************************************
Date		: 02.01.2014																*
Auteur		: Oscar																		*
Nom			: Chapitre05Exo12															*
Description	: Tableaux 3D avec notes, �tudiants, mati�res								*
			  Trouver moyenne par �tudiant et mati�re									*
*****************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//PROTOTYPES DE FONCTION
float saisieFloat();

#define MAX_LIGNE 10
#define NBETUDIANTS 3
#define NBMATIERES 3
#define NBNOTES 3

void main(){

	//Variables
	float notes[NBETUDIANTS][NBMATIERES][NBNOTES];
	float moyennes[NBETUDIANTS];
	int etudiant, matiere, nbNotes, note, nbMatieres, meilleur, n;
	float somme, moyenne;

	//Saisie des NOTES pour chaque etudiant et pour chaque mati�re
	for (etudiant = 0; etudiant < NBETUDIANTS; etudiant++)
	{
		for (matiere = 0; matiere < NBMATIERES; matiere++)
		{
			printf("Notes de l'etudiant No : %d, matiere : %d\n", etudiant + 1, matiere + 1);
			for (note = 0; note < NBNOTES; note++)
			{
				printf("Note %d: ", note + 1);
				notes[etudiant][matiere][note] = saisieFloat();
				while (notes[etudiant][matiere][note] != -1 && (notes[etudiant][matiere][note] < 1 || notes[etudiant][matiere][note] > 6))
				{
					printf("Note %d: ", note + 1);
					notes[etudiant][matiere][note] = saisieFloat();
				}
			}
		}
	}

	//Traitement des valeurs
	for (etudiant = 0; etudiant < NBETUDIANTS; etudiant++)
	{
		moyenne = 0;
		nbMatieres = NBMATIERES;
		for (matiere = 0; matiere < NBMATIERES; matiere++)
		{
			nbNotes = 0;
			somme = 0;
			for (note = 0; note < NBNOTES; note++)
			{
				if ((notes[etudiant][matiere][note] != -1))			//On contr�le qu'il n'y a pas -1 (absence de l'�l�ve au test)
				{
					somme += notes[etudiant][matiere][note];		//Somme des notes valides pour la mati�re et l'�l�ve trait�s
					nbNotes++;										//Incr�mente si note valide
				}
			}
			if (nbNotes > 0)
			{
				moyenne += somme / nbNotes;
			}
			else
			{
				nbMatieres--;
				//puts("Pas de notes dans cette matiere");
			}
		}

		if (nbMatieres > 0)
		{
			moyennes[etudiant] = moyenne / nbMatieres;
		}
		else
		{
			//puts("Aucunne Note");
			moyennes[etudiant] = -1;
		}
	}

	//Impression des r�sultats
	meilleur = 0;
	for ( etudiant = 0; etudiant < NBETUDIANTS; etudiant++)
	{
		printf("Moyenne de l'etudiant %d: %.2f\n", etudiant+1, moyennes[etudiant]);
		if (moyennes[etudiant] > moyennes[meilleur])
		{
			meilleur = etudiant;
		}
	}

	printf("Le meilleur etudiant est le numero %d\n\n", meilleur + 1);
	system("pause");

}


//FONCTIONS
//Saisie d'une valeur r�elle
float saisieFloat() {
	int n;
	float valeur;
	char ligne[MAX_LIGNE];

	fgets(ligne, MAX_LIGNE, stdin);
	n = sscanf(ligne, "%f", &valeur);
	while (n != 1) {
		printf("Erreur entrer une valeur entiere : ");
		fgets(ligne, MAX_LIGNE, stdin);
		n = sscanf(ligne, "%f", &valeur);
	}
	return valeur;
}