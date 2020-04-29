#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int num[2000000];
vector<string>s;

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    sort(s.begin(), s.end());

    int j=0;
    int maxvote=0;
    num[0]=1;
    for(int i=1; i<n; i++){
        if(s[i-1] != s[i]){
            j++;
        }
        num[j]++;
        if(maxvote < num[j]){
            maxvote = num[j];
        }
    }
    
    s.erase(unique(s.begin(), s.end()), s.end()); 

//            cout << "##" << endl;
//            cout << maxvote << endl;
//            cout << num[0] << endl;


    for(int i=0; i<s.size(); i++){
        if(num[i] == maxvote){
            cout << s[i] << endl;
        }
    }


    return 0;
}