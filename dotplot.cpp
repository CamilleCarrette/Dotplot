#include "dotplot.h"
#include <iostream>
#include <string>

using namespace std;

binMat::binMat(int n, int m)
{
    this->n = n;
    this->m = m;
    this->Mat = new bool*[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->Mat[i] = new bool[this->m];
        for (int j = 0; j < this->m; j++)
        {
            this->Mat[i][j]=false;
        }
        
    }
}



void binMat::afficheMatrice()
{
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            cout<<Mat[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void binMat::destructor()
{
    for (int i = 0; i < this->n; i++)
    {       
        delete[] this->Mat[i];
    }
    delete[] this->Mat;
}

binMat* dotplot1(string s1, string s2)
{
    binMat* M = new binMat(s1.length(),s2.length());
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            M->Mat[i][j] = (s1[i]==s2[j]);
        }
        
    }
    return M;
}

binMat* diagonal(binMat* Mdot)
{
    int n,count;
    binMat* Mdiag = new binMat(Mdot->n,Mdot->m);
    cout<<"Les diagonales de longueur au moins 'n' seront prises en compte"<<endl;
    cout<<"Entrez n : ";
    cin>>n;
    for (int i = 0; i < (Mdot->n - (n-1)); i++)
    {
        for (int j = 0; j < (Mdot->m - (n-1)); j++)
        {
            if (Mdot->Mat[i][j] && !(Mdiag->Mat[i][j]))
            {
                count = 0;
                while((i+count)<Mdot->n && (j+count)<Mdot->m && Mdot->Mat[i+count][j+count]) 
                {
                    count++;
                }
                if (count>=n)
                {
                    count--;
                    while(count>=0)
                    {
                        Mdiag->Mat[i+count][j+count] = true;
                        count--;
                    }                    
                }                
            }            
        }        
    }    
    return Mdiag;
}


int main()
{
    string s1,s2;
    cout<<"Etrez la sequence 1 : ";
    cin>>s1;
    cout<<"Etrez la sequence 2 : ";
    cin>>s2;
    binMat* M = dotplot1(s1,s2);
    cout<<"Matrice du dotplot : "<<endl;
    M->afficheMatrice();
    binMat* M2 = diagonal(M);
    cout<<"Matrice des diagonales : "<<endl;
    M2->afficheMatrice();
    M->destructor();
    M2->destructor();
    
    return 0;
}