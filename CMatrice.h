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
	***** CMatrice : constructeur par d�faut de la classe CMatrice												*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une matrice du type sp�cifi�									    *****
	*****************************************************************************************************************/
	CMatrice<MType>();

	/****************************************************************************************************************
	***** CMatrice : constructeur de recopie de la classe CMatrice												*****
	*****************************************************************************************************************
	***** Entr�e : CMatrice<MType> MTPMATParam																	*****
	***** N�cessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraine : la fonction initialise une matrice du type sp�cifi� avec une autre matrice du m�me type	*****
	*****************************************************************************************************************/
	CMatrice<MType>(const CMatrice<MType>& MTPMATParam);

	/****************************************************************************************************************
	***** CMatrice : constructeur de confort de la classe CMatrice												*****
	*****************************************************************************************************************
	***** Entr�e : MType MTPElement, unsigned int uiLigne, unsigned int uiColonne								*****
	***** N�cessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraine : la fonction initialise une matrice du type sp�cifi� remplie de l'�l�ment en param�tre		*****
	*****************************************************************************************************************/
	CMatrice(MType MTPElement, const unsigned int uiLigne, const unsigned int uiColonne);

	/****************************************************************************************************************
	***** ~CMatrice : destructeur de la classe CMatrice															*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction d�salloue l'espace m�moire attribu� � un CMatrice							    *****
	*****************************************************************************************************************/
	~CMatrice<MType>();


	//M�thodes

	/****************************************************************************************************************
	***** MATLireElement : Accesseur en lecture d'un �l�ment d'une matrice										*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiLigne, uiColonne tous deux fix�s � 0 par d�faut								*****
	***** N�cessite : Rien																						*****
	***** Sortie : MType																						*****
	***** Entraine : la fonction renvoie l'�l�ment � la position demand�						  			  OU*****
	**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors des champs possibles		*****
	**************** pour cette matrice																		  OU*****
	**************** Exception MATRICE_VIDE : La matrice est vide												*****
	*****************************************************************************************************************/
	MType MATLireElement(unsigned int uiLigne = 0, unsigned int uiColonne = 0) const;

	/****************************************************************************************************************
	***** MATModifierElement : Accesseur en �criture d'un �l�ment d'une matrice									*****
	*****************************************************************************************************************
	***** Entr�e : MType MTPElement, unsigned int uiLigne, unsigned int uiColonne								*****
	***** N�cessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraine : la fonction modifie l'�l�ment � la position demand�						  			  OU*****
	**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors des champs possibles		*****
	**************** pour cette matrice																		  OU*****
	**************** Exception MATRICE_VIDE : La matrice est vide												*****
	*****************************************************************************************************************/
	void MATModifierElement(MType MTPElement, unsigned int uiLigne, unsigned int uiColonne);

	/****************************************************************************************************************
	***** MATLireNbLignes : Accesseur en lecture de uiMATNbLigne (nombre de lignes de la matrice)				*****
	*****************************************************************************************************************
	***** Entr�e : Rien																							*****
	***** N�cessite : Rien																						*****
	***** Sortie : unsigned int																					*****
	***** Entraine : la fonction renvoie le nombre de lignes de la matrice						  			    *****
	*****************************************************************************************************************/
	unsigned int MATLireNbLignes() const;

	/****************************************************************************************************************
	***** MATLireNbColonnes : Accesseur en lecture de uiMATNbColonne (nombre de colonnes de la matrice)			*****
	*****************************************************************************************************************
	***** Entr�e : Rien																							*****
	***** N�cessite : Rien																						*****
	***** Sortie : unsigned int																					*****
	***** Entraine : la fonction renvoie le nombre de colonnes de la matrice						  		    *****
	*****************************************************************************************************************/
	unsigned int MATLireNbColonnes() const;

	/****************************************************************************************************************
	***** MATAfficherMatrice : Fonction permettant l'affichage d'�ne matrice sur le terminal					*****																								*****
	*****				Dans le cas o� la matrice ne serait que partiellement ou non initialis�e, les valeurs	*****
	*****				non initialis�e seront affich�es ainsi : NULL (� voir avec le prof)						*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : L'appel de la fonction ne peut �tre r�alis� que sur une matrice d'un type de base, cela ne*****
	*****			  fonctionnera - si l'on est en pr�sence d'une matrice d'objets - que si l'utilisateur a au *****
	*****			  pr�alable surcharg� l'op�rateur "<<" afin d'avoir l'affichage de son objet sur le terminal*****
	***** Sortie : Rien 							                                                            *****
	***** Entraine : la fonction affiche la matrice dans le terminal											*****
	*****************************************************************************************************************/
	void MATAfficherMatrice() const;

	/****************************************************************************************************************
	***** operator/ : Surcharge de l'op�rateur / pour diviser une matrice par une constante						*****
	*****************************************************************************************************************
	***** Entr�e : double dParam																				*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie le r�sultat de la division d'une matrice par une constante			  OU*****
	**************** Exception DIVISION_PAR_0 : On ne peut pas diviser une matrice par 0						*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator/(const double& dParam);

	/****************************************************************************************************************
	***** operator* : Surcharge de l'op�rateur * pour multiplier une matrice par une constante					*****
	*****************************************************************************************************************
	***** Entr�e : double dParam																				*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie le r�sultat de la multiplication d'une matrice par une constante		*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator*(const double& dParam);

	/****************************************************************************************************************
	***** operator* : Surcharge de l'op�rateur * pour multiplier deux matrices									*****
	*****************************************************************************************************************
	***** Entr�e : MType MTPMATParam																			*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie le r�sultat de la multiplication d'une matrice par une matrice			*****
	**************** Exception TAILLES_INCOMPATIBLES : Le nombre de lignes de la matrice � gauche de			*****
	**************** l'op�rateur est diff�rent du nombre de colonnes de la matrice � droite de l'op�rateur		*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator*(const CMatrice<MType>& MTPMATParam);

	/****************************************************************************************************************
	***** operator+ : Surcharge de l'op�rateur + pour multiplier deux matrices									*****
	*****************************************************************************************************************
	***** Entr�e : MType MTPMATParam																			*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie le r�sultat de l'addition de deux matrices							  OU*****
	**************** Exception TAILLES_INCOMPATIBLES : Les deux matrices ne font pas la m�me taille				*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator+(const CMatrice<MType>& MTPMATParam);

	/****************************************************************************************************************
	***** operator- : Surcharge de l'op�rateur - pour soustraire deux matrices									*****
	*****************************************************************************************************************
	***** Entr�e : MType MTPMATParam																			*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : La fonction renvoie le r�sultat de la soustraction de deux matrices					  OU*****
	**************** Exception TAILLES_INCOMPATIBLES : Les deux matrices ne font pas la m�me taille				*****
	*****************************************************************************************************************/
	CMatrice<MType> & operator-(const CMatrice<MType>& MTPMATParam);

	/****************************************************************************************************************
	***** operator= : Surcharge de l'op�rateur d'affectation = 													*****
	*****************************************************************************************************************
	***** Entr�e : MType MTPMATParam																			*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : La fonction initialise une matrice du type sp�cifi� avec une autre matrice du m�me type    *****
	*****************************************************************************************************************/
	CMatrice<MType>& operator=(const CMatrice<MType>& MTPMATParam);
};

#include "CMatrice.ipp"