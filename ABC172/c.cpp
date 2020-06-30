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
    ll n;
    ll m;
    ll k;
    vector<ll> a;
    vector<ll> b;
    vector<pair<ll, ll > > a_total;
    vector<pair<ll, ll > > b_total;
    cin >> n >> m >> k;
    REP(i,n){
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    REP(i,m){
        ll tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    ll ans =0;
    ll a_use=0;
    ll b_use=0;
    ll ia=0;
        while(1){
            if( ia >= a.size()){
                break;
            }else{
                a_use+=a[ia];
                a_total.push_back({a_use, ia});
                ia++;
            }
        }

            ll j=0;
        while(1){
            if( j >= b.size()){
                break;
            }else{
                b_use+=b[j];
                b_total.push_back({b_use, j+1});
                j++;
            }
        }
        /*
    REP(i,k+1){
        ll a_max =i;
        ll b_max =k-i;
        ll a_ans =0;
        ll b_ans =0;
        const auto &a_itr = lower_bound(ALL(a_total), make_pair(a_max+1,0LL));
        const auto &b_itr = lower_bound(ALL(b_total), make_pair(b_max+1,0LL));

        if(a_itr == end(a_total)){
            a_ans = n;
        }else{
            a_ans = (*a_itr).second;
        }

        if(b_itr == end(b_total)){
            b_ans = m;
        }else{
            b_ans = (*b_itr).second;
        }

        ll tmp_ans = a_ans + b_ans;
        CHMAX(ans,tmp_ans);
    }
    */
    REP(i,n+1){
        if(i <n){
            ll b_ans = 0;
            ll b_max = k-a_total[i].first;
            if(b_max <0){
                continue;
            }
            auto b_itr = upper_bound(ALL(b_total), make_pair(b_max,INF));
            if(b_itr == end(b_total)){
                b_ans = m;
            }else if(b_itr == begin(b_total)){
                b_ans = 0;
            }else{
                //b_ans = (*(--b_itr)).second;
                b_ans = ll(b_itr-begin(b_total));
            }
            ll tmp_ans = i+1 + b_ans;
            CHMAX(ans,tmp_ans);
        }else{
            ll b_max = k;
            ll b_ans = 0;
            auto b_itr = upper_bound(ALL(b_total), make_pair(b_max,INF));
            if(b_itr == end(b_total)){
                b_ans = m;
            }else if(b_itr == begin(b_total)){
                b_ans = 0;
            }else{
                b_ans = (*(--b_itr)).second;
            }
            CHMAX(ans,b_ans);
        }
    }
    cout << ans << endl;
    return 0;
}