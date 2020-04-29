#include <iostream>
using namespace std;

int main(void){
    int a;
    int b;
    int c;

    cin >>a;
    cin >>b;
    cin >>c;

    if(a == b && a!=c){
        cout << "Yes" << endl;
    }else if(b==c && a!= b){
        cout << "Yes" << endl;
    }else if(a==c && a!= b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}