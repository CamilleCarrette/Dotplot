#include "dotplot.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>

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
    if (this->n > 20 || this->m > 20)
    {
        cout<<"Matrice trop grande"<<endl<<endl;
        return;
    }
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
    cout<<endl;
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

binMat* diagonal2(binMat* Mdot)
{
    int n,count;
    binMat* Mdiag = new binMat(Mdot->n,Mdot->m);
    cout<<"Les diagonales de longueur au moins 'n' seront prises en compte"<<endl;
    cout<<"Entrez n : ";
    cin>>n;
    cout<<endl;
    for (int i = 0; i < (Mdot->n - (n-1)); i++)
    {
        for (int j = (n-1); j < Mdot->m; j++)
        {
            if (Mdot->Mat[i][j] && !(Mdiag->Mat[i][j]))
            {
                count = 0;
                while((i+count)<Mdot->n && (j-count)>=0 && Mdot->Mat[i+count][j-count]) 
                {
                    count++;
                }
                if (count>=n)
                {
                    count--;
                    while(count>=0)
                    {
                        Mdiag->Mat[i+count][j-count] = true;
                        count--;
                    }                    
                }                
            }            
        }        
    }    
    return Mdiag;
}

void datgeneration(binMat* Mdot){
    int n,count;
    binMat* Mdiag = new binMat(Mdot->n,Mdot->m);
    std::ofstream fichier { "dotplot.dat" };
    for (int i = 0; i < Mdot->n; i++)
    {
        for (int j = 0; j < Mdot->m; j++)
        {
            if(Mdot->Mat[i][j]){
                fichier << i << " " << j << endl;
            }
        }
    }
}

void majPng(binMat* Mdot){
    cout<<"Generation du fichier dat : "<<endl;
    datgeneration(Mdot);
    cout<<"Execution du dotplot.gp"<<endl;
    system("gnuplot dotplot.gp");
}

void randSequence(string* s1, string* s2)
{
    int l1,l2;
    string rand1,rand2;
    string pool = {'a','c','g','t'};
    srand(time(NULL));
    cout<<"Longueur de la sequence 1 : ";
    cin>>l1;
    cout<<"Longueur de la sequence 2 : ";
    cin>>l2;
    rand1.resize(l1);
    rand2.resize(l2);
    for (int i = 0; i < l1; i++)
    {
        rand1[i] = pool[rand()%4];
    }
    for (int i = 0; i < l2; i++)
    {
        rand2[i] = pool[rand()%4];
    }
    *s1=rand1;
    *s2=rand2;
    cout<<"s1 : "<<*s1<<endl<<"s2 : "<<*s2<<endl;       
}

void choixSequence(string* s1, string* s2)
{
    int c;
    cout<<endl<<"Quel type de sequence :"<<endl<<endl
        <<"1- sequence rentree a la main"<<endl
        <<"2- sequence aleatoire parmi {a,c,g,t}"<<endl
        <<"Autre pour sortir du programme"<<endl;
    cin>>c;
    cout<<endl;
    switch (c)
    {
    case 1:
        cout<<"Etrez la sequence 1 : ";
        cin>>*s1;
        cout<<"Etrez la sequence 2 : ";
        cin>>*s2;
        break;
    
    case 2:
        randSequence(s1,s2);
        break;

    default:
        break;
    }
    cout<<endl;
}


int main()
{
    string s1,s2;
    choixSequence(&s1,&s2);
    binMat* M = dotplot1(s1,s2);
    cout<<"Matrice du dotplot : "<<endl;
    M->afficheMatrice();
    majPng(M);
    unsigned int cases;
    binMat* M2;
    while (1)
    {
        cout<<endl<<"Que faire :"<<endl<<endl
            <<"1- Exposer les diagonales"<<endl
            <<"2- Exposer les diagonales inverses"<<endl
            <<"3- Changer les sequences"<<endl
            <<"Autre pour sortir du programme"<<endl;
        cin>>cases;
        cout<<endl;
        switch (cases)
        {
        case 1:
            M2 = diagonal(M);
            cout<<"Matrice des diagonales : "<<endl;
            M2->afficheMatrice();
            majPng(M2);
            M2->destructor();
            break;
        
        case 2:
            M2 = diagonal2(M);
            cout<<"Matrice des diagonales inverses : "<<endl;
            M2->afficheMatrice();
            majPng(M2);
            M2->destructor();
            break;

        case 3:
            choixSequence(&s1,&s2);
            M->destructor();
            M = dotplot1(s1,s2);
            cout<<"Matrice du dotplot : "<<endl;
            M->afficheMatrice();
            majPng(M);
            break;
        
        default:
            M->destructor();
            return 0;
        }
    }
}