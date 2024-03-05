#pragma once

#include "CMatrice.h"
#include "CException.h"

template <class MType> class COperationMatrice
{
public :
	/****************************************************************************************************************
	***** OMATransposee : Fonction effectuant la transpos�e d'une matrice										*****
	*****************************************************************************************************************
	***** Entr�e : CMatrice<MType>  MATMatrice																	*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie la transpos�e de la matrice							  				*****
	*****************************************************************************************************************/
	CMatrice<MType>& OMATransposee(CMatrice<MType> & MATMatrice);

	/****************************************************************************************************************
	***** OMAPermutationSimple : effectue les permutations simples d'une liste									*****
	*****************************************************************************************************************
	***** Entr�e : CMatrice<MType> MATSequence																	*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie une matrice des permutations simples de la liste						*****
	**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne						*****
	*****************************************************************************************************************/
	CMatrice<MType>& OMAPermutationSimple(CMatrice<MType> & MATSequence);

	/****************************************************************************************************************
	***** OMAPermutationComplete : effectue toutes les permutations possibles d'une liste avec l'algorithme		*****
	*****						   de Heap it�ratif																*****
	*****************************************************************************************************************
	***** Entr�e : CMatrice<MType> MATSequence																	*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie une matrice de toutes les permutations possibles de la liste			*****
	**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne						*****
	*****************************************************************************************************************/
	CMatrice<MType>& OMAPermutationComplete(CMatrice<MType>& MATSequence);

	/****************************************************************************************************************
	***** OMAPermutationPersonalisee : effectue des permutations personalis�es d'une matrice					*****
	*****************************************************************************************************************
	***** Entr�e : CMatrice<MType> MATSequence, CMatrice<unsigned int> MATDecalages								*****
	***** N�cessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie la permutation choisie en param�tre de la matrice				  	  OU*****
	**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne					  OU*****
	**************** Exception MAUVAISE_MATRICE_DECALAGE : La liste de d�calage n'est pas de la m�me taille que	*****
	**************** le nombre de lignes de la matrice en param�tre												*****
		*****************************************************************************************************************/
	CMatrice<MType>& OMAPermutationPersonnalisee(CMatrice<MType>& MATOriginale, CMatrice<unsigned int>& MATDecalages);
};

#include "COperationMatrice.ipp"