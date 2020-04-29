#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



std::vector<int> find_all(const std::string str, const std::string subStr) {
  std::vector<int> result;
 
  int subStrSize = subStr.size();
  int pos = str.find(subStr);
 
  while (pos != std::string::npos) {
    result.push_back(pos);
    pos = str.find(subStr, pos + subStrSize);
  }
 
  return result;
}





int main(){
  int n=0;
  int ans= 0;
  string str[10000];
  string search ="AB";

  scanf("%d\n",&n);
  for(int i=0;i<n;i++){
    cin >> str[i];
  }

  for(int i=0;i<n;i++){
    vector<int> findVec = find_all(str[i], search);
    ans += findVec.size();
  }

  int topbnum=0;
  int botanum=0;
  int Sflag = 1;
  int SSflag = 1;
  for(int i=0; i<n; i++){
    int flag = 0;
    if(str[i][0] == 'B'){
      topbnum++;
      flag++;
    }
    if(str[i][(str[i].size() -1)  ] == 'A'){
      botanum++;
      flag++;
    }

    if(flag==2){
      SSflag=0;
    }
    if(flag==1){
      Sflag = 0;
    }

  }


  int tmp=0;
  tmp = min(topbnum,botanum);
  //  tmp = min(tmp,n-1);
  ans += tmp;

  if(Sflag && (!SSflag) && (ans > 0)){ans--;}

  printf("%d",ans);

  return 0;
}
