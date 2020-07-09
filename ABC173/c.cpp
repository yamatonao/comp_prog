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

ll ans;
char info[10][10];
ll selected[20];
ll h;
ll w;
ll k;
void dfs(ll level){
    ll blknum=0;;
    if(level == 0){
        // 計算
        REP(hi,h){
            REP(wi,w){
                if(selected[hi] == 1){
                    continue;
                }
                if(selected[wi + h] == 1){
                    continue;
                }
                if(info[hi][wi] == '#'){
                    blknum++;
                }
            }
        }

        if(blknum == k){
            ans++;
        }
        return;
    }

    selected[ (h+w) -level ] = 1;
    dfs(level-1);
    selected[ (h+w) -level ] = 0;
    dfs(level-1);

    return;
}

int main(void){
    cin >> h >> w >> k;
    REP(i, h){
        REP(j,w){
            char tmp;
            cin >> tmp;
            info[i][j] = tmp;
        }
    }
    dfs(h+w);
    cout << ans << endl;
    return 0;
}