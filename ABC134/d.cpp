#include <iostream>

using namespace std;

int main (void){
    unsigned long int n;
    unsigned int a[200002] = {0};
    unsigned int box[200002] = {0};
    int ansflag = 0;
    int ansvalue = 0;
    unsigned int no[200002] = {0};

    // 0はダミーとして用いる

    //input
    cin >> n;
    for(unsigned long int i=1;i<(n+1);i++){
        cin >> a[i];
    }

    //半分以上
    for(unsigned long int i=n; i > (n/2) ; i-- ){
        if(a[i] ==1){
            box[i] = 1;
            no[ansvalue] = i;
            ansvalue++;
        }else{
            box[i] = 0;
        }
        //debug
    }

    //半分以下
    for( unsigned long i=(n/2) ; i>0; i--){
        unsigned long value = 2 * i;
        unsigned long sum = 0;

        while(value <= n){
            sum += box[value];
            value += i;
        }

        if( (sum+1)%2 == a[i] ){
            box[i] =1;
            no[ansvalue] = i;
            ansvalue++;
        }else if( sum%2 == a[i]){
            box[i] = 0;
        }else{
            ansflag = -1;
            break;
        }
    }

    if(ansflag == -1){
        cout << "-1" << endl;
    }else{
        cout << ansvalue << endl;
        for(int i=0;i<ansvalue; i++){
            cout << no[i] << " " ;
        }
    }




    return 0;
}