#include <stdio.h>

int main(){
  int n = 0;
  int value[20] ={0};
  int cost[20] ={0};
  int is_buy[20] ={0};
  int ans=0;

  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d", &value[i]);
  }

  for(int i=0; i<n;i++){
    scanf("%d",&cost[i]);
  }

  for(int i=0; i<n;i++){
    if(value[i] > cost[i]){
      is_buy[i]= 1;
    }
  }

  for(int i=0; i<n;i++){
    if(is_buy[i]){
      ans += (value[i]-cost[i]);
    }
    //  printf("%d ",ans);
  }
  printf("%d",ans);
  

  return 0;
}
