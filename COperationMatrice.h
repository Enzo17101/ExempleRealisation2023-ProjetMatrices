#pragma once

#include "CMatrice.h"
#include "CException.h"

template <class MType> class COperationMatrice
{
public :
	/****************************************************************************************************************
	***** OMATransposee : Fonction effectuant la transposée d'une matrice										*****
	*****************************************************************************************************************
	***** Entrée : CMatrice<MType>  MATMatrice																	*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie la transposée de la matrice							  				*****
	*****************************************************************************************************************/
	CMatrice<MType>& OMATransposee(CMatrice<MType> & MATMatrice);

	/****************************************************************************************************************
	***** OMAPermutationSimple : effectue les permutations simples d'une liste									*****
	*****************************************************************************************************************
	***** Entrée : CMatrice<MType> MATSequence																	*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie une matrice des permutations simples de la liste						*****
	**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne						*****
	*****************************************************************************************************************/
	CMatrice<MType>& OMAPermutationSimple(CMatrice<MType> & MATSequence);

	/****************************************************************************************************************
	***** OMAPermutationComplete : effectue toutes les permutations possibles d'une liste avec l'algorithme		*****
	*****						   de Heap itératif																*****
	*****************************************************************************************************************
	***** Entrée : CMatrice<MType> MATSequence																	*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie une matrice de toutes les permutations possibles de la liste			*****
	**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne						*****
	*****************************************************************************************************************/
	CMatrice<MType>& OMAPermutationComplete(CMatrice<MType>& MATSequence);

	/****************************************************************************************************************
	***** OMAPermutationPersonalisee : effectue des permutations personalisées d'une matrice					*****
	*****************************************************************************************************************
	***** Entrée : CMatrice<MType> MATSequence, CMatrice<unsigned int> MATDecalages								*****
	***** Nécessite : Rien																						*****
	***** Sortie : CMatrice<MType>																				*****
	***** Entraine : la fonction renvoie la permutation choisie en paramètre de la matrice				  	  OU*****
	**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne					  OU*****
	**************** Exception MAUVAISE_MATRICE_DECALAGE : La liste de décalage n'est pas de la même taille que	*****
	**************** le nombre de lignes de la matrice en paramètre												*****
		*****************************************************************************************************************/
	CMatrice<MType>& OMAPermutationPersonnalisee(CMatrice<MType>& MATOriginale, CMatrice<unsigned int>& MATDecalages);
};

#include "COperationMatrice.ipp"