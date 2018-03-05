#include <iostream>
#include <fstream>
using namespace std;
ifstream f("rucsac.in");

struct obiect { float greutate;
                int numar;
                int cost;
              };
obiect a[100];
int gmax,n;

void citire (obiect a[],int n)
  {f>>n;
   f>>gmax;
   for(int i=1;i<=n;i++)
     {f>>a[i].greutate;
      f>>a[i].cost;
      a[i].numar=i;
     }
  }

void afisare (obiect a[],int n)
  { cout<<"Lista de obiecte este: "<<endl;
    for(int i=1;i<=n;i++)
      cout<<"Obiectul "<<a[i].numar<<" are greutatea "<<a[i].greutate<<" si profitul de: "<<a[i].cost<<endl;
  cout<<endl;
  }

void sortare(obiect a[],int n)
  { int ok;
    obiect aux;
    do{
       ok=1;
       for(int i=1;i<=n-1;i++)
         if(a[i].cost<a[i+1].cost)
           {aux=a[i];a[i]=a[i+1];a[i+1]=aux;ok=0;}
         else
           if(a[i].cost==a[i+1].cost)
             if(a[i].greutate>a[i+1].greutate)
                 { aux=a[i];a[i]=a[i+1];a[i+1]=aux;ok=0;}
      }while(ok==0);
}

void greedy(obiect a[],int n)
  {for(int i=1;i<=n;i++)
     if(a[i].greutate<=gmax)
       { cout<<a[i].numar<<" ";
         gmax=gmax-a[i].greutate;
        }
  }

int main()
  {citire(a,n);
   afisare(a,n);
   sortare(a,n);
   cout<<endl;
   afisare(a,n);
   cout<<"Greedy: ";
   greedy(a,n);

}
