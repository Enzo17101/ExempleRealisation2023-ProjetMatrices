#include "CException.h"


/****************************************************************************************************************
***** EXCLireValeur : cette m�thode lit la valeur de la classe										   	    *****
*****************************************************************************************************************
***** Entr�e : Rien																							*****
***** N�cessite : Rien																						*****
***** Sortie : unsigned int valeur																			*****
***** Entra�ne : la fonction renvoie la valeur de l'exception												*****
*****************************************************************************************************************/

inline const unsigned int CException::EXCLireValeur() const
{
	return 0;
}


/****************************************************************************************************************
***** EXCModifierValeur	: cette m�thode modifie la valeur de la classe										*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiNvValeur																		*****
***** N�cessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entra�ne : la valeur de l'exception est modifi�e														*****
*****************************************************************************************************************/

inline void CException::EXCModifierValeur(unsigned int uiNvValeur)
{
	uiEXCValeur = uiNvValeur;
}