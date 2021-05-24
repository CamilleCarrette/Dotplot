#ifndef __DOTPLOT_H__
#define __DOTPLOT_H__

#include <iostream>
#include <string>

using namespace std;

struct binMat
{
    int n;
    int m;
    bool **Mat;

    binMat(int n, int m);

    void afficheMatrice();
    void destructor();
};

binMat* dotplot1(string s1, string s2);

binMat* diagonal(binMat* Mdot);

binMat* diagonal2(binMat* Mdot);

void datgeneration(binMat* Mdot);

void majPng(binMat* Mdot,string s1,string s2);

void randSequence(string* s1, string* s2);

void choixSequence(string* s1, string* s2);

#endif