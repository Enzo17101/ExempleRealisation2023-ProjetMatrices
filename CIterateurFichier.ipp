#include "CIterateurFichier.h"


/****************************************************************************************************************
***** ITELireChemin : Accesseur en lecture de pcChemin														*****
*****************************************************************************************************************
***** Entr�e : Rien																							*****
***** N�cessite : Rien																						*****
***** Sortie : char *																						*****
***** Entraine : la fonction renvoie le chemin stock� dans l'it�rateur de fichier						  OU*****
*****************************************************************************************************************/

inline char* CIterateurFichier::ITELireChemin() const
{
	return pcChemin;
}


/****************************************************************************************************************
***** ITEModifierChemin : Accesseur en �criture de pcChemin													*****
*****************************************************************************************************************
***** Entr�e : char * pcCheminFichier																		*****
***** N�cessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraine : La fonction modifie le chemin stock� dans l'it�rateur de fichier							*****
*****************************************************************************************************************/

inline void CIterateurFichier::ITEModifierChemin(const char* pcCheminFichier)
{
	//on supprime le chemin d�j� existant
	delete pcChemin;

	//longueur du chemin en param�tre en comptant le caract�re de fin de chaine
	unsigned int uiLongueurChemin = strlen(pcCheminFichier) + 1;

	//on cr�e le nouveau chemin
	pcChemin = new char[uiLongueurChemin];

	//on copie le chemin en param�tre dans pcChemin
	strcpy_s(pcChemin, uiLongueurChemin, pcCheminFichier);
}