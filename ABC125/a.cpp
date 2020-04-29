#include <stdio.h>

int main(){
  int a=0;
  int b=0;
  int t=0;
  int ans = 0;


  scanf("%d %d %d",&a, &b, &t);
  for(int i=1; 1;i++){
    if( (i*a) > t ){
      break;
    }
    ans += b;
  }

  printf("%d\n",ans);

  return 0;
}
