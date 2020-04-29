// its Kata(copy code for practice )
// src:https://atcoder.jp/contests/abc125/submissions/5207651

#include <iostream>
#include <set>

using namespace std;

int gcd(int a, int b){
  // ユークリッドの互除法
  if(a%b==0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int main(void){

  set<int> a;
  set<int> b;

  int x;
  int n;
  int k=0;
  int i;
  int ans = 1;

  //read datas
  cin >> n;

  for(i=0; i<n;i++){
    b.clear();  // 初期化
    swap(a,b);  // aとbをまるごと入れ替え
                // aは初期化状態
                // bは前回のaの値が入る

    cin >> x;   // Ax read

    for(set<int>::iterator it=b.begin(); it != b.end(); it++){
      a.insert( gcd(*it, x) ); // 今までの最大公約数 と今回読み込んだ数との最大公約数を順次求めてaに追加
    }
    a.insert(k);    // aにkを追加
    k = gcd( k, x); // kに kと今回読み込んだxの値の最大公約数を代入
  }

  // n = 3
  // 7 6 8
  // 
  // 1st time i=0
  // start end 
  // x = 7    / x = 7
  // a = none / a = 0 
  // b = none / b = none
  // k = 0    / k = 7

  // 2nd time i=1
  // x = 6    / x = 6
  // a = none / a = 6(0, 6), 7(k)
  // b = 0    / b = 0
  // k = 7    / k = 1(7, 6)

  // 3rd time i=2
  // x = 8    / x = 8
  // a = none / a = 2(6, 8), 1(7, 8), 1(k)
  // b = 6,7  / b = 6, 7
  // k = 1    / k = 2 (6, 8)

  for(set<int>::iterator it=a.begin(); it != a.end(); it++){
    ans = max(ans, *it);
  }
  cout << ans << endl;

  return 0;

}

