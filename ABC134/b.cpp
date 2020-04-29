#include <iostream>
using namespace std;

int main(void){
    long long int n;
    long long int d;
    long long int ans;

    cin >> n;
    cin >> d;

    while(1){
        ans++;
        n = n - ( 2*d+1);
        if(n<=0){break;}
    }

    cout << ans << endl;

    return 0;
}