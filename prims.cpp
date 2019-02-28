#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int adj[4][4];
    int parent[4];
    int cost[4];
    char color[4];
    for(int i=0; i<4; i++)
    {
        parent[i]=0;
        cost[i]=99;
        color[i]='w';
    }
    cost[0]=0;
    color[0]='b';
    parent[0]=0;

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i==j)
            {
                adj[i][j]=0;
            }
            else
            {
                cout<<"Enter cost of edge from "<<i<<" to "<<j<<endl;
                cin >> adj[i][j];
            }
        }
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i!=j)
            {
                if(adj[i][j]<cost[j])
                {
                    cost[j]=adj[i][j];
                    parent[j]=i;
                }
            }
        }
        int temp=0;
        for(int k=0; k<4; k++)
        {
            if(color[k] != 'b' && cost[k] < cost[temp])
            {
                temp = k;
            }
        }
        color[temp]='b';
    }

    for(int i=0; i<4; i++)
    {
        cout<<"Vertex "<<i<<" Cost: "<<cost[i]<<" Color: "<<color[i]<<" Parent: "<<parent[i]<<endl;
    }

    getch();
    return 0;
}
