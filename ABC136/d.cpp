#include <iostream>
#include <string>
#include <string.h>


using namespace std;

int main(void){
    int childnum[100000] = {0};
    int childnum_bk[100000] = {0};
    int childnum_bkk[100000] = {0};
    string s;
    cin >> s;
    unsigned int tmp;

    for(int i=0; i<s.size(); i++){
        childnum_bk[i] = 1;
    }

    while(1){
        tmp++;
        for(int i=0; i<s.size(); i++){
            if(i==0){
                childnum[1] += childnum_bk[0];
            }else if(i == 99999){
                childnum[99998] += childnum_bk[99999];
            }else{
                if(s[i] == 'L'){
                    childnum[i-1] += childnum_bk[i];
                }else{
                    childnum[i+1] += childnum_bk[i];
                }
            }
        }
        
        if( (memcmp(childnum, childnum_bkk, s.size())==0) && (tmp%2==0) ){break;}

        memcpy(childnum_bkk ,childnum_bk, 100000); //bk to bkk
        memcpy(childnum_bk ,childnum, 100000); //now to bk
        memset(childnum , 0, 100000); //now to bk
    }

    for(int i=0; i<s.size(); i++){
        cout << childnum[i] << " ";
    }
    

    return 0;
}