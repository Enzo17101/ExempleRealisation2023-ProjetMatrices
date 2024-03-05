#include "CMatrice.h"


/****************************************************************************************************************
***** operator* : Surcharge de l'op�rateur * pour multiplier un nombre et une matrice						*****
*****************************************************************************************************************
***** Entr�e : double dConstante, CMatrice<double> MATMatrice												*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie le r�sultat de la multiplication d'une matrice par une constante		*****
*****************************************************************************************************************/

template<class MType>
CMatrice<MType>& operator*(double dConstante, CMatrice<MType>& MTPMATParam)
{
	//cr�ation de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, MTPMATParam.MATLireNbLignes(), MTPMATParam.MATLireNbColonnes());
	
	//appel de la surcharge d'op�rateur * avec une constante de la classe CMatrice
	*MATResultat = MTPMATParam * dConstante;

	return *MATResultat;
}