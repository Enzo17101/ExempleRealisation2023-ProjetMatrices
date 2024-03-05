#include "CIterateurFichier.h"


/****************************************************************************************************************
***** CIterateurFichier : constructeur par d�faut de la classe CIterateurFichier							*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise un it�rateur de fichier												*****
*****************************************************************************************************************/

CIterateurFichier::CIterateurFichier()
{
	pcChemin = nullptr;
}

/****************************************************************************************************************
***** CIterateurFichier : constructeur de recopie de la classe CIterateurFichier							*****
*****************************************************************************************************************
***** Entr�e :	CIterateurFichier ITEParam			                                                        *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise un it�rateur de fichier	� partir d'un autre it�rateur de fichier	*****
*****************************************************************************************************************/

CIterateurFichier::CIterateurFichier(CIterateurFichier& ITEParam)
{
	//longueur du chemin en param�tre en comptant le caract�re de fin de chaine
	unsigned int uiLongueurChemin = strlen(ITEParam.pcChemin) + 1;
	
	//on cr�e le chemin
	pcChemin = new char[uiLongueurChemin];

	//copie de la chaine ITEParam.pcChemin dans pcChemin
	strcpy_s(pcChemin, uiLongueurChemin, ITEParam.pcChemin);
}


/****************************************************************************************************************
***** CIterateurFichier : constructeur de confort de la classe CIterateurFichier							*****
*****************************************************************************************************************
***** Entr�e :	char * pcCheminFichier			                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un it�rateur de fichier	� partir d'un chemin en param�tre		    *****
*****************************************************************************************************************/

CIterateurFichier::CIterateurFichier(const char * pcCheminFichier)
{
	//longueur du chemin en param�tre en comptant le caract�re de fin de chaine
	unsigned int uiLongueurChemin = strlen(pcCheminFichier) + 1;

	//on cr�e le chemin
	pcChemin = new char[uiLongueurChemin];

	//copie de la chaine pcCheminFichier dans pcChemin
	strcpy_s(pcChemin, uiLongueurChemin, pcCheminFichier);
}


/****************************************************************************************************************
***** ~CIterateurFichier : destructeur de la classe CIterateurFichier										*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction d�salloue l'espace m�moire attribu� � un it�rateur de fichier					*****
*****************************************************************************************************************/

CIterateurFichier::~CIterateurFichier()
{
	delete pcChemin;
}


/****************************************************************************************************************
***** ITEGenererMatrice : Fonction permettant de cr�er une matrice de doubles � partir d'un fichier texte	*****
*****************************************************************************************************************
***** Entr�e : Rien																							*****
***** N�cessite : Rien																						*****
***** Sortie : CMatrice<double>																				*****
***** Entraine : la fonction renvoie la matrice initialis�e � partir du fichier correspondant au chemin de	*****
*****			 CIterateurFichier																		  OU*****
**************** Exception CHEMIN_INVALIDE : Le fichier correspondant au chemin sp�cifi� n'a pas pus �tre	*****
****************							 ouvert															*****
**************** Exception BALISE_INVALIDE : Une des balises �crites dans le fichier texte est incorrecte,	*****
****************							 on rencontrera aussi cette exception si ce n'est pas le type	*****
****************							 double qui est sp�cifi�										*****
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

	//Chaine utilis�e pour parcourir le fichier
	char pcLigne[255];

	//Cha�nes permettant de v�rifier la bonne syntaxe des balises
	char pcTypeDouble[19] = "TypeMatrice=double";
	char pcNBLignes[10] = "NBLignes=";
	char pcNBColonnes[12] = "NBColonnes=";
	char pcBaliseMatriceDebut[10] = "Matrice=[";
	char pcBaliseMatriceFin[2] = "]";

	//Sous chaines permettant de v�rifier la bonne syntaxe des balises lignes et colonnes
	char pcSousChaineLignes[10];
	char pcSousChaineColonnes[12];

	//Variable de boucle utilis�e pour chaque parcours d'une ligne caract�re par caract�re
	unsigned int uiBoucle;

	//Variable utilis�e pour la lecture des entiers dans une chaine
	int uiDigit;

	//Variable utilis�e pour stocker le nombre de lignes et de colonnes de la matrice
	unsigned int uiNBLignes;
	unsigned int uiNBColonnes;

	//Variables de boucles pour parcourir la matrice
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	//Variables utiles � la lecture et v�rification du double dans le fichier
	double dNombre;
	bool bLectureDecimales;

	//V�rification de la premi�re ligne (et donc du type double)
	IFSFichier >> pcLigne;

	if (strcmp(pcTypeDouble, pcLigne) != 0)
	{
		CException EXCException(BALISE_INVALIDE);
		throw EXCException;
	}


	//V�rification de la deuxi�me ligne
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

	//V�rification de la troisi�me ligne
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

	//Matrice retourn�e par la fonction
	CMatrice<double>* pMATMatrice = new CMatrice<double>(0, uiNBLignes, uiNBColonnes);

	//v�rification de la quatri�me ligne
	IFSFichier >> pcLigne;

	if (strcmp(pcBaliseMatriceDebut, pcLigne) != 0)
	{
		CException EXCException(BALISE_INVALIDE);
		throw EXCException;
	}

	//Parcours de la matrice stock�e dans le fichier
	for (uiBoucleLigne = 0; uiBoucleLigne < uiNBLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiNBColonnes; uiBoucleColonne++)
		{
			//lecture d'une ligne contenant un double (l'espace �tant un s�parateur de lignes)
			IFSFichier >> pcLigne;

			uiBoucle = 0;
			bLectureDecimales = false;

			//V�rification de la bonne syntaxe du nombre
			for (uiBoucle; pcLigne[uiBoucle] != '\0'; uiBoucle++)
			{
				uiDigit = (int)pcLigne[uiBoucle] - 48;//Pour simplifier la compr�hension du code ensuite on ram�ne le code ascii du caract�re
				//� la valeur enti�re repr�sent�e par le caract�re
				if (((uiDigit == -2 && bLectureDecimales == true) || //v�rifier qu'il n'y ai pas de deuxi�me point
					(uiDigit != -2 && !(uiDigit == -3 && uiBoucle == 0) && (uiDigit < 0 || uiDigit > 9)))) //v�rifier que l'on lit bien un nombre ou le signe - (uniquement en d�but de nombre) ou un point
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


	//V�rification de la derni�re ligne
	IFSFichier >> pcLigne;

	if (strcmp(pcBaliseMatriceFin, pcLigne) != 0)
	{
		CException EXCException(BALISE_INVALIDE);
		throw EXCException;
	}

	return *pMATMatrice;
}
