#include <stdio.h>
int main(void){

  unsigned long long int n=0;
  unsigned long long int ans=0;

  scanf("%llu",&n);

  for(unsigned long long int i=1;i<n;i++){
    if( (n/i) == (n%i) ){ans += i;}
  }

  printf("%llu",ans);

  return 0;
}
