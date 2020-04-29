#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


    vector<int> a;
    long long int anum[200010];
    long long int a_0[200010];
    long long int a_1[200010];
    long long int ans=0;
    int n=0;

int main(void){
    cin >> n;
    for(long long int i=0; i<n;i++){
        long long int tmp=0;
        cin >> tmp;
        a.push_back(tmp);
        anum[tmp]++;
    }

//    cout << endl;
 //   for(int i=0; i<n; i++){
 //       cout << anum[i] << " " << endl;
 //   }
//    cout << endl;

    for(long long int i=0; i<=200005; i++){
        if( (anum[i] == 0 ) ||
            (anum[i] == 1 ) ){
            a_0[i] = 0;
            a_1[i] = 0;
        }
        a_0[i] = (anum[i] * (anum[i] -1)) /2;
        if( (anum[i] == 0 ) ||
            (anum[i] == 1 ) ||
            (anum[i] == 2 )  ) {
            a_1[i] = 0;
        }
        a_1[i] = ((anum[i]-1) * (anum[i] -2)) /2;
    }

    for(long long int i=0; i<=200005; i++){
        ans += a_0[i];
    }
    for(long long int i=1; i<=n; i++){
        long long int tmpans = ans;
        tmpans -= a_0[a[i-1]];
        tmpans += a_1[a[i-1]];
        cout << tmpans << endl;
    }

    return 0;
}