#include <stdio.h>

typedef struct
{
 int n;
 int next;

}no;

void iniciar (no *p,  int n)

{
int i;

 for (i=0;i<n-1;i++)
 {
     p[i].n=i+1;
     p[i].next=i+1;

 }
  p[i].n=i+1;
  p[i].next=0;
}

   int retirar (no *p,   int x, int k)
{
 int guia,k1;
 guia=0;


  while (x-1)
    {
      k1=k;
     while (k1-1)
        {
         guia=p[guia].next;
         k1--;
        }
        p[guia].n=p[p[guia].next].n;
        p[guia].next=p[p[guia].next].next;



   x--;
    }
  return p[guia].n;

}

int main() {

  int NC;
  no lista [10000];
  int i,k,m,n,N[30];
  no *p;
  p=&lista[0];



scanf ("%i",&NC);

    for (i=0;i<NC;i++)
    {
     scanf ("%i %i",&n,&k);
      iniciar (p,n);

     N[i]=retirar(p,n,k);

    }
  for (n=1;n<=NC;n++)
  {
   m=N[n-1];
   printf (" Case %i: %i \n",n,m);
  }

}
