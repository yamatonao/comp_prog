#include <iostream>

using namespace std;

int main(void){
    int a;
    int b;
    int c;
    cin >> a;
    cin >> b;
    cin >> c;

    int tmp;
    int ans;
    tmp = a-b;
    if(tmp > c){
        ans = 0;
    }else{
        ans = c-tmp;
    }

    cout << ans;

    return 0;
}