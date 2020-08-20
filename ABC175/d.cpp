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


int main(void){
	ll n, m;
	vector<ll> p, c;
	cin >> n >> m;
	REP(i,n){
		ll tmp;
		cin >> tmp;
		p.push_back(tmp);
		p[i]--;				//この時点で一個ずらしておくと便利。
	}

	REP(i,n){
		ll tmp;
		cin >> tmp;
		c.push_back(tmp);
	}

	// 先にループ値を求めておく。
	// p1～pnが相異なるので可能。
	// 異なっていたらどうしよう…
	vector<ll> sum(n);
	vector<ll> len(n);
	REP(i, n){
		sum[i] = c[i];
		len[i] = 1;
		for(ll j=p[i]; j != i; j=p[j]){
			sum[i] += c[j];
			len[i] ++;
		}
	}

	ll ans = -INF;
	for(ll i=0; i<n; i++){
		ll cur_ans=0;
		if(sum[i] > 0 && (m/len[i]) >1){ // 一周すると増える、かつ一周以上できるなら
			ll q = m / len[i];
			cur_ans += (q-1)* sum[i];
			ll r = m % len[i] + len[i];
			ll opt = -INF;
			ll acc = 0;
			for(ll j = i, k=0; k<r; k++, j=p[j]){
				acc += c[j];
				opt = max(opt, acc);
			}
			cur_ans += opt;
		}else{ // 一周しても増えないなら一周して終わり。
			ll opt = -INF;
			ll acc = 0;
			for(ll j=i, k=0; k< len[i]*2 && k<m; k++, j=p[j]){
				acc += c[j];
				opt = max(opt, acc);
			}
			cur_ans += opt;
		}
		ans = max(ans, cur_ans);
	}
	cout << ans << endl;

	return 0;
}
