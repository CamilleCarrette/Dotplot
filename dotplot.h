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






#endif