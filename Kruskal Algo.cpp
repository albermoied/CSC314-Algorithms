 #include<iostream>
 #include<conio.h>
 using namespace std;

 class Edge
 {
       private:
               int v1,v2,weight;
       public:
              Edge()
              {
                    v1=0;
                    v2=0;
                    weight=0;
              }
              Edge(int a, int b, int c)
              {
                       setv1(a);
                       setv2(b);
                       setweight(c);
              }
              int getv1()
              {
                  return v1;
              }
              int getv2()
              {
                  return v2;
              }
              int getweight()
              {
                  return weight;
              }
              void setv1(int x)
              {
                   v1=x;
              }
              void setv2(int y)
              {
                   v2=y;
              }
              void setweight(int z)
              {
                   weight=z;
              }
              void display()
              {
                  cout<<"("<<v1<<","<<v2<<")"<<weight<<endl;
              }
 };


 int FindSet(int k, int a[])
{
    while(a[k] != k)
	{
	    k = a[k];
	}
    return k;
}

void Union(int a, int b, int parent[])
{
    parent[a] = b;
}

 int main()
 {
     int v1,v2,weight;
     Edge a[8], b[8];
     int parent[18];
     for(int i=0; i<8; i++)
     {
             cout<<"Enter vertices: "<<endl;
             cin >> v1 >> v2;
             cout<<"Enter weight: "<<endl;
             cin >> weight;
             a[i]= Edge(v1, v2, weight);
     }

     for(int j=0; j<18; j++)
     {
         parent[j] = j;
     }

     for(int i=0; i<8; i++)
     {
         //NOTE: COMMIT SUICIDE
         int x,y;
         x= FindSet(a[i].getv1(), parent);
         y= FindSet(a[i].getv2(), parent);
         if(x!= y)
         {
                Union(x, y, parent);  //Union
                b[i] = a[i];          //Adding to MST
         }
     }

     for(int i=0; i<8; i++)
     {
         b[i].display();
     }

     getch();
     return 0;
 }
