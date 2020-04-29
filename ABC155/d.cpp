#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int k;

int boder =0;

vector<long long int> a;

int main(void){
    //k番目にくる数だけ計算する。
    cin >>n;
    cin >>k;

    for(int i=0; i<n; i++){
        long long int tmp;
        cin >> tmp;
        if(tmp<0){
            boder++;
        }
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    




}