#include <iostream>
#include <stdio.h>

using namespace std;

int main(void){
    char a;
    char b;
    char c;
    char d;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    if( a == b || b==c || c==d){
        cout << "Bad";
    }else{
        cout << "Good";
    }



    return 0;
}