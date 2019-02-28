#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int v;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<endl;
    int d[v][v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(i==j)
            {
                d[i][j]=0;
            }
            else
            {
                cout<<"Enter weight from "<<i+1<<" to "<<j+1<<": ";
                cin>>d[i][j];
            }
        }
    }
    int p[v][v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            p[i][j] = 0;
        }
    }

    for(int k=0; k<=v; k++)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k+1;
                    cout<<endl;
                    cout<<i<<k<<j<<endl<<endl;
                }
            }
        }
    }
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }

    getch();
    return 0;
}
