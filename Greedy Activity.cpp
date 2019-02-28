#include<iostream>
#include<conio.h>
using namespace std;

class Activity
{
      private:
              int start, finish;
      public:
             Activity()
             {
                  start=0;
                  finish=0;
             }
             Activity(int s, int f)
             {
                  start=s;
                  finish=f;
             }
             void setStart(int s)
             {
                  start=s;
             }
             void setFinish(int f)
             {
                  finish=f;
             }
             int getStart()
             {
                 return start;
             }
             int getFinish()
             {
                 return finish;
             }
             void display()
             {
                  cout<<"Start: "<<start<<"  Finish: "<<finish<<endl;
             }
};

void sortList(Activity act[], int s)
{
     int i=0;
     while(i<s)
     {
          int j=i;
          while(j<s)
          {
               Activity temp;
               if(act[i].getFinish()>act[j].getFinish())
               {
                    temp=act[i];
                    act[i]=act[j];
                    act[j]=temp;
               }
               j++;
          }
          i++;
     }
}

void greedySelection(Activity act[], int s)
{
     int j=0;
     act[j].display();
     for(int i=1; i<=s; i++)
     {
         if(act[i].getStart() >= act[j].getFinish())
         {
                act[i].display();
                j=i;
         }
     }
}
int main()
{
    Activity a(0,2);
    Activity b(3,5);
    Activity c(4,9);
    Activity d(10,12);
    Activity e(8,10);
    Activity f(1,5);
    Activity g(5,8);
    Activity list[] ={a,b,c,d,e,f,g};
    cout<<"Original List: "<<endl;
    for(int i=0; i<7; i++)
    {
         list[i].display();
    }
    cout<<endl;
    cout<<"Sorted List: "<<endl;
    sortList(list, 7);

    for(int i=0; i<7; i++)
    {
         list[i].display();
    }

    cout<<endl;
    cout<<"Selected Activity List: "<<endl;
    greedySelection(list, 7);


    getch();
    return 0;
}
