#include <iostream>

using namespace std;

int main(void){
    int n;
    int a[200000];
    int leftmax[200001] = {-1};
    int rightmax[200001] = {-1};
    int ans[200000] = {-1};

    cin >> n ;
    for(int i=0; i<n; i++){
        cin >> a[i]; 
    }

    for(int i= (n-1) ; i>=0; i--){
        if(i== (n-1)) {
            rightmax[i] = a[n-1];
        }else{
            ( rightmax[i+1] > a[i] ) ? rightmax[i] = rightmax[i+1] :  rightmax[i] = a[i];
        }
//cout << rightmax[i] << " " ;
    }
//cout<<endl;

    for(int i= 0 ; i<n; i++){
        if(i== 0) {
            leftmax[i] = a[0];
        }else{
            ( leftmax[i-1] > a[i] ) ? leftmax[i] = leftmax[i-1] :  leftmax[i] = a[i];
        }
//cout << leftmax[i] << " " ;
    }
//cout<<endl;


    for(int i=0; i<n; i++){
        if(i==0){ans[i] = rightmax[1]; }
        else if(i==(n-1)){ans[i] = leftmax[n-2]; }
        else{
            if(rightmax[i+1] > leftmax[i-1] ){
                ans[i] =rightmax[i+1];
            }else{
                ans[i] = leftmax[i-1];
            }

        }
    }

    for(int j=0;j<n;j++){
        cout << ans[j] << endl;
    }

    return 0;
}