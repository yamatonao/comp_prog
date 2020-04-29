#include <stdio.h>

int main(){
  int r=0;
  int g=0;
  int b=0;
  int n=0;
  int ans = 0;
  int ir = 0;
  int jg = 0;
  int kb = 0;

  int tmpi = 0;
  int tmpj = 0;
  int tmpk = 0;

  scanf("%d", &r);
  scanf("%d", &g);
  scanf("%d", &b);
  scanf("%d", &n);

  // (r * x) + (g + y) + (b + z) =n
  // x y zの組の数

  for(ir=0; 1; ir++){
    tmpi= ir*r;
    if( tmpi >n){ break; }

    for(jg=0; 1; jg++){
      int tmpn;
      tmpj = tmpi + (jg*g);
      if(tmpj>n){break;}
      tmpn = n-tmpj;
      if( !(tmpn%b)){
	ans++;
      }


      //      for(kb=0; 1; kb++){
      //	tmpk = tmpj + (kb*b);
      //	if(tmpk ==n  ){
      //	  ans++;
      //	}
      // 	if(tmpk>=n){break;}
      //      }

    }


  }

  printf("%d",ans);

  return 0;
}
