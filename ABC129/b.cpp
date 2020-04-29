#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);

    int w[100];
    for(int i=0;i<n; i++){
        scanf("%d",&w[i]);
    }

    int s1[100] ={0};
    int s2[100] ={0};
    int abs[100]={0};
    for(int t=1;t<n; t++){
        for(int i=0; i<t; i++){
            s1[t-1] += w[i];
            //printf("s1 %d\n",s1[t-1]);
        }
        for(int j=t; j<n; j++){
            s2[t-1] += w[j];
            //printf("s2 %d\n",s2[t-1]);
        }

        if(s1[t-1] > s2[t-1]){
            abs[t-1] = s1[t-1] - s2[t-1];
        }else{
            abs[t-1] = s2[t-1] - s1[t-1];
        }
//            printf("abs %d\n",abs[t-1]);
    }

    int ans=10000;
    for(int i=0; i<n-1;i++){
        if(ans>abs[i]){
            ans=abs[i];
//            printf("%d\n",ans);
        }
    }

    printf("%d",ans);


    return 0;
}