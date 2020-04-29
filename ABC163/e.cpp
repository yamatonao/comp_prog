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

ll dp[2010][2010];

int main(void){
    ll n;
    ll ans = 0;
    cin >> n;
    vector<pair<ll,ll> > act;
    REP(i, n){
        ll tmp;
        cin >> tmp;
        act.push_back( make_pair(tmp, (i+1)) );
    }

    sort( ALL(act), greater<pair<ll,ll > >() );

    dp[1][0] = (act[0].first) * abs(act[0].second-1);
    dp[0][1] = (act[0].first) * abs(act[0].second-n);

    for(ll i=2; i<=n; i++){
        for(ll y=0; y<=i; y++){
            ll x = i-y;
            if(y==0){
                dp[i][0] = dp[i-1][0] + (act[i-1].first ) * abs( act[i-1].second-i);
            }if(x==0){
                dp[0][i] = dp[0][i-1] + (act[i-1].first) * abs( act[i-1]. second-(n-(i-1)) );
            }else{
                dp[x][y] = max(
                    dp[x-1][y] + (act[i-1].first) * abs( (act[i-1].second-(x) ) ),
                    dp[x][y-1] + (act[i-1].first) * abs( (act[i-1].second-(n-(y-1) ) ) )
                    );
            }
            ans = max(ans,dp[x][y]);
        }
    }
    cout << ans << endl;
/*
    for(ll i=0; i<n+5; i++){
        for(ll j=0; j<n+5; j++){
            printf("%5lld ",dp[j][i]);
        }
        cout << endl;
    }
*/

    return 0;
}