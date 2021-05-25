#ifndef __DOTPLOT_H__
#define __DOTPLOT_H__

#include <iostream>
#include <string>

using namespace std;

struct binMat //Structure de matrice pour stocké les correspondence entre les séuqences.
{
    //Attributs
    int n;
    int m;
    bool **Mat; // si M[i][j]=1 alors le ieme caractère est égale au jeme caractère.

    //Constructeur
    binMat(int n, int m); 

    //Methodes
    void afficheMatrice();
    void destructor();
};

binMat* dotplot1(string s1, string s2); //effectue le dotplot entre s1 et s2

binMat* diagonal(binMat* Mdot); //Ne conserve que les cellule lorsqu'elles font parties d'une diagonal d'au moins n cellules.

binMat* diagonal2(binMat* Mdot); //Ne conserve que les cellule lorsqu'elles font parties d'une diagonal inversée d'au moins n cellules.

void datgeneration(binMat* Mdot); //Produit le fichier dat nécessaire au fichier gnuplot

void majPng(binMat* Mdot,string s1,string s2); //Génére le fichier gnuplot en fonction des paramètre du dotplot et crée le fichier .png qui l'affiche

void randSequence(string* s1, string* s2); //Génération d'une séquence ADN random

void choixSequence(string* s1, string* s2); //Interface de l'application

#endif