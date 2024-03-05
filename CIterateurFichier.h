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
	***** CIterateurFichier : constructeur par d�faut de la classe CIterateurFichier							*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un it�rateur de fichier												*****
	*****************************************************************************************************************/
	CIterateurFichier();

	/****************************************************************************************************************
	***** CIterateurFichier : constructeur de recopie de la classe CIterateurFichier							*****
	*****************************************************************************************************************
	***** Entr�e :	CIterateurFichier ITEParam			                                                        *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise un it�rateur de fichier	� partir d'un autre it�rateur de fichier	*****
	*****************************************************************************************************************/
	CIterateurFichier(CIterateurFichier & ITEParam);

	/****************************************************************************************************************
	***** CIterateurFichier : constructeur de confort de la classe CIterateurFichier							*****
	*****************************************************************************************************************
	***** Entr�e :	char * pcCheminFichier			                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un it�rateur de fichier	� partir d'un chemin en param�tre		    *****
	*****************************************************************************************************************/
	CIterateurFichier(const char * pcCheminFichier);

	/****************************************************************************************************************
	***** ~CIterateurFichier : destructeur de la classe CIterateurFichier										*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction d�salloue l'espace m�moire attribu� � un it�rateur de fichier					*****
	*****************************************************************************************************************/
	~CIterateurFichier();

	/****************************************************************************************************************
	***** ITELireChemin : Accesseur en lecture de pcChemin														*****
	*****************************************************************************************************************
	***** Entr�e : Rien																							*****
	***** N�cessite : Rien																						*****
	***** Sortie : char *																						*****
	***** Entraine : La fonction renvoie le chemin stock� dans l'it�rateur de fichier							*****
	*****************************************************************************************************************/
	char* ITELireChemin() const;

	/****************************************************************************************************************
	***** ITEModifierChemin : Accesseur en �criture de pcChemin													*****
	*****************************************************************************************************************
	***** Entr�e : char * pcCheminFichier																		*****
	***** N�cessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction modifie le chemin stock� dans l'it�rateur de fichier							*****
	*****************************************************************************************************************/
	void ITEModifierChemin(const char* pcCheminFichier);

	/****************************************************************************************************************
	***** ITEGenererMatrice : Fonction permettant de cr�er une matrice de doubles � partir d'un fichier texte	*****
	*****************************************************************************************************************
	***** Entr�e : Rien																							*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<double>																				*****
	***** Entraine : la fonction renvoie la matrice initialis�e � partir du fichier correspondant au chemin de	*****
	*****			 CIterateurFichier																		  OU*****
	**************** Exception CHEMIN_INVALIDE : Le fichier correspondant au chemin sp�cifi� n'a pas pus �tre	*****
	****************							 ouvert															*****
	**************** Exception BALISE_INVALIDE : Une des balises �crites dans le fichier texte est incorrecte,	*****
	****************							 on rencontrera aussi cette exception si ce n'est pas le type	*****
	****************							 double qui est sp�cifi�										*****
	*****************************************************************************************************************/
	CMatrice<double> & ITEGenererMatrice();
};

#include "CIterateurFichier.ipp"