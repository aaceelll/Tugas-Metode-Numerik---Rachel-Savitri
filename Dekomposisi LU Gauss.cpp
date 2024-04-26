#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int m,n,i,j,k, pilih, maks, flag=0, count=0;
    cout<<"\t\t\t RACHEL SAVITRI "<<endl;
    cout<<endl;
    cout<<"Inputan berupa Sistem persamaan linier yang akan dijadikan dalam bentuk matriks"<<endl<<endl;
    cout<<"-Silahkan tentukan ordo matriks-"<<endl<<endl;
    cout<<"Masukkan matriks ordo: ";
    cin>>n;
    cout<<endl;
    double a[n][n+1];
    double x[n];
    double epsilon,y;
    for (i=0; i<n; i++)
    {
        for (j=0; j<=n; j++)
        {
            cout<<"Masukkan nilai matriks["<<i+1<<"]["<<j+1<<"] = ";
            cin>>a[i][j];
        }
    }
    cout<<"\nMasukkan nilai awal variabel:\n";
    for (i=0; i<n; i++)
    {
        cout<<"Nilai awal x"<<i<<" = ";
        cin>>x[i];
    }


        for (i=0; i<n; i++)
            for (k=i+1; k<n; k++)
                if (abs(a[i][i])<abs(a[k][i]))
                    for(j=0; j<=n; j++)
                    {
                        double temp=a[i][j];
                        a[i][j]=a[k][j];
                        a[k][j]=temp;
                    }

    //------------Kode Testing------------//
    cout<<endl<<endl;
    cout<<"Pengerjaan:"<<endl;
    cout<<"1. Dengan Error"<<endl;
    cout<<"2. Dengan Iterasi"<<endl;
    cout<<"Masukkan Pilihan : ";
    cin>>pilih;

    if(pilih==1)
    {
        cout<<"\nMasukkan epsilon :";
        cin>>epsilon;
        cout<<endl;
        cout<<setw(3)<<"Iterasi"<<setw(10);
        for (i=0; i<n; i++)
            cout<<"x"<<i<<setw(18);
        cout<<"\n------------------------------------------------------------------------------";

        do
        {
            cout<<"\n"<<count+1<<"."<<setw(16);
            for (i=0; i<n; i++)
            {
                y=x[i];
                x[i]=a[i][n];
                for (j=0; j<n; j++)
                {
                    if (j!=i)
                        x[i]=x[i]-a[i][j]*x[j];
                }
                x[i]=x[i]/a[i][i];
                if (abs(x[i]-y)<=epsilon)
                    flag++;
                cout<<x[i]<<setw(18);
            }
            cout<<"\n";
            count++;
        }
        while(flag<n);
        cout<<"\nSolusinya :\n";
        for (i=0; i<n; i++)
            cout<<"x"<<i<<" = "<<x[i]<<endl;
        return 0;
    }

    else if(pilih==2)
    {
        cout<<"\nMasukkan banyak iterasi:";
        cin>>maks;
        cout<<endl;
        cout<<setw(3)<<"Iterasi"<<setw(10);
        for(i=0; i<n; i++)
            cout<<"x"<<i<<setw(18);
        cout<<"\n----------------------------------------------------------------------------------";
        for (m=0; m<maks; m++)
        {
            cout<<"\n"<<count+1<<"."<<setw(16);
            for (i=0; i<n; i++)
            {
                y=x[i];
                x[i]=a[i][n];
                for (j=0; j<n; j++)
                {
                    if (j!=i)
                        x[i]=x[i]-a[i][j]*x[j];
                }
                x[i]=x[i]/a[i][i];
                if(abs(x[i]-y)<=epsilon)
                    flag++;
                cout<<x[i]<<setw(18);
            }
            cout<<"\n";
            count++;
        }
        cout<<"\nSolusinya :\n";
        for (i=0; i<n; i++)
            cout<<"x"<<i<<" = "<<x[i]<<endl;
        return 0;
    }
}
