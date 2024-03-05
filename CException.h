#pragma once
#define PAS_ERREUR 0
#define CHEMIN_INVALIDE 1
#define POSITION_INVALIDE 2
#define MATRICE_VIDE 3
#define DIVISION_PAR_0 4
#define TAILLES_INCOMPATIBLES 5
#define BALISE_INVALIDE 6
#define MATRICE_NON_LIGNE 7
#define MAUVAISE_MATRICE_DECALAGE 8

#include <iostream>
using namespace std;

class CException
{
private:
	//Attributs
	unsigned int uiEXCValeur;

public:
	//Constructeur

	/****************************************************************************************************************
	***** CException : constructeur par d�faut de la classe CException											*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une exception													    *****
	*****************************************************************************************************************/
	CException();

	/****************************************************************************************************************
	***** CException : constructeur de confort de la classe CException											*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiValeur																		*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une exception � la valeur pass�e en param�tre					    *****
	*****************************************************************************************************************/
	CException(unsigned int uiValeur);

	//M�thodes

	/****************************************************************************************************************
	***** EXCLireValeur : cette m�thode lit la valeur de la classe										   	    *****
	*****************************************************************************************************************
	***** Entr�e : Rien																							*****
	***** N�cessite : Rien																						*****
	***** Sortie : unsigned int valeur																			*****
	***** Entra�ne : la fonction renvoie la valeur de l'exception												*****
	*****************************************************************************************************************/
	const unsigned int EXCLireValeur() const;


	/****************************************************************************************************************
	***** EXCModifierValeur	: cette m�thode modifie la valeur de la classe										*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiNvValeur																		*****
	***** N�cessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entra�ne : la valeur de l'exception est modifi�e														*****
	*****************************************************************************************************************/
	void EXCModifierValeur(unsigned int uiNvValeur);


	/****************************************************************************************************************
	***** EXCAfficherErreur	: cette m�thode affiche le message correspondant � l'exception						*****
	*****************************************************************************************************************
	***** Entr�e : CException EXCErreur																			*****
	***** N�cessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entra�ne : le message correspondant � l'exception est affich� dans le terminal						*****
	*****************************************************************************************************************/
	void EXCAfficherErreur();
};

#include "CException.ipp"