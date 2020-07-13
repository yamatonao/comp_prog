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

map<ll, ll> used_value;

int main(void){
    ll n;
    cin >> n;
    ll loop_base=0;

    for(ll i=1; i<=n; i++){
        used_value.clear();
        for(ll loopwk=loop_base; loopwk*loopwk<=i;loopwk++){
            loop_base++;
        }

        ll ans =0;
        for(ll ix=1; ix <=loop_base; ix++ ){
            for(ll iy=1; iy <=loop_base; iy++ ){
                ll Bnum = -1*(i-( (ix*ix)+(iy*iy)+(ix*iy)));
                if(Bnum > -1){
                    continue;
                }
                ll Anum = ix+iy;
                ll hanbetu = (Anum*Anum -4*1*Bnum);
                if(hanbetu<0){continue;}
                double tmp1 = sqrt(hanbetu);
                if(ceil(tmp1) != floor(tmp1)){
                    continue;
                }
                ll tmp2 = tmp1;
                if( (Anum + tmp2) % 2 == 1){
                    continue;
                }
                ll iz = (Bnum+tmp2) /2;
                ans ++;
            }
        }

        cout << ans  << endl;
        //cout << ans  << "// " <<i<< endl;
    }
    return 0;
}