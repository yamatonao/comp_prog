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
ll item_grid[3010][3010];
ll dp[3010][3010][4];

int main(void){
	ll r, c, k;
	cin >> r >> c >> k;
	REP(i,k){
		ll tmp_r;
		ll tmp_c;
		ll val;
		cin >> tmp_r >> tmp_c >> val;
		item_grid[tmp_r][tmp_c] = val;
	}

	dp[1][1][0] = 0;
	dp[1][1][1] += item_grid[1][1];

	for(ll now_r = 1; now_r <= r; now_r++){ // Cを全部やったらリセット
	    for(ll now_c = 1; now_c <= c; now_c++){ //Rが変わるとリセットなので、Cをまず全探索する。
			//R方向への繊維
			ll to_r_max =0;
			// 0
			dp[now_r][now_c+1][0] = max(dp[now_r][now_c][0], dp[now_r][now_c+1][0]);
			// 1
			to_r_max = max(dp[now_r][now_c][0]+item_grid[now_r][now_c+1] ,dp[now_r][now_c][1]);
			dp[now_r][now_c+1][1] = max(to_r_max,dp[now_r][now_c+1][1]);
			// 2
			to_r_max = max(dp[now_r][now_c][1]+item_grid[now_r][now_c+1] ,dp[now_r][now_c][2]);
			dp[now_r][now_c+1][2] = max(to_r_max,dp[now_r][now_c+1][2]);
			// 3
			to_r_max = max(dp[now_r][now_c][2]+item_grid[now_r][now_c+1] ,dp[now_r][now_c][3]);
			dp[now_r][now_c+1][3] = max(to_r_max,dp[now_r][now_c+1][3]);

			//C方向への繊維
			ll to_c_max=0;
			to_c_max = max(dp[now_r][now_c][0], dp[now_r][now_c][1]);
            to_c_max = max(to_c_max, dp[now_r][now_c][2]);
            to_c_max = max(to_c_max, dp[now_r][now_c][3]);
			dp[now_r+1][now_c][0] = to_c_max;
			dp[now_r+1][now_c][1] = to_c_max +item_grid[now_r+1][now_c];
		}
	}
    ll  ans = max(dp[r][c][0], dp[r][c][1]);
        ans = max(ans, dp[r][c][2]);
        ans = max(ans, dp[r][c][3]);
        cout << ans <<endl;
	return 0;
}
