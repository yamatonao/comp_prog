#include <iostream>

using namespace std;

int main(void){
    unsigned int n;
    unsigned int h[100000];

    cin >> n; 
    for(unsigned int i=0; i<n; i++){
        cin >> h[i];
    }

    int ans = 1;
    unsigned int max = 0;

    for(unsigned int i=0; i<n; i++){
        if( h[i] > max){
            max = h[i];
            continue;
        }
        if( max > h[i] + 1){
            ans = 0;
            break;
        }
    }

    if(ans == 0){
        cout << "No"; 
    }else{
        cout << "Yes";
    }

    return 0;
}