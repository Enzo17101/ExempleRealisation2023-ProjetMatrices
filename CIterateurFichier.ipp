#include "CIterateurFichier.h"


/****************************************************************************************************************
***** ITELireChemin : Accesseur en lecture de pcChemin														*****
*****************************************************************************************************************
***** Entrée : Rien																							*****
***** Nécessite : Rien																						*****
***** Sortie : char *																						*****
***** Entraine : la fonction renvoie le chemin stocké dans l'itérateur de fichier						  OU*****
*****************************************************************************************************************/

inline char* CIterateurFichier::ITELireChemin() const
{
	return pcChemin;
}


/****************************************************************************************************************
***** ITEModifierChemin : Accesseur en écriture de pcChemin													*****
*****************************************************************************************************************
***** Entrée : char * pcCheminFichier																		*****
***** Nécessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraine : La fonction modifie le chemin stocké dans l'itérateur de fichier							*****
*****************************************************************************************************************/

inline void CIterateurFichier::ITEModifierChemin(const char* pcCheminFichier)
{
	//on supprime le chemin déjà existant
	delete pcChemin;

	//longueur du chemin en paramètre en comptant le caractère de fin de chaine
	unsigned int uiLongueurChemin = strlen(pcCheminFichier) + 1;

	//on crée le nouveau chemin
	pcChemin = new char[uiLongueurChemin];

	//on copie le chemin en paramètre dans pcChemin
	strcpy_s(pcChemin, uiLongueurChemin, pcCheminFichier);
}