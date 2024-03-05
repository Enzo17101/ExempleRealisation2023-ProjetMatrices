#include "CIterateurFichier.h"


/****************************************************************************************************************
***** CIterateurFichier : constructeur par défaut de la classe CIterateurFichier							*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise un itérateur de fichier												*****
*****************************************************************************************************************/

CIterateurFichier::CIterateurFichier()
{
	pcChemin = nullptr;
}

/****************************************************************************************************************
***** CIterateurFichier : constructeur de recopie de la classe CIterateurFichier							*****
*****************************************************************************************************************
***** Entrée :	CIterateurFichier ITEParam			                                                        *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise un itérateur de fichier	à partir d'un autre itérateur de fichier	*****
*****************************************************************************************************************/

CIterateurFichier::CIterateurFichier(CIterateurFichier& ITEParam)
{
	//longueur du chemin en paramètre en comptant le caractère de fin de chaine
	unsigned int uiLongueurChemin = strlen(ITEParam.pcChemin) + 1;
	
	//on crée le chemin
	pcChemin = new char[uiLongueurChemin];

	//copie de la chaine ITEParam.pcChemin dans pcChemin
	strcpy_s(pcChemin, uiLongueurChemin, ITEParam.pcChemin);
}


/****************************************************************************************************************
***** CIterateurFichier : constructeur de confort de la classe CIterateurFichier							*****
*****************************************************************************************************************
***** Entrée :	char * pcCheminFichier			                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un itérateur de fichier	à partir d'un chemin en paramètre		    *****
*****************************************************************************************************************/

CIterateurFichier::CIterateurFichier(const char * pcCheminFichier)
{
	//longueur du chemin en paramètre en comptant le caractère de fin de chaine
	unsigned int uiLongueurChemin = strlen(pcCheminFichier) + 1;

	//on crée le chemin
	pcChemin = new char[uiLongueurChemin];

	//copie de la chaine pcCheminFichier dans pcChemin
	strcpy_s(pcChemin, uiLongueurChemin, pcCheminFichier);
}


/****************************************************************************************************************
***** ~CIterateurFichier : destructeur de la classe CIterateurFichier										*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction désalloue l'espace mémoire attribué à un itérateur de fichier					*****
*****************************************************************************************************************/

CIterateurFichier::~CIterateurFichier()
{
	delete pcChemin;
}


/****************************************************************************************************************
***** ITEGenererMatrice : Fonction permettant de créer une matrice de doubles à partir d'un fichier texte	*****
*****************************************************************************************************************
***** Entrée : Rien																							*****
***** Nécessite : Rien																						*****
***** Sortie : CMatrice<double>																				*****
***** Entraine : la fonction renvoie la matrice initialisée à partir du fichier correspondant au chemin de	*****
*****			 CIterateurFichier																		  OU*****
**************** Exception CHEMIN_INVALIDE : Le fichier correspondant au chemin spécifié n'a pas pus être	*****
****************							 ouvert															*****
**************** Exception BALISE_INVALIDE : Une des balises écrites dans le fichier texte est incorrecte,	*****
****************							 on rencontrera aussi cette exception si ce n'est pas le type	*****
****************							 double qui est spécifié										*****
*****************************************************************************************************************/

CMatrice<double> & CIterateurFichier::ITEGenererMatrice()
{
	ifstream IFSFichier(pcChemin);

	//Teste si le fichier est bien ouvert
	if (!IFSFichier)
	{
		CException EXCException(CHEMIN_INVALIDE);
		throw EXCException;
	}

	//Chaine utilisée pour parcourir le fichier
	char pcLigne[255];

	//Chaînes permettant de vérifier la bonne syntaxe des balises
	char pcTypeDouble[19] = "TypeMatrice=double";
	char pcNBLignes[10] = "NBLignes=";
	char pcNBColonnes[12] = "NBColonnes=";
	char pcBaliseMatriceDebut[10] = "Matrice=[";
	char pcBaliseMatriceFin[2] = "]";

	//Sous chaines permettant de vérifier la bonne syntaxe des balises lignes et colonnes
	char pcSousChaineLignes[10];
	char pcSousChaineColonnes[12];

	//Variable de boucle utilisée pour chaque parcours d'une ligne caractère par caractère
	unsigned int uiBoucle;

	//Variable utilisée pour la lecture des entiers dans une chaine
	int uiDigit;

	//Variable utilisée pour stocker le nombre de lignes et de colonnes de la matrice
	unsigned int uiNBLignes;
	unsigned int uiNBColonnes;

	//Variables de boucles pour parcourir la matrice
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	//Variables utiles à la lecture et vérification du double dans le fichier
	double dNombre;
	bool bLectureDecimales;

	//Vérification de la première ligne (et donc du type double)
	IFSFichier >> pcLigne;

	if (strcmp(pcTypeDouble, pcLigne) != 0)
	{
		CException EXCException(BALISE_INVALIDE);
		throw EXCException;
	}


	//Vérification de la deuxième ligne
	IFSFichier >> pcLigne;

	strncpy_s(pcSousChaineLignes, 10, pcLigne, 9);

	if (strcmp(pcSousChaineLignes, pcNBLignes) != 0)
	{

		CException EXCException(BALISE_INVALIDE);
		throw EXCException;
	}


	//Lecture du nombre de lignes
	uiBoucle = 9;
	uiNBLignes = 0;

	while (pcLigne[uiBoucle] != '\0')
	{
		uiDigit = (int)pcLigne[uiBoucle] - 48;
		if (uiDigit < 0 || uiDigit > 9)
		{
			CException EXCException(BALISE_INVALIDE);
			throw EXCException;
		}
		else
		{
			uiNBLignes *= 10;
			uiNBLignes += uiDigit;
		}
		uiBoucle++;
	}

	//Vérification de la troisième ligne
	IFSFichier >> pcLigne;

	strncpy_s(pcSousChaineColonnes, 12, pcLigne, 11);

	if (strcmp(pcSousChaineColonnes, pcNBColonnes) != 0)
	{
		CException EXCException(BALISE_INVALIDE);
		throw EXCException;
	}


	//Lecture du nombre de colonnes
	uiBoucle = 11;
	uiNBColonnes = 0;

	while (pcLigne[uiBoucle] != '\0')
	{
		uiDigit = (int)pcLigne[uiBoucle] - 48;

		if (uiDigit < 0 || uiDigit > 9)
		{
			CException EXCException(BALISE_INVALIDE);
			throw EXCException;
		}
		else
		{
			uiNBColonnes *= 10;
			uiNBColonnes += uiDigit;
		}
		uiBoucle++;
	}

	//Matrice retournée par la fonction
	CMatrice<double>* pMATMatrice = new CMatrice<double>(0, uiNBLignes, uiNBColonnes);

	//vérification de la quatrième ligne
	IFSFichier >> pcLigne;

	if (strcmp(pcBaliseMatriceDebut, pcLigne) != 0)
	{
		CException EXCException(BALISE_INVALIDE);
		throw EXCException;
	}

	//Parcours de la matrice stockée dans le fichier
	for (uiBoucleLigne = 0; uiBoucleLigne < uiNBLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiNBColonnes; uiBoucleColonne++)
		{
			//lecture d'une ligne contenant un double (l'espace étant un séparateur de lignes)
			IFSFichier >> pcLigne;

			uiBoucle = 0;
			bLectureDecimales = false;

			//Vérification de la bonne syntaxe du nombre
			for (uiBoucle; pcLigne[uiBoucle] != '\0'; uiBoucle++)
			{
				uiDigit = (int)pcLigne[uiBoucle] - 48;//Pour simplifier la compréhension du code ensuite on ramène le code ascii du caractère
				//à la valeur entière représentée par le caractère
				if (((uiDigit == -2 && bLectureDecimales == true) || //vérifier qu'il n'y ai pas de deuxième point
					(uiDigit != -2 && !(uiDigit == -3 && uiBoucle == 0) && (uiDigit < 0 || uiDigit > 9)))) //vérifier que l'on lit bien un nombre ou le signe - (uniquement en début de nombre) ou un point
				{
					CException EXCException(BALISE_INVALIDE);
					throw EXCException;
				}
				if (uiDigit == -2)
				{
					bLectureDecimales = true;
				}
			}

			//Conversion de la chaine en double
			dNombre = atof(pcLigne);

			pMATMatrice->MATModifierElement(dNombre, uiBoucleLigne, uiBoucleColonne);
		}
	}


	//Vérification de la dernière ligne
	IFSFichier >> pcLigne;

	if (strcmp(pcBaliseMatriceFin, pcLigne) != 0)
	{
		CException EXCException(BALISE_INVALIDE);
		throw EXCException;
	}

	return *pMATMatrice;
}
