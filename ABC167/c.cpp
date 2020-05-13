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
ll m;
ll x;
ll ans =INF;
bool is_selected[20];
ll books_info[20][20];

void bfs(ll level){
    // 最下層のとき
    if(level == 0){
        bool not_manzoku = false;
        // 満たしているか計算
        ll tmp_ans[20]={
            0,0,0,0,0,
            0,0,0,0,0,
            0,0,0,0,0,
            0,0,0,0,0};
        REP(i,n){
            if(is_selected[i] == false){
                continue;
            }
            REP(j,m+1){
                tmp_ans[j] += books_info[i][j];
            }
        }
        // 満たしているなら値段を更新
        for(ll i=1; i<m+1; i++ ){
            if( tmp_ans[i]<x){
                not_manzoku  = true;
            }
        }
        if(! not_manzoku){
            CHMIN(ans,tmp_ans[0]);
        }
        return ;
    }
    // 買うことを選ぶ
    is_selected[level-1] = true;
    bfs( level-1 );
    // 買うことを選ばない
    is_selected[level-1] = false;
    bfs( level-1 );
}

int main(void){
    cin >> n >> m >> x;
    REP(i, n){
        REP(j, m+1){
            ll tmp;
            cin >> tmp;
            books_info[i][j] = tmp;
        }
    }

    // BFS 一つずつ選択するかしないかする。

    bfs(n);

    if(ans == INF){
        cout << "-1" << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}