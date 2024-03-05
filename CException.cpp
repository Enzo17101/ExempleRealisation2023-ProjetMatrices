#include "CException.h"

/****************************************************************************************************************
***** CException : constructeur par défaut de la classe CException											*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise une exception													    *****
*****************************************************************************************************************/

CException::CException()
{
	uiEXCValeur = PAS_ERREUR;
}


/****************************************************************************************************************
***** CException : constructeur de confort de la classe CException											*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiValeur																		*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise une exception à la valeur passée en paramètre					    *****
*****************************************************************************************************************/

CException::CException(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}


/****************************************************************************************************************
***** EXCAfficherErreur	: cette méthode affiche le message correspondant à l'exception						*****
*****************************************************************************************************************
***** Entrée : CException EXCErreur																			*****
***** Nécessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraîne : le message correspondant à l'exception est affiché dans le terminal						*****
*****************************************************************************************************************/

void CException::EXCAfficherErreur()
{
	switch (uiEXCValeur)
	{
		default:
		{
			cout << "Erreur par défaut de CException.\n";
			break;
		}
		case CHEMIN_INVALIDE:
		{
			cout << "Le chemin spécifié est invalide. Veuillez entrer un chemin différent pour vos fichiers.\n";
			break;
		}
		case POSITION_INVALIDE:
		{
			cout << "La position à laquelle vous essayez d'accéder est en dehors de la matrice.\n";
			break;
		}
		case MATRICE_VIDE:
		{
			cout << "La matrice est vide.\n";
			break;
		}
		case DIVISION_PAR_0:
		{
			cout << "Impossible de diviser par 0.\n";
			break;
		}
		case TAILLES_INCOMPATIBLES:
		{
			cout << "Les tailles des matrices sont incompatibles pour cette opération.\n";
			break;
		}
		case BALISE_INVALIDE:
		{
			cout << "Une erreur de syntaxe a été recontrée lors de la lecture du fichier.\n";
			break;
		}
		case MATRICE_NON_LIGNE:
		{
			cout << "La matrice fournie doit être une matrice ligne.\n";
			break;
		}
		case MAUVAISE_MATRICE_DECALAGE :
		{
			cout << "La séquence de décalage fournie n'est pas à la bonne taille.\n";
			break;
		}
	}
}