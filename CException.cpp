#include "CException.h"

/****************************************************************************************************************
***** CException : constructeur par d�faut de la classe CException											*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
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
***** Entr�e :	unsigned int uiValeur																		*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise une exception � la valeur pass�e en param�tre					    *****
*****************************************************************************************************************/

CException::CException(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}


/****************************************************************************************************************
***** EXCAfficherErreur	: cette m�thode affiche le message correspondant � l'exception						*****
*****************************************************************************************************************
***** Entr�e : CException EXCErreur																			*****
***** N�cessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entra�ne : le message correspondant � l'exception est affich� dans le terminal						*****
*****************************************************************************************************************/

void CException::EXCAfficherErreur()
{
	switch (uiEXCValeur)
	{
		default:
		{
			cout << "Erreur par d�faut de CException.\n";
			break;
		}
		case CHEMIN_INVALIDE:
		{
			cout << "Le chemin sp�cifi� est invalide. Veuillez entrer un chemin diff�rent pour vos fichiers.\n";
			break;
		}
		case POSITION_INVALIDE:
		{
			cout << "La position � laquelle vous essayez d'acc�der est en dehors de la matrice.\n";
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
			cout << "Les tailles des matrices sont incompatibles pour cette op�ration.\n";
			break;
		}
		case BALISE_INVALIDE:
		{
			cout << "Une erreur de syntaxe a �t� recontr�e lors de la lecture du fichier.\n";
			break;
		}
		case MATRICE_NON_LIGNE:
		{
			cout << "La matrice fournie doit �tre une matrice ligne.\n";
			break;
		}
		case MAUVAISE_MATRICE_DECALAGE :
		{
			cout << "La s�quence de d�calage fournie n'est pas � la bonne taille.\n";
			break;
		}
	}
}