// 写経

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i,n) for(ll i=0; i<(n); i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define ALL(n) begin(n),end(n)
#define IN(a, x, b) (a<=x && x<b)
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T & a, const T b) { return a = (a > b) ? b : a; }

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const long long MOD = 1000000007;

ll n;
string x;

ll fix(ll o, ll m){
    o%=m;
    if(o<0){
        o+=m;
    }
    return o;
}

ll calc(ll mod){
    if(mod == 0){
        return -1;
    }
    ll rem = 0;
    REP(i, n){
        rem = (2*rem + x[i]-'0') %mod;
    }
    return rem;
}

ll foo(ll input){
    ll ans = 0;
    while(input ){
        input %= __builtin_popcount(input);
        ans++;
    }
    return ans;
}

int main(void){
    ll cnt =0;

    cin >> n;
    cin >> x;
    REP(i,n){
        if(x[i] == '1'){ //文字列 -> ゴリ押しpopcnt
            cnt++;
        }
    }

    ll x_minus_1 = calc(cnt -1); // x%(popcnt(x)-1)の計算
    ll x_plus_1 = calc(cnt +1); // x%(popcnt(x)+1)の計算

    ll pl =1;
    ll ph =1;

    vector<ll> ans(n);
    for(ll i=n-1; i>=0; i--){
        if(x[i]=='1' && cnt == 1){ //すべて0となるような場合 -> 割り算するまでもなく0
            ans[i]=0;
        }else{
            ll r =0;
            if(x[i] == '1'){
                r = fix(x_minus_1 -pl, cnt-1);  //1->0にする側。 割ったあまりから減算
            }else{
                r = fix(x_plus_1 +ph, cnt+1);   //0->1にする側。 割ったあまりに加算
            }
            ans[i] = 1+ foo(r); // 最初の１回+あとはゴリ押し
        }
        pl = 2* pl % (cnt ==1 ? 1: cnt-1); //次の桁(減算)。1つしかbitないときは0になると困るので1
        ph = 2* ph % (cnt+1); //次の桁(加算)
    }
    for(ll tans: ans){
        cout << tans << endl;
    }


    return 0;
}