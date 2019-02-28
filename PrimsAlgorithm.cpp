#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int adj[5][5];
    int cost[5], par[5];
    char col[5];
    int i=0, j=0;
    while(i<5)
    {
         if(i==1)
         {cost[i]=0;}
         else
         {cost[i]=99;}
         i++;
    }
    i=0;
    while(i<5)
    {
         par[1]=1;
         par[i]=0;
         col[i]='w';
         i++;
    }
    i=0;
    while(i<5)
    {
       while(j<5)
       {
          if(i==0 || j==0 || i==j)
          {adj[i][j]=0;}
          else
          {
           cout<<"Enter weight of Edge "<<i<<" -> "<<j<<": "<<endl;
           cin>>adj[i][j];
          }
          j++;
       }
       j=0;
       i++;
    }
    i=1, j=1;
    int z;
    while(i<5)
    {
         z=1;
         while(j<5)
         {
              if(i!=j)
              {
                   if(adj[i][j]<cost[j])
                   {cost[j]=adj[i][j];
                    par[j]=i;}
              }
              j++;
         }
         j=1;
         z=1;
         while(j<5)
         {
             if(i!=j)
             {
              if(col[z]=='b' && z<4)
              z++;
              if(cost[j]<cost[z] && col[j]!='b')
              {z=j;}
             }
             j++;
         }
         col[z]='b';
         j=1;
         i++;
    }
    i=1;
    while(i<5)
    {
         cout<<"Vertex "<<i<<" Color: "<<col[i]<<" Cost: "<<cost[i]<<" Parent: "<<par[i]<<endl;
         i++;
    }
    getch();
    return 0;
}
