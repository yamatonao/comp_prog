#include <iostream>
#include <vector>
using namespace std;

void comb(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

int main(void){
    int n =0;
    long long int a[100000] = {0};

    cin >> n ;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long int max=0;
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max = a[i];
        }
    }


    long long int ans2= 0;
    long long int val = 0;

    for(int i=0; i<n; i++){
        if(a[i] != max){
            vector<vector<long long int> > v(max+1,vector<long long int>(max+1,0));
            comb(v);
            if(v[max][a[i]] > val){
                ans2 = a[i];
                val = v[max][a[i]];
            }
        }
    }

    cout << max << " " << ans2;

    return 0;
}