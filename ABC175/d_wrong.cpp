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


typedef struct{
    ll action;
    ll score;
}TY_input;
map <ll, TY_input> walk;

int main(void){
    ll n;
    ll k;
    vector <ll> p;
    vector <ll> c;
    cin >> n >> k;
    REP(i,n){
        ll tmp;
        cin >>tmp;
        p.push_back(tmp);
    }
    REP(i,n){
        ll tmp;
        cin >>tmp;
        c.push_back(tmp);
    }

    ll ans =-INF;
    for(ll in=0; in<n; in++){
        ll tmp_ans=0;
        ll now_town=in;
        if( k<n){ // 閉路検出不要なら気合い入れて計算
            REP(jk,k){
                now_town = (p[now_town]-1);
                tmp_ans += (c[now_town]);
                CHMAX(ans,tmp_ans);
            }
            continue;
        }

        ll walk_time = 0;
        walk.clear();
        while(1){
            now_town = (p[now_town]-1);
            if(walk.find(now_town) == walk.end() ){//存在しない
                TY_input tmp_ty;
                walk_time++;
                tmp_ans += (c[now_town]);
                tmp_ty.action = walk_time;
                tmp_ty.score = tmp_ans;
                CHMAX(ans,tmp_ans);
                walk.insert({now_town, tmp_ty});
            }else{// 閉路発見
                walk_time++;
                tmp_ans += (c[now_town]);
                CHMAX(ans,tmp_ans);

                ll rest_action  = k-walk_time;
                ll move_actions = walk_time - walk[now_town].action;
                ll loop_num = rest_action/move_actions;
                ll mod = rest_action % move_actions;

                ll rest = 0;
                if(loop_num >0){
                    rest = mod + move_actions;
                    tmp_ans += ((walk[now_town].score-tmp_ans) * (loop_num-1) );
                    CHMAX(ans,tmp_ans);
                }else{
                    rest=mod;
                }

                for(ll last_i=0; last_i < rest; last_i++){
                    walk_time++;
                    now_town = (p[now_town]-1);
                    tmp_ans += (c[now_town]);
                    CHMAX(ans,tmp_ans);
                }
                break;
            }

        }
    }
    cout << ans << endl;
    return 0;
}