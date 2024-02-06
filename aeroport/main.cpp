#include <iostream>
#include <fstream>


using namespace std;
ifstream f("aeroport.in");
struct datan
{
    int zi,luna,an,ora,minut;
};
struct zbor
{
    char model_aeronava[21];
    int id, durata, nr_locuri;
    datan plecare, sosire;
};
struct ruta
{
    int nr_zboruri;
    zbor z[10];
    char destinatie[21], sursa[21];
}r[10];


int main()
{
    int i,j,n;
    f>>n;//nr zboruri
    for(i=0;i<n;i++)
        f>>r[i].sursa[i]>>r[i].destinatie>>r[i].nr_zboruri;
    for(i=0;i<n;i++)
    {
        for(j=0;j<r[i].nr_zboruri;j++)
        {
            f>>r[i].z[j].id>>r[i].z[j].durata>>r[i].z[j].plecare.zi>>r[i].z[j].plecare.luna>>r[i].z[j].plecare.an;
            f>>r[i].z[j].plecare.ora>>r[i].z[j].plecare.minut;
            f>>r[i].z[j].sosire.zi>>r[i].z[j].sosire.luna>>r[i].z[j].sosire.an>>r[i].z[j].sosire.ora>>r[i].z[j].sosire.minut;
            f.get[i].z[j].model_aeronava>>f;
        }
    }

    //cout<<"Datele de intrare au fost citite."<<endl;
    int ok = 1, op;
    cout<<"Introduceti o valoare (1-5) pentru a efectua una dintre operatiunile de mai jos:"<<endl;
    cout<<"1. Adaugarea unei ruta."<<endl;
    cout<<"2. Adaugare zbor pe o anumita ruta."<<endl;
    cout<<"3. Afisarea tuturor zborurilor de pe o anumita ruta, crescator in functie de numarul de locuri."<<endl;
    cout<<"4. Verificarea existentei unui zbor pe o anumita ruta."<<endl;
    cout<<"5. Verificarea existentei unei anumite aeronave pe o anumita ruta."<<endl;
    cout<<"6. Stop."<<endl;
    while (ok == 1)
    {
        cin>>op;
        switch(op)
        {
        case 1:
            {
                cout<<"Adaugarea unei rute."<<endl;
                cout<<"Introduceti orasul de plecare si destinatia:"<<endl;
                n++;
                cin>>r[n-1].sursa>>r[n-1].destinatie;
                r[n-1].nr_zboruri = 0;
                cout<<"Ruta adaugata cu succes!"<<endl;
                cout<<"Inapoi"<<endl;
                break;
            }
        case 2:
            {
                cout<<"Adaugarea unui zbor pe o anumita ruta."<<endl;
                cout<<"Introduceti numarul de ordine al rutei pe care vreti sa adaugati un zbor:"<<endl;
                int nr;
                cin>>nr;
                if (nr < n)
                {
                    r[nr].nr_zboruri++;
                    cout<<"Introduceti informatiile despre zbor:"<<endl;

                    cout<<r[nr].nr_zboruri<<endl;
                }
                else
                    cout<<"Imposibil. Ruta nu exista."<<endl;
                break;
            }
        case 3:
            {
                int nr;
                cout<<"Afisarea tuturor zborurilor de pe o anumita ruta, crescator in functie de numarul de locuri:"<<endl;
                cout<<"Introduceti numarul de ordine a rutei:"<<endl;
                cin>>nr;
                if(nr<n)
                {
                    for(i=0;i<r[nr].nr_zboruri-1;i++)
                        for(j=i+1;j<r[nr].nr_zboruri;j++)
                            if(r[nr].z[j].nr_locuri>r[nr].z[i].nr_locuri)
                            {
                                 swap(r[nr].z[j],r[nr].z[i]);
                            }
                   // cout<<"okay";
                    for(i=0;i<r[nr].nr_zboruri;i++)
                    {

                        cout<<r[nr].z[i].id<<endl;
                    }
                }
                else
                    cout<<"Imposibil.Ruta nu exista"<<endl;

                break;
            }

        case 4:
        {
            cout<<"Verificarea existentei unui zbor pe o anumita ruta:"<<endl;
            cout<<"Introduceti numarul de ordine a rutei:"<<endl;
            int nr,ok1=0;
            cin>>nr;
            if(nr<n)
            {
                cout<<"Introduceti id-ul zborului pe care il cautati:"<<endl;
                int nrid;
                cin>>nrid;
                for(i=0;i<r[nr].nr_zboruri;i++)
                    if(nrid==r[nr].z[i].id)
                    {
                        ok1==1;
                        cout<<"Ruta cu numarul "<<nrid<<" a fost gasita";
                        break;
                    }
                if(ok1==0)
                    cout<<"Ruta cu numarul "<<nrid<<" NU a fost gasita";

                break;//afiseaza doar ca nu gaseste id-ul !?
            }
            else
                cout<<"Imposibil.Ruta nu exista";

        }
        case 6:
            {

            }
        case 8:
            {
                ok=0;
                break;
            }

        }


    }
    return 0;
}


