#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

int main(void){
    string input;
    char buf1[3] = {0};
    char buf2[3] = {0};
    int a = 0;
    int b=0;
    int a_pattern = 0;
    int b_pattern = 0;

    cin >> input;
    buf1[0] = input[0];
    buf1[1] = input[1];
    buf2[0] = input[2];
    buf2[1] = input[3];

    a = atoi(buf1);
    b = atoi(buf2);

    if(a ==0 || a>12){
        a_pattern =1;
    }

    if(b ==0 || b>12){
        b_pattern =1;
    }

    if(a_pattern==1 && b_pattern ==1){
        printf("NA");
    }else if(a_pattern ==1){
        printf("YYMM");
    }else if(b_pattern ==1){
        printf("MMYY");
    }else{
        printf("AMBIGUOUS");
    }

    return 0;
}