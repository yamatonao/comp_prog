#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int ans=0;
    int m=0;
    int n=0;

    cin >> n;
    cin >> m;
    for(int i=1; i<n; i++){
        ans += n-i;
    }
    for(int i=1; i<m; i++){
        ans += m-i;
    }
    cout << ans << endl;
    
    return 0;
}