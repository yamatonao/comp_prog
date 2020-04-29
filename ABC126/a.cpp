#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(void){
    int n =0;
    int k=0;
    int offset = 0;
    string s;

    scanf("%d",&n);
    scanf("%d",&k);
    cin >> s;

    offset = s[k-1] - 0x41;
    s[k-1] = 0x61 + offset;

    cout << s ;.

    return 0;
}