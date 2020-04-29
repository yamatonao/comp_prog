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

int main(void){
    ll ans =0;
    ll x;
    ll y;
    ll a;
    ll b;
    ll c;
    cin >> x;
    cin >> y;
    cin >> a;
    cin >> b;
    cin >> c;
    vector<ll> red;
    vector<ll> green;
    vector<ll> cl;

    for(ll i=0; i<a; i++){
        ll tmp;
        cin >> tmp;
        red.push_back(tmp);
    }
    for(ll i=0; i<b; i++){
        ll tmp;
        cin >> tmp;
        green.push_back(tmp);
    }
    for(ll i=0; i<c; i++){
        ll tmp;
        cin >> tmp;
        cl.push_back(tmp);
    }
        sort(ALL(red), greater<ll>());
        sort(ALL(green), greater<ll>());
        sort(ALL(cl), greater<ll>());
        vector<ll> xy;
    REP(i, x){
        xy.push_back(red[i]);
    }
    REP(i, y){
        xy.push_back(green[i]);
    }
    REP(i, cl.size()){
        xy.push_back(cl[i]);
    }

    sort(ALL(xy), greater<ll>());
    REP(i, x+y){
        ans += xy[i];
    }

    cout << ans << endl;
    /*
    ll redprog= (red.size())-1;
    ll greenprog= (red.size())-1;
        bool redflag =false;
        bool greenflag = false;
    for(ll i=0; i<cl.size(); i++){
        ll src = cl[i];
        ll tmp1 = red[redprog];
        ll tmp2 = green[greenprog];
        //cout << tmp1 << " " << tmp2 << endl;
        bool target = false;
        if(tmp1 < tmp2){
            target = true;
        }

        if( ( (target) && (redflag == false) ) || greenflag ){
            if(tmp1 < cl[i]){
                red[redprog] = cl[i];
                if(redprog == 0){
                redprog--;
                    redflag = true;
                }
            }
        }else{
            if(tmp2 < cl[i]){
                green[greenprog] = cl[i];
                if(greenprog > 0){
                greenprog--;
                }
            }
        }
    }
        for(ll i=0; i<x; i++){
            ans += red[i];
            //cout << "red" << red[i] << endl;
        }
        for(ll i=0; i<y; i++){
            ans += green[i];
            //cout << "green" << green[i] << endl;
        }
    cout << ans << endl;
        */

    return 0;
}