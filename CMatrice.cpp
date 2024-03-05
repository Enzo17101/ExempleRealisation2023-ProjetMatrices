#include "CMatrice.h"


/****************************************************************************************************************
***** operator* : Surcharge de l'opérateur * pour multiplier un nombre et une matrice						*****
*****************************************************************************************************************
***** Entrée : double dConstante, CMatrice<double> MATMatrice												*****
***** Nécessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le résultat de la multiplication d'une matrice par une constante		*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& operator*(double dConstante, CMatrice<MType>& MTPMATParam)
{
	//création de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, MTPMATParam.MATLireNbLignes(), MTPMATParam.MATLireNbColonnes());
	
	//appel de la surcharge d'opérateur * avec une constante de la classe CMatrice
	*MATResultat = MTPMATParam * dConstante;

	return *MATResultat;
}