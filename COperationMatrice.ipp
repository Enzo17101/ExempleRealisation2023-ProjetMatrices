#include "COperationMatrice.h"


/****************************************************************************************************************
***** OMATransposee : Fonction effectuant la transposée d'une matrice										*****
*****************************************************************************************************************
***** Entrée : Rien																							*****
***** Nécessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie la transposée de la matrice							  				*****
*****************************************************************************************************************/

template<class MType>
inline CMatrice<MType>& COperationMatrice<MType>::OMATransposee(CMatrice<MType>& MATMatrice)
{
	//Variables de boucle afin de parcourir la matrice
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//Puisqu'on l'utilisera plusieurs fois on initialise des variables avec le nombre de lignes et colonnes de la matrice
	unsigned int uiNbLignes = MATMatrice.MATLireNbLignes();
	unsigned int uiNbColonnes = MATMatrice.MATLireNbColonnes();

	//Création de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiNbColonnes, uiNbLignes);

	//On affecte à chaque élément de la matrice de retour la valeur symétrique à la diagonale de la matrice de base
	for (uiBoucleLigne = 0; uiBoucleLigne < uiNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiNbColonnes; uiBoucleColonne++)
		{
			MATResultat->MATModifierElement(MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne), uiBoucleColonne, uiBoucleLigne);
		}
	}

	return *MATResultat;
}


/****************************************************************************************************************
***** OMAPermutationSimple : effectue les permutations simples d'une liste									*****
*****************************************************************************************************************
***** Entrée : CMatrice<MType> MATSequence																	*****
***** Nécessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie une matrice des permutations simples de la liste						*****
**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne						*****
*****************************************************************************************************************/

template<class MType>
inline CMatrice<MType>& COperationMatrice<MType>::OMAPermutationSimple(CMatrice<MType>& MATSequence)
{
	//Nombre de valeurs contenues dans la séquence, et donc permutations à réaliser
	unsigned int uiNombreValeurs = MATSequence.MATLireNbColonnes();

	//Variables de boucle utiles au parcours de la matrice
	unsigned int uiBoucleValeur = 0;
	unsigned int uiBoucleDecalage = 0;

	//Vérification de si l'on fourni bien une séquence de nombre et non une matrice à avec plusieurs lignes
	if (MATSequence.MATLireNbLignes() > 1)
	{
		CException EXCException(MATRICE_NON_LIGNE);
		throw EXCException;
	}

	//Matrice retournée à la fin de la fonction
	CMatrice<MType>* pMATMatrice = new CMatrice<MType>((MType)0, uiNombreValeurs, uiNombreValeurs);

	//On affecte à chaque position de la matrice les valeurs de la séquence, et se décalant de la valeur du numéro de la ligne (0 pour la première, n-1 pour la dernière)
	for (uiBoucleDecalage = 0; uiBoucleDecalage < uiNombreValeurs; uiBoucleDecalage++)
	{
		for (uiBoucleValeur = 0; uiBoucleValeur < uiNombreValeurs; uiBoucleValeur++)
		{
			pMATMatrice->MATModifierElement(MATSequence.MATLireElement(0, uiBoucleValeur), uiBoucleDecalage, (uiBoucleValeur + uiBoucleDecalage) % uiNombreValeurs);
		}
	}

	return *pMATMatrice;
}


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

template<class MType>
inline CMatrice<MType>& COperationMatrice<MType>::OMAPermutationComplete(CMatrice<MType>& MATSequence)
{
	//Vérification de si l'on fourni bien une séquence de nombre et non une matrice à avec plusieurs lignes
	if (MATSequence.MATLireNbLignes() > 1)
	{
		CException EXCException(MATRICE_NON_LIGNE);
		throw EXCException;
	}

	//Puisqu'on l'utilisera plusieurs fois on initialise des variables avec le nombre de lignes et colonnes de la matrice
	unsigned int uiNombreValeurs = MATSequence.MATLireNbColonnes();
	unsigned int uiNombrePermutations = 1;

	//Variables de boucle utiles au parcours de la matrice
	unsigned int uiBoucleFactorielle;
	unsigned int uiBoucleCopie;
	unsigned int uiBoucleCompteur;

	//Variables utiles à l'alorithme de heap
	unsigned int uiNiveauIncrementation = 0;
	unsigned int uiCompteurLigne = 1;
	MType MTPRecopie;
	MType MTPSauvegarde;
	int* piCompteur = new int[uiNombreValeurs];

	//Calcul du nombre de lignes de la matrice qui est égal à la factorielle du nombres de valeurs
	for (uiBoucleFactorielle = 1; uiBoucleFactorielle <= uiNombreValeurs; uiBoucleFactorielle++)
	{
		uiNombrePermutations = uiNombrePermutations * uiBoucleFactorielle;
	}

	//Matrice retournée à la fin de la fonction
	CMatrice<MType>* pMATMatrice = new CMatrice<MType>((MType)0, uiNombrePermutations, uiNombreValeurs);

	//Recopie de la première ligne
	for (uiBoucleCopie = 0; uiBoucleCopie < uiNombreValeurs; uiBoucleCopie++)
	{
		MTPRecopie = MATSequence.MATLireElement(0, uiBoucleCopie);
		pMATMatrice->MATModifierElement(MTPRecopie, 0, uiBoucleCopie);
	}

	//Initialisation du compteur à 0
	for (uiBoucleCompteur = 0; uiBoucleCompteur < uiNombreValeurs; uiBoucleCompteur++)
	{
		piCompteur[uiBoucleCompteur] = 0;
	}


	while (uiNiveauIncrementation < uiNombreValeurs)
	{
		if (piCompteur[uiNiveauIncrementation] < uiNiveauIncrementation)
		{
			//Recopie de la ligne précédente
			for (uiBoucleCopie = 0; uiBoucleCopie < uiNombreValeurs; uiBoucleCopie++)
			{
				pMATMatrice->MATModifierElement(pMATMatrice->MATLireElement(uiCompteurLigne - 1, uiBoucleCopie), uiCompteurLigne, uiBoucleCopie);
			}

			//Permutation différentes selon la parité du niveau d'incrémentation
			if (uiNiveauIncrementation % 2 == 0)
			{
				//On sauvegarde un des deux éléments que l'on veut permutter, puisqu'il sera remplacé par l'autre
				MTPSauvegarde = pMATMatrice->MATLireElement(uiCompteurLigne, 0);

				//On remplace le second élément par le premier
				pMATMatrice->MATModifierElement(pMATMatrice->MATLireElement(uiCompteurLigne, uiNiveauIncrementation), uiCompteurLigne, 0);

				//Puis le premier par le second, sauvegardé précédemment
				pMATMatrice->MATModifierElement(MTPSauvegarde, uiCompteurLigne, uiNiveauIncrementation);
			}
			else
			{
				//On sauvegarde un des deux éléments que l'on veut permutter, puisqu'il sera remplacé par l'autre
				MTPSauvegarde = pMATMatrice->MATLireElement(uiCompteurLigne, piCompteur[uiNiveauIncrementation]);

				//On remplace le second élément par le premier
				pMATMatrice->MATModifierElement(pMATMatrice->MATLireElement(uiCompteurLigne, uiNiveauIncrementation), uiCompteurLigne, piCompteur[uiNiveauIncrementation]);
				//Puis le premier par le second, sauvegardé précédemment
				pMATMatrice->MATModifierElement(MTPSauvegarde, uiCompteurLigne, uiNiveauIncrementation);
			}

			//Incrémentation des deux compteurs
			piCompteur[uiNiveauIncrementation]++;
			uiCompteurLigne++;

			//Réinitialisation du niveau d'incrémentation
			uiNiveauIncrementation = 0;

		}
		else
		{
			//Réinitialisation du compteur
			piCompteur[uiNiveauIncrementation] = 0;

			//Incrémentation du niveau d'incrémentation
			uiNiveauIncrementation++;
		}
	}

	return *pMATMatrice;
}


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

template<class MType>
inline CMatrice<MType>& COperationMatrice<MType>::OMAPermutationPersonnalisee(CMatrice<MType>& MATOriginale, CMatrice<unsigned int>& MATDecalages)
{
	//Puisqu'on l'utilisera plusieurs fois on initialise des variables avec le nombre de lignes et colonnes de la matrice
	unsigned int uiNombreLignes = MATOriginale.MATLireNbLignes();
	unsigned int uiNombreColonnes = MATOriginale.MATLireNbColonnes();

	//Variables de boucle utile au parcours de la matrice
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//Vérification de si l'on fourni bien une séquence de nombre et non une matrice à avec plusieurs lignes
	if (MATDecalages.MATLireNbLignes() > 1)
	{
		CException EXCException(MATRICE_NON_LIGNE);
		throw EXCException;
	}

	//Vérification de si la séquence de décalages comporte bien le bon nombre de décalages
	if (uiNombreLignes != MATDecalages.MATLireNbColonnes())
	{
		CException EXCException(MAUVAISE_MATRICE_DECALAGE);
		throw EXCException;
	}

	//Initialisation de la matrice retournée par la fonction
	CMatrice<MType>* pMATMatrice = new CMatrice<MType>(0, uiNombreLignes, uiNombreColonnes);

	for (uiBoucleLigne = 0; uiBoucleLigne < uiNombreLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiNombreColonnes; uiBoucleColonne++)
		{
			//On suit le même principe que pour les permutation simple, mais en décalant du nombre de décalage spécifé au n-ième nombre de la séquence
			pMATMatrice->MATModifierElement(MATOriginale.MATLireElement(uiBoucleLigne, uiBoucleColonne), uiBoucleLigne, (MATDecalages.MATLireElement(0, uiBoucleLigne) + uiBoucleColonne) % uiNombreColonnes);
		}
	}

	return *pMATMatrice;
}
