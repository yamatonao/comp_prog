#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string s;

int main(void){
    int n=0;
    bool ans = true;
    cin >> s;
    n = s.size();
    int num = (s.size()-1)/2;
    if(num % 2){
        num=(num -1) /2;
    }else{
        num = num/2;
    }

    for(int i=0; i< (n-1)/2; i++){
//            cout << s[i] << " " << s[(s.size())-i-1] << endl ;
        if(s[i] != s[ (s.size()-1)-i ] ){
            ans = false;
            break;
        }
    }


    for(int i=0; i< num; i++){
        
//             cout << s[i] << " " << s[ (((n-1)/2) -1)-i ] << endl;
        if(s[i] != s[ (((n-1)/2) -1)-i  ] ){
            ans = false;
            break;
        }
    }


    for(int i=0; i< num; i++){
        if(s[ (((n+3)/2)-1)+i ] != s[(s.size()-i)-1] ){
            ans = false;
            break;
        }
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;

    }

    return 0;
}