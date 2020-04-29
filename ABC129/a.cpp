#include <stdio.h>

int main(void){
    int p;
    int q;
    int r;

    scanf("%d",&p);
    scanf("%d",&q);
    scanf("%d",&r);

    if(p>=q && p>=r){
        printf("%d",q+r);
    }else if(q>=p && q>= r){
        printf("%d",p+r);
    }else{
        printf("%d",p+q);
    }

    return 0;
}