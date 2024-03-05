#include "COperationMatrice.h"


/****************************************************************************************************************
***** OMATransposee : Fonction effectuant la transpos�e d'une matrice										*****
*****************************************************************************************************************
***** Entr�e : Rien																							*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie la transpos�e de la matrice							  				*****
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

	//Cr�ation de la matrice de retour
	CMatrice<MType>* MATResultat = new CMatrice<MType>(0, uiNbColonnes, uiNbLignes);

	//On affecte � chaque �l�ment de la matrice de retour la valeur sym�trique � la diagonale de la matrice de base
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
***** Entr�e : CMatrice<MType> MATSequence																	*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie une matrice des permutations simples de la liste						*****
**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne						*****
*****************************************************************************************************************/

template<class MType>
inline CMatrice<MType>& COperationMatrice<MType>::OMAPermutationSimple(CMatrice<MType>& MATSequence)
{
	//Nombre de valeurs contenues dans la s�quence, et donc permutations � r�aliser
	unsigned int uiNombreValeurs = MATSequence.MATLireNbColonnes();

	//Variables de boucle utiles au parcours de la matrice
	unsigned int uiBoucleValeur = 0;
	unsigned int uiBoucleDecalage = 0;

	//V�rification de si l'on fourni bien une s�quence de nombre et non une matrice � avec plusieurs lignes
	if (MATSequence.MATLireNbLignes() > 1)
	{
		CException EXCException(MATRICE_NON_LIGNE);
		throw EXCException;
	}

	//Matrice retourn�e � la fin de la fonction
	CMatrice<MType>* pMATMatrice = new CMatrice<MType>((MType)0, uiNombreValeurs, uiNombreValeurs);

	//On affecte � chaque position de la matrice les valeurs de la s�quence, et se d�calant de la valeur du num�ro de la ligne (0 pour la premi�re, n-1 pour la derni�re)
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
*****						   de Heap it�ratif																*****
*****************************************************************************************************************
***** Entr�e : CMatrice<MType> MATSequence																	*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<MType>																				*****
***** Entraine : la fonction renvoie une matrice de toutes les permutations possibles de la liste			*****
**************** Exception MATRICE_NON_LIGNE : La matrice n'est pas une matrice ligne						*****
*****************************************************************************************************************/

template<class MType>
inline CMatrice<MType>& COperationMatrice<MType>::OMAPermutationComplete(CMatrice<MType>& MATSequence)
{
	//V�rification de si l'on fourni bien une s�quence de nombre et non une matrice � avec plusieurs lignes
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

	//Variables utiles � l'alorithme de heap
	unsigned int uiNiveauIncrementation = 0;
	unsigned int uiCompteurLigne = 1;
	MType MTPRecopie;
	MType MTPSauvegarde;
	int* piCompteur = new int[uiNombreValeurs];

	//Calcul du nombre de lignes de la matrice qui est �gal � la factorielle du nombres de valeurs
	for (uiBoucleFactorielle = 1; uiBoucleFactorielle <= uiNombreValeurs; uiBoucleFactorielle++)
	{
		uiNombrePermutations = uiNombrePermutations * uiBoucleFactorielle;
	}

	//Matrice retourn�e � la fin de la fonction
	CMatrice<MType>* pMATMatrice = new CMatrice<MType>((MType)0, uiNombrePermutations, uiNombreValeurs);

	//Recopie de la premi�re ligne
	for (uiBoucleCopie = 0; uiBoucleCopie < uiNombreValeurs; uiBoucleCopie++)
	{
		MTPRecopie = MATSequence.MATLireElement(0, uiBoucleCopie);
		pMATMatrice->MATModifierElement(MTPRecopie, 0, uiBoucleCopie);
	}

	//Initialisation du compteur � 0
	for (uiBoucleCompteur = 0; uiBoucleCompteur < uiNombreValeurs; uiBoucleCompteur++)
	{
		piCompteur[uiBoucleCompteur] = 0;
	}


	while (uiNiveauIncrementation < uiNombreValeurs)
	{
		if (piCompteur[uiNiveauIncrementation] < uiNiveauIncrementation)
		{
			//Recopie de la ligne pr�c�dente
			for (uiBoucleCopie = 0; uiBoucleCopie < uiNombreValeurs; uiBoucleCopie++)
			{
				pMATMatrice->MATModifierElement(pMATMatrice->MATLireElement(uiCompteurLigne - 1, uiBoucleCopie), uiCompteurLigne, uiBoucleCopie);
			}

			//Permutation diff�rentes selon la parit� du niveau d'incr�mentation
			if (uiNiveauIncrementation % 2 == 0)
			{
				//On sauvegarde un des deux �l�ments que l'on veut permutter, puisqu'il sera remplac� par l'autre
				MTPSauvegarde = pMATMatrice->MATLireElement(uiCompteurLigne, 0);

				//On remplace le second �l�ment par le premier
				pMATMatrice->MATModifierElement(pMATMatrice->MATLireElement(uiCompteurLigne, uiNiveauIncrementation), uiCompteurLigne, 0);

				//Puis le premier par le second, sauvegard� pr�c�demment
				pMATMatrice->MATModifierElement(MTPSauvegarde, uiCompteurLigne, uiNiveauIncrementation);
			}
			else
			{
				//On sauvegarde un des deux �l�ments que l'on veut permutter, puisqu'il sera remplac� par l'autre
				MTPSauvegarde = pMATMatrice->MATLireElement(uiCompteurLigne, piCompteur[uiNiveauIncrementation]);

				//On remplace le second �l�ment par le premier
				pMATMatrice->MATModifierElement(pMATMatrice->MATLireElement(uiCompteurLigne, uiNiveauIncrementation), uiCompteurLigne, piCompteur[uiNiveauIncrementation]);
				//Puis le premier par le second, sauvegard� pr�c�demment
				pMATMatrice->MATModifierElement(MTPSauvegarde, uiCompteurLigne, uiNiveauIncrementation);
			}

			//Incr�mentation des deux compteurs
			piCompteur[uiNiveauIncrementation]++;
			uiCompteurLigne++;

			//R�initialisation du niveau d'incr�mentation
			uiNiveauIncrementation = 0;

		}
		else
		{
			//R�initialisation du compteur
			piCompteur[uiNiveauIncrementation] = 0;

			//Incr�mentation du niveau d'incr�mentation
			uiNiveauIncrementation++;
		}
	}

	return *pMATMatrice;
}


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

template<class MType>
inline CMatrice<MType>& COperationMatrice<MType>::OMAPermutationPersonnalisee(CMatrice<MType>& MATOriginale, CMatrice<unsigned int>& MATDecalages)
{
	//Puisqu'on l'utilisera plusieurs fois on initialise des variables avec le nombre de lignes et colonnes de la matrice
	unsigned int uiNombreLignes = MATOriginale.MATLireNbLignes();
	unsigned int uiNombreColonnes = MATOriginale.MATLireNbColonnes();

	//Variables de boucle utile au parcours de la matrice
	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;

	//V�rification de si l'on fourni bien une s�quence de nombre et non une matrice � avec plusieurs lignes
	if (MATDecalages.MATLireNbLignes() > 1)
	{
		CException EXCException(MATRICE_NON_LIGNE);
		throw EXCException;
	}

	//V�rification de si la s�quence de d�calages comporte bien le bon nombre de d�calages
	if (uiNombreLignes != MATDecalages.MATLireNbColonnes())
	{
		CException EXCException(MAUVAISE_MATRICE_DECALAGE);
		throw EXCException;
	}

	//Initialisation de la matrice retourn�e par la fonction
	CMatrice<MType>* pMATMatrice = new CMatrice<MType>(0, uiNombreLignes, uiNombreColonnes);

	for (uiBoucleLigne = 0; uiBoucleLigne < uiNombreLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiNombreColonnes; uiBoucleColonne++)
		{
			//On suit le m�me principe que pour les permutation simple, mais en d�calant du nombre de d�calage sp�cif� au n-i�me nombre de la s�quence
			pMATMatrice->MATModifierElement(MATOriginale.MATLireElement(uiBoucleLigne, uiBoucleColonne), uiBoucleLigne, (MATDecalages.MATLireElement(0, uiBoucleLigne) + uiBoucleColonne) % uiNombreColonnes);
		}
	}

	return *pMATMatrice;
}
