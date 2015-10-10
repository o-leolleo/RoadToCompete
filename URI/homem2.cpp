#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int LSOne(int i){  return (i & (-i)); }

class FenwickTree{
  private:
    vector<int> ft;
    int n;
  public:
    FenwickTree(int _n)
    {
      ft.assign(_n+1,0);
      n = _n;
    }
    int rsq(int b){
      int sum = 0;
      for(;b; b -= LSOne(b))
        sum += ft[b];
      return sum;
    }
    int rsq(int a,int b){
      return  rsq(b) - ( a == 1 ? 0 : rsq(a-1) );
    }

    void adjust(int k, int v){
      for(; k < (int) ft.size(); k += LSOne(k))
        ft[k] += v;
    }

    void adjust(int a, int b, int v){
      adjust(a,v);
      if(b+1 <= n)adjust(b+1,-1*v);
    }

};

int main(){
  int n,m,i,j,t;
  char line[20];
  while(scanf("%d %d",&n,&m)==2){
    getchar();
    FenwickTree ft1(n);
    FenwickTree ft2(n);
    FenwickTree ft3(n);
    for(i=1;i<=n;i++) {
      ft1.adjust(i,1);
      ft2.adjust(i,0);
      ft3.adjust(i,0);
    }
    for(t=0;t<m;t++){
      gets(line);
      //puts(line);
      if(line[0]=='M'){
        sscanf(line,"%*c %d %d",&i,&j);

        int a = ft1.rsq(i,j);
        int b = ft2.rsq(i,j);
        int c = ft3.rsq(i,j);

        ft1.adjust(i,j,c-a);
        printf("%d <\n", ft1.rsq(i,i));
        ft2.adjust(i,j,a-b);
        ft3.adjust(i,j,b-c);
        /*
        for(int k=a;k<=b;k++){
          ft1.adjust(i,j,c-a);
          ft2.adjust(i,j,a-b);
          ft3.adjust(i,j,b-c);
        }
        */
      }else{
        //comando C
        sscanf(line,"%*c %d %d",&i,&j);
        int a = ft1.rsq(i,j);
        int b = ft2.rsq(i,j);
        int c = ft3.rsq(i,j);
        printf("%d %d %d\n",a,b,c);
      }
    }
    printf("\n");
  }
  return 0;
}
