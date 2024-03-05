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
	***** CException : constructeur par défaut de la classe CException											*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une exception													    *****
	*****************************************************************************************************************/
	CException();

	/****************************************************************************************************************
	***** CException : constructeur de confort de la classe CException											*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiValeur																		*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une exception à la valeur passée en paramètre					    *****
	*****************************************************************************************************************/
	CException(unsigned int uiValeur);

	//Méthodes

	/****************************************************************************************************************
	***** EXCLireValeur : cette méthode lit la valeur de la classe										   	    *****
	*****************************************************************************************************************
	***** Entrée : Rien																							*****
	***** Nécessite : Rien																						*****
	***** Sortie : unsigned int valeur																			*****
	***** Entraîne : la fonction renvoie la valeur de l'exception												*****
	*****************************************************************************************************************/
	const unsigned int EXCLireValeur() const;


	/****************************************************************************************************************
	***** EXCModifierValeur	: cette méthode modifie la valeur de la classe										*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiNvValeur																		*****
	***** Nécessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraîne : la valeur de l'exception est modifiée														*****
	*****************************************************************************************************************/
	void EXCModifierValeur(unsigned int uiNvValeur);


	/****************************************************************************************************************
	***** EXCAfficherErreur	: cette méthode affiche le message correspondant à l'exception						*****
	*****************************************************************************************************************
	***** Entrée : CException EXCErreur																			*****
	***** Nécessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraîne : le message correspondant à l'exception est affiché dans le terminal						*****
	*****************************************************************************************************************/
	void EXCAfficherErreur();
};

#include "CException.ipp"