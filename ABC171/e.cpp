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

ll left_array[200010];
ll right_array[200010];
ll input[200010];
ll ans[200010];

int main(void){
    ll n=0;
    cin >> n;
    REP(i, n){
        ll tmp;
        cin >> tmp;
        input[i] = tmp;
    }

    ll tmp_xor=0;
    REP(i,n){
        tmp_xor ^= input[i];
        left_array[i] = tmp_xor;
    }
    tmp_xor = 0;
    REP(i,n){
        tmp_xor ^= input[n-(i+1)];
        right_array[n-(i+1)] = tmp_xor;
    }
    REP(i,n){
        ll tmp=0;
        if(i==0){
            tmp = right_array[1];
        }else if(i == n-1){
            tmp = left_array[i-1];
        }else{
            tmp = left_array[i-1]^right_array[i+1];
        }
        cout << tmp << " ";
    }
    cout << endl;
    return 0;
}