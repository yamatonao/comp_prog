#include <iostream>
#include <stdio.h>

using namespace std;

int main(void){
    int n = 0;
    int l = 0;
    int taste[200] = {0};

    cin >> n;
    cin >> l;

    for(int i=0;i<n;i++){
        taste[i] = l+(i+1)-1;
    }

    int value   = 1000000;
    int num     = 1000000;

    for(int i=0;i<n;i++){
        int abs = 0;
        if(taste[i] < 0){
            abs = -taste[i];
        }else{
            abs = taste[i];
        }

        if(abs < value){
            value = abs;
            num = i;
        }
    }

    // cout << num << endl;
    int ans = 0;

    for(int i=0; i<n;i++){
        if(num == i){
            continue;
        }
        ans += taste[i];
        // cout << ans << endl;
    }

    cout << ans;

    return 0;
}