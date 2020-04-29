#include <iostream>
using namespace std;


long long int calc_val(char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

long long int dp[10000001][2];
//ピッタリ払うときの最小
//1余分に払うときの最小

int main(void){
    string n;
    int tmp;
    cin >>n;

    tmp = calc_val( n[0] );

    dp[0][0] += tmp;
    dp[0][1] += 1+ (10-tmp);
       //cout << dp[0][0] << " " << dp[0][1] << endl;


    for(int i=1; i<n.size();i++){
        tmp = calc_val( n[i] );
        //ピッタリ払うときの最小
        dp[i][0] += min( dp[i-1][0] + tmp ,
                         dp[i-1][1] + tmp );
        //1余分に払うときの最小
        dp[i][1] += min( 
                    ( dp[i-1][0] + 1 + (10-tmp) ) , 
                    ( dp[i-1][1] - 1 + (10-tmp) ) 
                    //1つ上の桁は2つ上の桁で余分に1払っているため、必ず1余っているはずであり、それを使用していいことに注意する。
//                    ( dp[i-1][1] - 1 + (10-tmp) )
                    );
       //cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << min(dp[n.size()-1][0],dp[n.size()-1][1]) << endl;

    return 0;
}