#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int price[6],weight[6];
    int value[6][12];
    int keep[6][12];

    for(int i=0; i<6; i++)
    {
        if(i==0)
        {
            price[i]=0;
            weight[i]=0;
        }
        else
        {
            cout<<"Weight of item "<<i<<" : ";
            cin>>weight[i];
            cout<<"Price of item "<<i<<" : ";
            cin>>price[i];
        }
    }

    for(int i=0; i<6; i++)
    {
        value[i][0]=0;
    }

    for(int j=0; j<12; j++)
    {
        value[0][j]=0;
    }

    for(int i=1; i<6; i++)
    {
        for(int j=1; j<12; j++)
        {
            if(weight[i] > j || value[i-1][j] > price[i]+value[i-1][j-weight[i]])
            {
                value[i][j] = value[i-1][j];
                keep[i][j] = 0;
            }
            else
            {
                value[i][j] = price[i] + value[i-1][j-weight[i]];
                keep[i][j] = 1;
            }
        }
    }

    cout<<endl<<endl;
    cout<<"Selected: "<<endl;
    int j=11;
    for(int i=5; i>=1; i--)
    {
        if(keep[i][j] == 1)
        {
            cout<<"Item no "<<i<<": "<<"Weight "<<weight[i]<<" Price "<<price[i]<<endl;
            j = j - weight[i];
        }

    }

    getch();
    return 0;
}
