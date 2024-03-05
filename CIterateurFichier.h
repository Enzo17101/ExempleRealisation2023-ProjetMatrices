#pragma once

#include "CException.h"
#include "CMatrice.h"
#include <cstring>
#include <fstream>

class CIterateurFichier
{
private:
	//Attributs
	char* pcChemin;

public:
	//Constructeurs et destructeur

	/****************************************************************************************************************
	***** CIterateurFichier : constructeur par défaut de la classe CIterateurFichier							*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un itérateur de fichier												*****
	*****************************************************************************************************************/
	CIterateurFichier();

	/****************************************************************************************************************
	***** CIterateurFichier : constructeur de recopie de la classe CIterateurFichier							*****
	*****************************************************************************************************************
	***** Entrée :	CIterateurFichier ITEParam			                                                        *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise un itérateur de fichier	à partir d'un autre itérateur de fichier	*****
	*****************************************************************************************************************/
	CIterateurFichier(CIterateurFichier & ITEParam);

	/****************************************************************************************************************
	***** CIterateurFichier : constructeur de confort de la classe CIterateurFichier							*****
	*****************************************************************************************************************
	***** Entrée :	char * pcCheminFichier			                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un itérateur de fichier	à partir d'un chemin en paramètre		    *****
	*****************************************************************************************************************/
	CIterateurFichier(const char * pcCheminFichier);

	/****************************************************************************************************************
	***** ~CIterateurFichier : destructeur de la classe CIterateurFichier										*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction désalloue l'espace mémoire attribué à un itérateur de fichier					*****
	*****************************************************************************************************************/
	~CIterateurFichier();

	/****************************************************************************************************************
	***** ITELireChemin : Accesseur en lecture de pcChemin														*****
	*****************************************************************************************************************
	***** Entrée : Rien																							*****
	***** Nécessite : Rien																						*****
	***** Sortie : char *																						*****
	***** Entraine : La fonction renvoie le chemin stocké dans l'itérateur de fichier							*****
	*****************************************************************************************************************/
	char* ITELireChemin() const;

	/****************************************************************************************************************
	***** ITEModifierChemin : Accesseur en écriture de pcChemin													*****
	*****************************************************************************************************************
	***** Entrée : char * pcCheminFichier																		*****
	***** Nécessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction modifie le chemin stocké dans l'itérateur de fichier							*****
	*****************************************************************************************************************/
	void ITEModifierChemin(const char* pcCheminFichier);

	/****************************************************************************************************************
	***** ITEGenererMatrice : Fonction permettant de créer une matrice de doubles à partir d'un fichier texte	*****
	*****************************************************************************************************************
	***** Entrée : Rien																							*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<double>																				*****
	***** Entraine : la fonction renvoie la matrice initialisée à partir du fichier correspondant au chemin de	*****
	*****			 CIterateurFichier																		  OU*****
	**************** Exception CHEMIN_INVALIDE : Le fichier correspondant au chemin spécifié n'a pas pus être	*****
	****************							 ouvert															*****
	**************** Exception BALISE_INVALIDE : Une des balises écrites dans le fichier texte est incorrecte,	*****
	****************							 on rencontrera aussi cette exception si ce n'est pas le type	*****
	****************							 double qui est spécifié										*****
	*****************************************************************************************************************/
	CMatrice<double> & ITEGenererMatrice();
};

#include "CIterateurFichier.ipp"