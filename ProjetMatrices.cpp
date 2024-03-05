#include <iostream>
#include <fstream>
#include <Windows.h>
#include "CException.h"
#include "CMatrice.cpp"
#include "CIterateurFichier.h"
#include "COperationMatrice.h"

int main(int argc, const char* argv[])
{
	SetConsoleOutputCP(CP_UTF8);
	
	if (argc < 3) 
	{
		cout << "Veuillez rentrer le numéro de la méthode de permutation que vous voulez, puis le chemin de votre fichier.";
		exit(1);
	}

	//Variable de boucle
	unsigned int uiBoucle;

	if (argv[1][0] == '1')
	{
		cout << "Question 1 :\n\n";

		//Calcul de la matrice de permutation 1

		try
		{
			CIterateurFichier* pITEIterateur = new CIterateurFichier(argv[2]);
			CMatrice<double>* pMATMatrice = &pITEIterateur->ITEGenererMatrice();
			delete pITEIterateur;

			CMatrice<double>* pMATPermutee1 = new CMatrice<double>();
			COperationMatrice<double> OMAOperation;

			*pMATPermutee1 = OMAOperation.OMAPermutationSimple(*pMATMatrice);

			cout << "Matrice originale :" << endl;
			pMATMatrice->MATAfficherMatrice();
			cout << endl;

			cout << "Matrice permutée :" << endl;
			pMATPermutee1->MATAfficherMatrice();

			delete pMATMatrice;
			delete pMATPermutee1;
		}
		catch (CException EXCErreur)
		{
			EXCErreur.EXCAfficherErreur();
			exit(1);
		}
	}
	else if (argv[1][0] == '2')
	{
		cout << "Question 2 :\n\n";

		//Calcul de la matrice de permutation 2

		try
		{
			CIterateurFichier* pITEIterateur = new CIterateurFichier(argv[2]);
			CMatrice<double>* pMATMatrice = &pITEIterateur->ITEGenererMatrice();
			delete pITEIterateur;

			CMatrice<double>* pMATPermutee2 = new CMatrice<double>();
			COperationMatrice<double> OMAOperation;

			*pMATPermutee2 = OMAOperation.OMAPermutationComplete(*pMATMatrice);

			cout << "Matrice originale :" << endl;
			pMATMatrice->MATAfficherMatrice();
			cout << endl;

			cout << "Matrice permutée :" << endl;
			pMATPermutee2->MATAfficherMatrice();

			delete pMATMatrice;
			delete pMATPermutee2;
		}
		catch (CException EXCErreur)
		{
			EXCErreur.EXCAfficherErreur();
			exit(1);
		}
	}
	else if (argv[1][0] == '3')
	{
		cout << "Question 3 :\n\n";

		//Calcul de la matrice de permutation 3
		
		try
		{
			CIterateurFichier* pITEIterateur = new CIterateurFichier(argv[2]);
			CMatrice<double>* pMATMatrice = &pITEIterateur->ITEGenererMatrice();
			delete pITEIterateur;
			
			unsigned int uiNombreColonnes = argc - 3;
			CMatrice<unsigned int>* pMATDecalages = new CMatrice<unsigned int>(0, 1, uiNombreColonnes);
			
			unsigned int uiBoucleArguments = 0;
			for (uiBoucleArguments = 0; uiBoucleArguments < uiNombreColonnes; uiBoucleArguments++)
			{
				pMATDecalages->MATModifierElement(atoi(argv[uiBoucleArguments + 3]), 0, uiBoucleArguments);
			}
			
			COperationMatrice<double> OMAOperation;

			CMatrice<double>* pMATPermutee3 = &OMAOperation.OMAPermutationPersonnalisee(*pMATMatrice, *pMATDecalages);

			cout << "Matrice originale :" << endl;
			pMATMatrice->MATAfficherMatrice();
			cout << endl;

			cout << "Matrice de décalages :" << endl;
			pMATDecalages->MATAfficherMatrice();
			cout << endl;

			cout << "Matrice permutée :" << endl;
			pMATPermutee3->MATAfficherMatrice();

			delete pMATMatrice;
			delete pMATDecalages;
			delete pMATPermutee3;
		}
		catch (CException EXCErreur)
		{
			EXCErreur.EXCAfficherErreur();
			exit(1);
		}
	}
	else
	{
		cout << "Numéro de question invalide, entrez un numéro entre 1 et 3.";
	}
}