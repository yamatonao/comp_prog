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

vector<ll> common;
vector<ll> alice;
vector<ll> bob;
vector<ll> alice_sum;
vector<ll> bob_sum;

int main(void){
    ll n;
    ll k;
    ll common_val=0;
    ll alice_val=0;
    ll bob_val=0;
    cin >> n >> k;
    REP(i,n){
        ll tmp1;
        ll tmp2;
        ll tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        if(tmp2 && tmp3){
            common.push_back(tmp1);
        }else if(tmp2){
            alice.push_back(tmp1);
        }else if(tmp3){
            bob.push_back(tmp1);
        }
    }
    sort(ALL(common));
    sort(ALL(alice));
    sort(ALL(bob));
    REP(i, alice.size()){
        alice_val += alice[i];
        alice_sum.push_back(alice_val);
    }
    REP(i, bob.size()){
        bob_val += bob[i];
        bob_sum.push_back(bob_val);
    }

    ll val = common.size();
    ll loop_num = k;
    ll ans =INF;
    CHMIN(loop_num, val);
    if(common.size()+alice_sum.size() < k || common.size()+bob_sum.size() < k){
        cout << -1 << endl;
        return 0;
    }

    ll xxx_val=0;
    for(ll i =-1; i<loop_num; i++){
        ll tmp_ans =0;
        ll rest_num = k-(i+1);
        if(i != -1){
            xxx_val += common[i];
            tmp_ans += xxx_val;
        }

        if( alice_sum.size()< rest_num || bob_sum.size()<rest_num){
            continue;
        }

        if(rest_num >0){
            tmp_ans += alice_sum[rest_num-1];
            tmp_ans += bob_sum[rest_num-1];
        }
        CHMIN(ans, tmp_ans);
    }
    cout << ans << endl;
    return 0;
}