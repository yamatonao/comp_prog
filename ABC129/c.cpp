#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
    int n = 0;
    int m = 0;
    int broken[100001] = {0};

    cin >> n ;
    cin >> m ;
    for(int i=0; i<m; i++){
        int brokenstep = 0;
        cin >> brokenstep;
        broken[brokenstep] = -1;
//       cout << "bs:" << brokenstep << endl;
    }

    int dp[100002] = {0};
    dp[n]=1;
    for(int i=n-1; i>=0; i--){
        if(broken[i] == -1){
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i+1] + dp[i+2])%1000000007;
//        cout << "i:" << i << "  dp[i]:" << dp[i] << endl;
    }

    cout << dp[0];

    return 0;
}