#include <iostream>
#include <stdio.h>

using namespace std;

int main(void){
    unsigned long long int a = 0;
    unsigned long long int b = 0;
    unsigned long long int c = 0;
    unsigned long long int d = 0;
    unsigned long long int ans =0;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    ans = b-(a-1);

    unsigned long long int tmp1 = (b/c) - ( (a-1) /c );
    unsigned long long int tmp2 = (b/d) - ( (a-1) /d );

    unsigned long long int lcm = c * d;
    if(c<d){
        unsigned int long long tmp = c;
        c = d;
        d = tmp;
    }

    unsigned int long long r = c % d;
    while(r!=0){
        c = d;
        d = r;
        r = c % d;
    }
    lcm = lcm / d;

    unsigned long long int tmp3 = (b/lcm) - ( (a-1) /lcm );

    ans += tmp3;
    ans -= tmp1;
    ans -= tmp2;
    cout << ans;

    return 0;
}