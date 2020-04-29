#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    unsigned long long int n=0;
    vector<pair<unsigned long long int, unsigned long long int> > tasks;
    cin >> n;
    for(int i=0; i<n; i++){
        unsigned long long int tmp1;
        unsigned long long int tmp2;
        cin >> tmp1;
        cin >> tmp2;
        tasks.emplace_back(tmp2, tmp1);
    }


    sort(tasks.begin(),tasks.end());

    unsigned long long int sum = 0;
    bool flag = true;
    for(int i=0; i<n;i++){
        sum += tasks[i].second;
        if(sum > tasks[i].first){
            flag = false;
        }
        // cout << " " << tasks[i].first << "/"<< sum << endl;
    }

    if(flag){
        cout << "Yes";
    }else{
        cout << "No" ;
    }

    return 0;
}
