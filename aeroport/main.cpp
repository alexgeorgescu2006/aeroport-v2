#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;
ifstream f("aeroport.in");
struct datan
{
    int zi,luna,an,ora,minut,fus_orar;
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

void citire_rute(int i)
{
    f>>r[i].sursa>>r[i].destinatie>>r[i].nr_zboruri;
}

void citire_zboruri(int i)
{
    for (int j = 0; j < r[i].nr_zboruri; j++)
        {
            f>>r[i].z[j].id>>r[i].z[j].durata;
            f>>r[i].z[j].plecare.zi>>r[i].z[j].plecare.luna>>r[i].z[j].plecare.an;
            f>>r[i].z[j].plecare.ora>>r[i].z[j].plecare.minut;
            f>>r[i].z[j].plecare.fus_orar;
            f>>r[i].z[j].sosire.zi>>r[i].z[j].sosire.luna>>r[i].z[j].sosire.an;
            f>>r[i].z[j].sosire.ora>>r[i].z[j].sosire.minut;
            f>>r[i].z[j].sosire.fus_orar;
            f>>r[i].z[j].model_aeronava;
            f>>r[i].z[j].nr_locuri;
        }
}

int main()
{
    int i, j, n;
    f>>n;
    for(int i=0;i<n;i++)
        citire_rute(i);

    for (i = 0; i < n; i++)
        citire_zboruri(i);

    int ok = 1; char op;

    //cautarea zborurilor dintr-un oras -> a
    //ora de sosire / plecare a unui zbor
    while (ok == 1)
    {
        system("cls");
        cout<<"Introduceti o valoare (1-5) pentru a efectua una dintre operatiunile de mai jos:"<<endl;
    cout<<"1. Adaugarea unei ruta."<<endl;
    cout<<"2. Adaugare zbor pe o anumita ruta."<<endl;
    cout<<"3. Afisarea tuturor zborurilor de pe o anumita ruta, crescator in functie de numarul de locuri."<<endl;
    cout<<"4. Verificarea existentei unui zbor pe o anumita ruta."<<endl;
    cout<<"5. Verificarea existentei unei anumite aeronave pe o anumita ruta."<<endl;
    cout<<"6. Stop."<<endl;
        op=getch();
        system("cls");
        switch(op)
        {
        case '1':
            {
                cout<<"Adaugarea unei rute."<<endl;
                cout<<"Introduceti orasul de plecare si destinatia:"<<endl;
                n++;
                cin>>r[n-1].sursa>>r[n-1].destinatie;
                r[n-1].nr_zboruri = 0;
                system("cls");
                cout<<"Ruta adaugata cu succes!"<<endl;
                cout<<"Inapoi"<<endl;
                getch();
                break;
            }
        case '2':
            {
                cout<<"Adaugarea unui zbor pe o anumita ruta."<<endl;
                cout<<"Introduceti numarul de ordine al rutei pe care vreti sa adaugati un zbor:"<<endl;
                int nr;
                cin>>nr;
                if (nr < n)
                {
                    cout<<"Se adauga un zbor pe ruta de la "<<r[nr].sursa<<" la "<<r[nr].destinatie<<endl;
                    cout<<"Introduceti informatiile despre zbor:"<<endl;

                    r[nr].nr_zboruri++;
                    int x = r[nr].nr_zboruri - 1;
                    system("cls");
                    cin>>r[nr].z[x].id>>r[nr].z[x].durata;
                    getch();
                    system("cls");
                    cin>>r[nr].z[x].plecare.zi>>r[nr].z[x].plecare.luna>>r[nr].z[x].plecare.an;
                    getch();
                    system("cls");
                    cin>>r[nr].z[x].plecare.ora>>r[nr].z[x].plecare.minut;
                    getch();
                    system("cls");
                    cin>>r[nr].z[x].sosire.zi>>r[nr].z[x].sosire.luna>>r[nr].z[x].sosire.an;
                    getch();
                    system("cls");
                    cin>>r[nr].z[x].sosire.ora>>r[nr].z[x].sosire.minut;
                    getch();
                    system("cls");
                    cin>>r[nr].z[x].model_aeronava;
                    getch();
                    system("cls");
                    cin>>r[nr].z[x].nr_locuri;
                    getch();
                    system("cls");
                    cout<<"Zborul a fost adaugat!"<<endl;
                    getch();
                }
                else{
                    system("cls");
                    cout<<"Imposibil. Ruta nu exista."<<endl;
                    getch();
                }

                break;

            }
        case '3':
            {
                int nr;
                cout<<"Afisarea tuturor zborurilor de pe o anumita ruta, crescator in functie de numarul de locuri:"<<endl;
                cout<<"Introduceti numarul de ordine a rutei:"<<endl;
                cin>>nr;
                system("cls");
                if(nr<n)
                {
                    for(i=0;i<r[nr].nr_zboruri-1;i++)
                        for(j=i+1;j<r[nr].nr_zboruri;j++)
                            if(r[nr].z[j].nr_locuri>r[nr].z[i].nr_locuri)
                            {
                                 swap(r[nr].z[j],r[nr].z[i]);
                            }
                    for(i=0;i<r[nr].nr_zboruri;i++)
                        cout<<r[nr].z[i].id<<endl;
                    getch();
                }
                else{
                    system("cls");
                    cout<<"Imposibil.Ruta nu exista"<<endl;
                    getch();
                }


                break;
            }

        case '4':
        {
            int nr,ok1=0;
            cout<<"Verificarea existentei unui zbor pe o anumita ruta:"<<endl;
            cout<<"Introduceti numarul de ordine a rutei:"<<endl;
            cin>>nr;
            if(nr<n)
            {
                cout<<"Introduceti id-ul zborului pe care il cautati:"<<endl;
                int nrid;
                cin>>nrid;
                for(i=0;i<r[nr].nr_zboruri;i++)
                {
                    if(nrid==r[nr].z[i].id)
                    {
                        ok1=1;
                        system("cls");
                        cout<<"Ruta cu numarul "<<nrid<<" a fost gasita"<<endl;
                        getch();
                        break;
                    }
                }

                if(ok1==0)
                {
                    system("cls");
                    cout<<"Ruta cu numarul "<<nrid<<" NU a fost gasita"<<endl;
                    getch();
                }

            }
            else{
                system("cls");
                cout<<"Imposibil.Ruta nu exista"<<endl;
                getch();
            }
            break;
        }

        case '5':
            {

            }
        case '6':
            {
                system("cls");
                cout<<"Am iesit de pe pagina principala. ";
                ok=0;
                break;
            }
        default:
            {
                system("cls");
                cout<<"Introduceti alta tasta!"<<endl;
                getch();
                break;
            }
        }
    }
    return 0;
}

