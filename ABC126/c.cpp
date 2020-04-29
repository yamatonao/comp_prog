#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

int main(void){
    int n =0;
    int k=0;
    double ans = 0;

    scanf("%d",&n);
    scanf("%d",&k);

    for(int i = 1; i<=n;i++){
        int j=0;
        int tmp_point = i;
        double tmp_per = ((double)1/(double)n);

        for(j=0; tmp_point< k; j++ ){
            tmp_point = tmp_point *2;
            tmp_per = tmp_per * (1.0/2.0);
//            printf("tpe = %lf\n",tmp_per);
        }
        ans += tmp_per;

//        printf("t = %lf\n",ans);
    }

    printf("%.10lf",ans);

    return 0;
}