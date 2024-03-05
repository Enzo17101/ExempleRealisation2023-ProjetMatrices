#include "CMatrice.h"
#include "CIterateurFichier.h"

/****************************************************************************************************************
***** CMatrice : constructeur par d�faut de la classe CMatrice												*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise une matrice du type sp�cifi�									    *****
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
***** Entr�e : CMatrice<MType> MTPMATParam																	*****
***** N�cessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraine : la fonction initialise une matrice du type sp�cifi� avec une autre matrice du m�me type	*****
*****************************************************************************************************************/

template <class MType>
CMatrice<MType>::CMatrice<MType>(const CMatrice<MType>& MTPMATParam) 
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//recopie du nombre de lignes et colonnes de la matrice en param�tre
	uiMATNbColonnes = MTPMATParam.uiMATNbColonnes;
	uiMATNbLignes = MTPMATParam.uiMATNbLignes;

	//cr�ation d'un tableau � deux dimensions avec les dimensions de la matrice en param�tre
	ppMTPMATMatrice = new MType * [uiMATNbLignes];
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++) 
	{
		ppMTPMATMatrice[uiBoucleLigne] = new MType[uiMATNbColonnes];
	}

	//recopie de chaque valeur de la matrice en param�tre
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
***** Entr�e : MType MTPElement, unsigned int uiLigne, unsigned int uiColonne								*****
***** N�cessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraine : la fonction initialise une matrice du type sp�cifi� remplie de l'�l�ment en param�tre		*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>::CMatrice<MType>(MType MTPElement, const unsigned int uiLigne, const unsigned int uiColonne)
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//recopie du nombre de lignes et colonnes en param�tre
	uiMATNbLignes = uiLigne;
	uiMATNbColonnes = uiColonne;

	//cr�ation d'un tableau � deux dimensions avec les dimensions en param�tre
	ppMTPMATMatrice = new MType * [uiLigne];
	for (uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++) {
		ppMTPMATMatrice[uiBoucleLigne] = new MType[uiColonne];
	}

	//recopie de chaque valeur de la matrice en param�tre
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
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction d�salloue l'espace m�moire attribu� � un CMatrice							    *****
*****************************************************************************************************************/

template <class MType>
CMatrice<MType>::~CMatrice<MType>()
{
	unsigned int uiBoucle = 0;

	//supression de chaque �l�ment de la matrice 
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		delete ppMTPMATMatrice[uiBoucle];
	}

	//suppresion de l'objet
	delete ppMTPMATMatrice;
}


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

template<class MType>
inline MType CMatrice<MType>::MATLireElement(unsigned int uiLigne, unsigned int uiColonne) const
{
	//si la position sp�cif�e est en dehors des champs possibles pour cette matrice
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

template<class MType>
inline void CMatrice<MType>::MATModifierElement(MType MTPElement, unsigned int uiLigne, unsigned int uiColonne)
{
	//si la position sp�cif�e est en dehors des champs possibles pour cette matrice
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
***** Entr�e : Rien																							*****
***** N�cessite : Rien																						*****
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
***** Entr�e : Rien																							*****
***** N�cessite : Rien																						*****
***** Sortie : unsigned int																					*****
***** Entraine : la fonction renvoie le nombre de colonnes de la matrice						  		    *****
*****************************************************************************************************************/

template<class MType>
inline unsigned int CMatrice<MType>::MATLireNbColonnes() const
{
	return uiMATNbColonnes;
}


/****************************************************************************************************************
***** MATAfficherMatrice : Fonction permettant l'affichage d'�ne matrice sur le terminal					*****											*****
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

template<class MType>
inline void CMatrice<MType>::MATAfficherMatrice() const
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;
	
	//on parcourt la matrice pour afficher tous les �l�ments un par un
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
***** operator/ : Surcharge de l'op�rateur / pour diviser une matrice par une constante						*****
*****************************************************************************************************************
***** Entr�e : MType MTPParam																				*****
***** N�cessite : une surcharge de l'op�rateur "/" si l'utilisateur veut multiplier un objet				*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le r�sultat de la division d'une matrice par une constante			  OU*****
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

	//cr�ation de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, uiMATNbColonnes);

	//on affecte � chaque �l�ment de la matrice de retour l'�l�ment de la matrice de base divis� par le param�tre
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
***** operator* : Surcharge de l'op�rateur * pour multiplier une matrice par une constante					*****
*****************************************************************************************************************
***** Entr�e : MType MTPParam																				*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le r�sultat de la multiplication d'une matrice par une constante		*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator*(const double& dParam) 
{
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//cr�ation de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, uiMATNbColonnes);

	//on affecte � chaque �l�ment de la matrice de retour l'�l�ment de la matrice de base multipli� par le param�tre
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
***** operator* : Surcharge de l'op�rateur * pour multiplier deux matrices									*****
*****************************************************************************************************************
***** Entr�e : MType MTPMATParam																			*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le r�sultat de la multiplication d'une matrice par une matrice			*****
**************** Exception TAILLES_INCOMPATIBLES : Le nombre de lignes de la matrice � gauche de			*****
**************** l'op�rateur est diff�rent du nombre de colonnes de la matrice � droite de l'op�rateur		*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator*(const CMatrice<MType>& MTPMATParam) 
{
	//si le nombre de colonnes n'est pas �gale au nombre de lignes de la matrice en param�tre
	if (uiMATNbColonnes != MTPMATParam.uiMATNbLignes) {
		CException EXCErreur(TAILLES_INCOMPATIBLES);
		throw EXCErreur;
	}
	
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;
	unsigned int uiBoucle = 1;

	//cr�ation de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, MTPMATParam.uiMATNbColonnes);

	//on affecte � chaque �l�ment de la matrice de retour l'�l�ment de la matrice de base multipli� par l'�l�ment de la matrice en param�tre
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
***** operator+ : Surcharge de l'op�rateur + pour multiplier deux matrices									*****
*****************************************************************************************************************
***** Entr�e : MType MTPMATParam																			*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le r�sultat de l'addition de deux matrices							  OU*****
**************** Exception TAILLES_INCOMPATIBLES : Les deux matrices ne font pas la m�me taille				*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator+(const CMatrice<MType>& MTPMATParam) 
{
	//si les matrices ne font pas la m�me taille
	if (uiMATNbLignes != MTPMATParam.uiMATNbLignes || uiMATNbColonnes != MTPMATParam.uiMATNbColonnes) 
	{
		CException EXCErreur(TAILLES_INCOMPATIBLES);
		throw EXCErreur;
	}

	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//cr�ation de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, uiMATNbColonnes);

	//on affecte � chaque �l�ment de la matrice de retour l'�l�ment de la matrice de base additionn� par l'�l�ment de la matrice en param�tre
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
***** operator- : Surcharge de l'op�rateur - pour soustraire deux matrices									*****
*****************************************************************************************************************
***** Entr�e : MType MTPMATParam																			*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : La fonction renvoie le r�sultat de la soustraction de deux matrices					  OU*****
**************** Exception TAILLES_INCOMPATIBLES : Les deux matrices ne font pas la m�me taille				*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator-(const CMatrice<MType>& MTPMATParam) 
{
	//si les matrices ne font pas la m�me taille
	if (uiMATNbLignes != MTPMATParam.uiMATNbLignes || uiMATNbColonnes != MTPMATParam.uiMATNbColonnes)
	{
		CException EXCErreur(TAILLES_INCOMPATIBLES);
		throw EXCErreur;
	}

	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//cr�ation de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiMATNbLignes, uiMATNbColonnes);

	//on affecte � chaque �l�ment de la matrice de retour l'�l�ment de la matrice de base soustrait par l'�l�ment de la matrice en param�tre
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
***** operator= : Surcharge de l'op�rateur d'affectation = 													*****
*****************************************************************************************************************
***** Entr�e : MType MTPMATParam																			*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : La fonction initialise une matrice du type sp�cifi� avec une autre matrice du m�me type    *****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& CMatrice<MType>::operator=(const CMatrice<MType>& MTPMATParam) 
{

	//desallocation de l'espace m�moire pr�c�dement attribu� � ppMTPMATMatrice
	unsigned int uiBoucle = 0;

	//supression de chaque �l�ment de la matrice 
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		delete ppMTPMATMatrice[uiBoucle];
	}

	//suppresion de l'objet

	delete ppMTPMATMatrice;

	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//recopie du nombre de lignes et colonnes de la matrice en param�tre
	uiMATNbColonnes = MTPMATParam.uiMATNbColonnes;
	uiMATNbLignes = MTPMATParam.uiMATNbLignes;

	//cr�ation d'un tableau � deux dimensions avec les dimensions de la matrice en param�tre
	ppMTPMATMatrice = new MType * [uiMATNbLignes];
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		ppMTPMATMatrice[uiBoucleLigne] = new MType[uiMATNbColonnes];
	}

	//recopie de chaque valeur de la matrice en param�tre
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
		{
			ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne] = MTPMATParam.ppMTPMATMatrice[uiBoucleLigne][uiBoucleColonne];
		}
	}

	return *this;
}