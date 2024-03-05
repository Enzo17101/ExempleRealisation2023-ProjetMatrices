#include "CMatrice.h"
#include "CIterateurFichier.h"

/****************************************************************************************************************
***** CMatrice : constructeur par défaut de la classe CMatrice												*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise une matrice du type spécifié									    *****
*****************************************************************************************************************/

template <class MType>
CMatrice<MType>::CMatrice<MType>()
{
	uiMATNbLignes = 0;
	uiMATNbColonnes = 0;
	ppMTPMATMatrice = nullptr;
}


/****************************************************************************************************************
***** CMatrice : constructeur de recopie de la classe CMatrice												*****
*****************************************************************************************************************
***** Entrée : CMatrice<MType> MTPMATParam																	*****
***** Nécessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraine : la fonction initialise une matrice du type spécifié avec une autre matrice du même type	*****
*****************************************************************************************************************/

template <class MType>
CMatrice<MType>::CMatrice<MType>(const CMatrice<MType>& MTPMATParam) 
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//recopie du nombre de lignes et colonnes de la matrice en paramètre
	uiMATNbColonnes = MTPMATParam.uiMATNbColonnes;
	uiMATNbLignes = MTPMATParam.uiMATNbLignes;

	//création d'un tableau à deux dimensions avec les dimensions de la matrice en paramètre
	ppMTPMATMatrice = new MType * [uiMATNbLignes];
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++) 
	{
		ppMTPMATMatrice[uiBoucleLigne] = new MType[uiMATNbColonnes];
	}

	//recopie de chaque valeur de la matrice en paramètre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++) 
		{
			ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne] = MTPMATParam.ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne];
		}
	}
}


/****************************************************************************************************************
***** CMatrice : constructeur de confort de la classe CMatrice												*****
*****************************************************************************************************************
***** Entrée : MType MTPElement, unsigned int uiLigne, unsigned int uiColonne								*****
***** Nécessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraine : la fonction initialise une matrice du type spécifié remplie de l'élément en paramètre		*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>::CMatrice<MType>(MType MTPElement, const unsigned int uiLigne, const unsigned int uiColonne)
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//recopie du nombre de lignes et colonnes en paramètre
	uiMATNbLignes = uiLigne;
	uiMATNbColonnes = uiColonne;

	//création d'un tableau à deux dimensions avec les dimensions en paramètre
	ppMTPMATMatrice = new MType * [uiLigne];
	for (uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++) {
		ppMTPMATMatrice[uiBoucleLigne] = new MType[uiColonne];
	}

	//recopie de chaque valeur de la matrice en paramètre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne] = MTPElement;
		}
	}
}


/****************************************************************************************************************
***** ~CMatrice : destructeur de la classe CMatrice															*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction désalloue l'espace mémoire attribué à un CMatrice							    *****
*****************************************************************************************************************/

template <class MType>
CMatrice<MType>::~CMatrice<MType>()
{
	unsigned int uiBoucle = 0;

	//supression de chaque élément de la matrice 
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		delete ppMTPMATMatrice[uiBoucle];
	}

	//suppresion de l'objet
	delete ppMTPMATMatrice;
}


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

template<class MType>
inline MType CMatrice<MType>::MATLireElement(unsigned int uiLigne, unsigned int uiColonne) const
{
	//si la position spécifée est en dehors des champs possibles pour cette matrice
	if (uiLigne >= uiMATNbLignes || uiColonne >= uiMATNbColonnes)
	{
		CException EXCException;
		EXCException.EXCModifierValeur(POSITION_INVALIDE);
		throw EXCException;
	}

	//si la matrice est vide
	if (uiMATNbLignes == 0 || uiMATNbColonnes == 0)
	{
		CException EXCException;
		EXCException.EXCModifierValeur(MATRICE_VIDE);
		throw EXCException;
	}

	return ppMTPMATMatrice[uiLigne][uiColonne];
}


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

template<class MType>
inline void CMatrice<MType>::MATModifierElement(MType MTPElement, unsigned int uiLigne, unsigned int uiColonne)
{
	//si la position spécifée est en dehors des champs possibles pour cette matrice
	if (uiLigne >= uiMATNbLignes || uiColonne >= uiMATNbColonnes)
	{
		CException EXCException(POSITION_INVALIDE);
		throw EXCException;
	}

	//si la matrice est vide
	if (uiMATNbLignes == 0 || uiMATNbColonnes == 0)
	{
		CException EXCException(MATRICE_VIDE);
		throw EXCException;
	}

	ppMTPMATMatrice[uiLigne][uiColonne] = MTPElement;
}


/****************************************************************************************************************
***** MATLireNbLignes : Accesseur en lecture de uiMATNbLignes (nombre de lignes de la matrice)				*****
*****************************************************************************************************************
***** Entrée : Rien																							*****
***** Nécessite : Rien																						*****
***** Sortie : unsigned int																					*****
***** Entraine : la fonction renvoie le nombre de lignes de la matrice						  			    *****
*****************************************************************************************************************/

template<class MType>
inline unsigned int CMatrice<MType>::MATLireNbLignes() const
{
	return uiMATNbLignes;
}


/****************************************************************************************************************
***** MATLireNbColonnes : Accesseur en lecture de uiMATNbColonnes (nombre de colonnes de la matrice)		*****
*****************************************************************************************************************
***** Entrée : Rien																							*****
***** Nécessite : Rien																						*****
***** Sortie : unsigned int																					*****
***** Entraine : la fonction renvoie le nombre de colonnes de la matrice						  		    *****
*****************************************************************************************************************/

template<class MType>
inline unsigned int CMatrice<MType>::MATLireNbColonnes() const
{
	return uiMATNbColonnes;
}


/****************************************************************************************************************
***** MATAfficherMatrice : Fonction permettant l'affichage d'ûne matrice sur le terminal					*****											*****
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

template<class MType>
inline void CMatrice<MType>::MATAfficherMatrice() const
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;
	
	//on parcourt la matrice pour afficher tous les éléments un par un
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			std::cout << MATLireElement(uiBoucleLigne, uiBoucleColonne) << " ";
		}
		std::cout << '\n';
	}
}


/****************************************************************************************************************
***** operator/ : Surcharge de l'opérateur / pour diviser une matrice par une constante						*****
*****************************************************************************************************************
***** Entrée : MType MTPParam																				*****
***** Nécessite : une surcharge de l'opérateur "/" si l'utilisateur veut multiplier un objet				*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le résultat de la division d'une matrice par une constante			  OU*****
**************** Exception DIVISION_PAR_0 : On ne peut pas diviser une matrice par 0						*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator/(const double& dParam)
{
	//si on essaie de diviser par 0
	if (dParam == 0)
	{
		CException EXCErreur(DIVISION_PAR_0);
		throw EXCErreur;
	}

	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//création de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, uiMATNbColonnes);

	//on affecte à chaque élément de la matrice de retour l'élément de la matrice de base divisé par le paramètre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			MATResultat->MATModifierElement(ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne] / dParam, uiBoucleLigne, uiBoucleColonne);
		}
	}

	return *MATResultat;
}


/****************************************************************************************************************
***** operator* : Surcharge de l'opérateur * pour multiplier une matrice par une constante					*****
*****************************************************************************************************************
***** Entrée : MType MTPParam																				*****
***** Nécessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le résultat de la multiplication d'une matrice par une constante		*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator*(const double& dParam) 
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//création de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, uiMATNbColonnes);

	//on affecte à chaque élément de la matrice de retour l'élément de la matrice de base multiplié par le paramètre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			MATResultat->MATModifierElement(ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne] * dParam, uiBoucleLigne, uiBoucleColonne);
		}
	}

	return *MATResultat;
}


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

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator*(const CMatrice<MType>& MTPMATParam) 
{
	//si le nombre de colonnes n'est pas égale au nombre de lignes de la matrice en paramètre
	if (uiMATNbColonnes != MTPMATParam.uiMATNbLignes) {
		CException EXCErreur(TAILLES_INCOMPATIBLES);
		throw EXCErreur;
	}
	
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;
	unsigned int uiBoucle = 1;

	//création de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, MTPMATParam.uiMATNbColonnes);

	//on affecte à chaque élément de la matrice de retour l'élément de la matrice de base multiplié par l'élément de la matrice en paramètre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < MTPMATParam.uiMATNbColonnes; uiBoucleColonne++)
		{
			MType MTPElement = ppMTPMATMatrice[uiBoucleLigne][0] * MTPMATParam.ppMTPMATMatrice[0][uiBoucleColonne];
			for (uiBoucle = 1; uiBoucle < uiMATNbColonnes; uiBoucle++) 
			{
				MTPElement = MTPElement + ppMTPMATMatrice[uiBoucleLigne][uiBoucle] * MTPMATParam.ppMTPMATMatrice[uiBoucle][uiBoucleColonne];
			}

			MATResultat->MATModifierElement(MTPElement, uiBoucleLigne, uiBoucleColonne);
		}
	}

	return *MATResultat;
}


/****************************************************************************************************************
***** operator+ : Surcharge de l'opérateur + pour multiplier deux matrices									*****
*****************************************************************************************************************
***** Entrée : MType MTPMATParam																			*****
***** Nécessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le résultat de l'addition de deux matrices							  OU*****
**************** Exception TAILLES_INCOMPATIBLES : Les deux matrices ne font pas la même taille				*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator+(const CMatrice<MType>& MTPMATParam) 
{
	//si les matrices ne font pas la même taille
	if (uiMATNbLignes != MTPMATParam.uiMATNbLignes || uiMATNbColonnes != MTPMATParam.uiMATNbColonnes) 
	{
		CException EXCErreur(TAILLES_INCOMPATIBLES);
		throw EXCErreur;
	}

	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//création de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, uiMATNbColonnes);

	//on affecte à chaque élément de la matrice de retour l'élément de la matrice de base additionné par l'élément de la matrice en paramètre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			MATResultat->MATModifierElement(ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne] + MTPMATParam.ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne], uiBoucleLigne, uiBoucleColonne);
		}
	}

	return *MATResultat;
}


/****************************************************************************************************************
***** operator- : Surcharge de l'opérateur - pour soustraire deux matrices									*****
*****************************************************************************************************************
***** Entrée : MType MTPMATParam																			*****
***** Nécessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : La fonction renvoie le résultat de la soustraction de deux matrices					  OU*****
**************** Exception TAILLES_INCOMPATIBLES : Les deux matrices ne font pas la même taille				*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator-(const CMatrice<MType>& MTPMATParam) 
{
	//si les matrices ne font pas la même taille
	if (uiMATNbLignes != MTPMATParam.uiMATNbLignes || uiMATNbColonnes != MTPMATParam.uiMATNbColonnes)
	{
		CException EXCErreur(TAILLES_INCOMPATIBLES);
		throw EXCErreur;
	}

	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//création de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, uiMATNbColonnes);

	//on affecte à chaque élément de la matrice de retour l'élément de la matrice de base soustrait par l'élément de la matrice en paramètre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			MATResultat->MATModifierElement(ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne] - MTPMATParam.ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne], uiBoucleLigne, uiBoucleColonne);
		}
	}

	return *MATResultat;
}


/****************************************************************************************************************
***** operator= : Surcharge de l'opérateur d'affectation = 													*****
*****************************************************************************************************************
***** Entrée : MType MTPMATParam																			*****
***** Nécessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : La fonction initialise une matrice du type spécifié avec une autre matrice du même type    *****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator=(const CMatrice<MType>& MTPMATParam) 
{

	//desallocation de l'espace mémoire précédement attribué à ppMTPMATMatrice
	unsigned int uiBoucle = 0;

	//supression de chaque élément de la matrice 
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		delete ppMTPMATMatrice[uiBoucle];
	}

	//suppresion de l'objet

	delete ppMTPMATMatrice;

	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//recopie du nombre de lignes et colonnes de la matrice en paramètre
	uiMATNbColonnes = MTPMATParam.uiMATNbColonnes;
	uiMATNbLignes = MTPMATParam.uiMATNbLignes;

	//création d'un tableau à deux dimensions avec les dimensions de la matrice en paramètre
	ppMTPMATMatrice = new MType * [uiMATNbLignes];
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		ppMTPMATMatrice[uiBoucleLigne] = new MType[uiMATNbColonnes];
	}

	//recopie de chaque valeur de la matrice en paramètre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne] = MTPMATParam.ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne];
		}
	}

	return *this;
}