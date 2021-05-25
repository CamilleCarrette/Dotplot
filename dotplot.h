#ifndef __DOTPLOT_H__
#define __DOTPLOT_H__

#include <iostream>
#include <string>

using namespace std;

struct binMat //Structure de matrice pour stocker les correspondences entre les séquences.
{
    //Attributs
    int n;
    int m;
    bool **Mat; // si M[i][j]=1 alors le i-ème caractère est égal au j-ème caractère.

    //Constructeur
    binMat(int n, int m); 

    //Méthodes
    void afficheMatrice();
    void destructor();
};

binMat* dotplot1(string s1, string s2); //Effectue le dotplot entre s1 et s2.

binMat* diagonal(binMat* Mdot); //Ne conserve que les cellules qui font partie d'une diagonale d'au moins n cellules.

binMat* diagonal2(binMat* Mdot); //Ne conserve que les cellules qui font partie d'une diagonale inversée d'au moins n cellules.

void datgeneration(binMat* Mdot); //Produit le fichier .dat nécessaire au fichier gnuplot.

void majPng(binMat* Mdot,string s1,string s2); //Génère le fichier gnuplot en fonction des paramètres du dotplot et crée le fichier .png qui l'affiche.

void randSequence(string* s1, string* s2); //Génération d'une séquence aléatoire à partir d'un dictionnaire de caractères.

void choixSequence(string* s1, string* s2); //Interface de l'application.

#endif