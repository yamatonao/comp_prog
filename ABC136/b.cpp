#include <iostream>

using namespace std;

int main(void){
    int n;
    int ans;
    // 1        1-9 no (10-1)
    // 10       0
    // 100      1-9 + (100 - 999) = 9 + 900
    // 1000     0
    // 10000    1-9 + (100 - 999) + (10000 - 99999) = 9 + 900 + 900000
    // 100000

    cin >> n;
    if(n == 100000){
        ans = 90909;
    }else if (n > 9999){
        ans = 9 + 900 + (n - 10000 + 1);
    }else if(n > 999){
        ans = 9 + 900;
    }else if(n > 99){
        ans = 9 + (n-100 +1);
    }else if(n > 9){
        ans = 9;
    }else{
        ans = (n);
    }

    cout << ans ;
    return 0;
}