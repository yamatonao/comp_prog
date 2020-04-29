#include <iostream>
using namespace std;

int n;
int a[1001];

int main(void){
    int ans=0;

    cin >> n;
    for(int i =0; i<n; i++){
        cin >> a[i];
    }

    for(int i =0; i<n; i++){
        if( (a[i] % 2) ==0){
            if( ((a[i]% 3)==0) || ((a[i]% 5)==0) ){
                continue;
            }else{
                ans = 1;
                break;
            }
        }
    }

    if(ans){
        cout <<  "DENIED" << endl;
    }else{
        cout << "APPROVED" << endl;
    }

    return 0;
}