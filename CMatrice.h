#pragma once
#include "CException.h"
#include <iostream>


template <class MType> class CMatrice
{
private:
	//Attributs
	MType** ppMTPMATMatrice;
	
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;

public:
	//Constructeurs et destructeur

	/****************************************************************************************************************
	***** CMatrice : constructeur par défaut de la classe CMatrice												*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une matrice du type spécifié									    *****
	*****************************************************************************************************************/
	CMatrice<MType>();

	/****************************************************************************************************************
	***** CMatrice : constructeur de recopie de la classe CMatrice												*****
	*****************************************************************************************************************
	***** Entrée : CMatrice<MType> MTPMATParam																	*****
	***** Nécessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraine : la fonction initialise une matrice du type spécifié avec une autre matrice du même type	*****
	*****************************************************************************************************************/
	CMatrice<MType>(const CMatrice<MType>& MTPMATParam);

	/****************************************************************************************************************
	***** CMatrice : constructeur de confort de la classe CMatrice												*****
	*****************************************************************************************************************
	***** Entrée : MType MTPElement, unsigned int uiLigne, unsigned int uiColonne								*****
	***** Nécessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraine : la fonction initialise une matrice du type spécifié remplie de l'élément en paramètre		*****
	*****************************************************************************************************************/
	CMatrice(MType MTPElement, const unsigned int uiLigne, const unsigned int uiColonne);

	/****************************************************************************************************************
	***** ~CMatrice : destructeur de la classe CMatrice															*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction désalloue l'espace mémoire attribué à un CMatrice							    *****
	*****************************************************************************************************************/
	~CMatrice<MType>();


	//Méthodes

	/****************************************************************************************************************
	***** MATLireElement : Accesseur en lecture d'un élément d'une matrice										*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiLigne, uiColonne tous deux fixés à 0 par défaut								*****
	***** Nécessite : Rien																						*****
	***** Sortie : MType																						*****
	***** Entraine : la fonction renvoie l'élément à la position demandé						  			  OU*****
	**************** Exception POSITION_INVALIDE : La position spécifée est en dehors des champs possibles		*****
	**************** pour cette matrice																		  OU*****
	**************** Exception MATRICE_VIDE : La matrice est vide												*****
	*****************************************************************************************************************/
	MType MATLireElement(unsigned int uiLigne = 0, unsigned int uiColonne = 0) const;

	/****************************************************************************************************************
	***** MATModifierElement : Accesseur en écriture d'un élément d'une matrice									*****
	*****************************************************************************************************************
	***** Entrée : MType MTPElement, unsigned int uiLigne, unsigned int uiColonne								*****
	***** Nécessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraine : la fonction modifie l'élément à la position demandé						  			  OU*****
	**************** Exception POSITION_INVALIDE : La position spécifée est en dehors des champs possibles		*****
	**************** pour cette matrice																		  OU*****
	**************** Exception MATRICE_VIDE : La matrice est vide												*****
	*****************************************************************************************************************/
	void MATModifierElement(MType MTPElement, unsigned int uiLigne, unsigned int uiColonne);

	/****************************************************************************************************************
	***** MATLireNbLignes : Accesseur en lecture de uiMATNbLigne (nombre de lignes de la matrice)				*****
	*****************************************************************************************************************
	***** Entrée : Rien																							*****
	***** Nécessite : Rien																						*****
	***** Sortie : unsigned int																					*****
	***** Entraine : la fonction renvoie le nombre de lignes de la matrice						  			    *****
	*****************************************************************************************************************/
	unsigned int MATLireNbLignes() const;

	/****************************************************************************************************************
	***** MATLireNbColonnes : Accesseur en lecture de uiMATNbColonne (nombre de colonnes de la matrice)			*****
	*****************************************************************************************************************
	***** Entrée : Rien																							*****
	***** Nécessite : Rien																						*****
	***** Sortie : unsigned int																					*****
	***** Entraine : la fonction renvoie le nombre de colonnes de la matrice						  		    *****
	*****************************************************************************************************************/
	unsigned int MATLireNbColonnes() const;

	/****************************************************************************************************************
	***** MATAfficherMatrice : Fonction permettant l'affichage d'ûne matrice sur le terminal					*****																								*****
	*****				Dans le cas où la matrice ne serait que partiellement ou non initialisée, les valeurs	*****
	*****				non initialisée seront affichées ainsi : NULL (à voir avec le prof)						*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : L'appel de la fonction ne peut être réalisé que sur une matrice d'un type de base, cela ne*****
	*****			  fonctionnera - si l'on est en présence d'une matrice d'objets - que si l'utilisateur a au *****
	*****			  préalable surchargé l'opérateur "<<" afin d'avoir l'affichage de son objet sur le terminal*****
	***** Sortie : Rien 							                                                            *****
	***** Entraine : la fonction affiche la matrice dans le terminal											*****
	*****************************************************************************************************************/
	void MATAfficherMatrice() const;

	/****************************************************************************************************************
	***** operator/ : Surcharge de l'opérateur / pour diviser une matrice par une constante						*****
	*****************************************************************************************************************
	***** Entrée : double dParam																				*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie le résultat de la division d'une matrice par une constante			  OU*****
	**************** Exception DIVISION_PAR_0 : On ne peut pas diviser une matrice par 0						*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator/(const double& dParam);

	/****************************************************************************************************************
	***** operator* : Surcharge de l'opérateur * pour multiplier une matrice par une constante					*****
	*****************************************************************************************************************
	***** Entrée : double dParam																				*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie le résultat de la multiplication d'une matrice par une constante		*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator*(const double& dParam);

	/****************************************************************************************************************
	***** operator* : Surcharge de l'opérateur * pour multiplier deux matrices									*****
	*****************************************************************************************************************
	***** Entrée : MType MTPMATParam																			*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie le résultat de la multiplication d'une matrice par une matrice			*****
	**************** Exception TAILLES_INCOMPATIBLES : Le nombre de lignes de la matrice à gauche de			*****
	**************** l'opérateur est différent du nombre de colonnes de la matrice à droite de l'opérateur		*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator*(const CMatrice<MType>& MTPMATParam);

	/****************************************************************************************************************
	***** operator+ : Surcharge de l'opérateur + pour multiplier deux matrices									*****
	*****************************************************************************************************************
	***** Entrée : MType MTPMATParam																			*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie le résultat de l'addition de deux matrices							  OU*****
	**************** Exception TAILLES_INCOMPATIBLES : Les deux matrices ne font pas la même taille				*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator+(const CMatrice<MType>& MTPMATParam);

	/****************************************************************************************************************
	***** operator- : Surcharge de l'opérateur - pour soustraire deux matrices									*****
	*****************************************************************************************************************
	***** Entrée : MType MTPMATParam																			*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : La fonction renvoie le résultat de la soustraction de deux matrices					  OU*****
	**************** Exception TAILLES_INCOMPATIBLES : Les deux matrices ne font pas la même taille				*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator-(const CMatrice<MType>& MTPMATParam);

	/****************************************************************************************************************
	***** operator= : Surcharge de l'opérateur d'affectation = 													*****
	*****************************************************************************************************************
	***** Entrée : MType MTPMATParam																			*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : La fonction initialise une matrice du type spécifié avec une autre matrice du même type    *****
	*****************************************************************************************************************/
	CMatrice<MType>& operator=(const CMatrice<MType>& MTPMATParam);
};

#include "CMatrice.ipp"