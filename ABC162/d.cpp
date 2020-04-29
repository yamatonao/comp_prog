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
    ll n;
    ll ans =0;
    string s;
    cin >> n;
    cin >> s;
    vector<ll> rpos;
    vector<ll> gpos;
    vector<ll> bpos;

    for(ll i=0; i<n; i++){
        if(s[i] == 'R'){
            rpos.push_back(i);
        }else if(s[i] == 'G'){
            gpos.push_back(i);
        }else{
            bpos.push_back(i);
        }
    }

/////// phase FOR
    for(ll i=0; i<(n-2); i++){
/////// phase R
        if(s[i] == 'R'){
            for(ll j=(i+1);j<(n-1); j++){
                vector<ll>::iterator tmp;
                bool same_distance = false;
                if(s[j] == 'G'){
                    tmp = upper_bound(ALL(bpos), j);
                    same_distance = binary_search(ALL(bpos), j+(j-i));
                    if( (bpos.end()-tmp) == 0){continue;}
                    if(same_distance){
                        ans += (bpos.end() - tmp)-1;
                    }else{
                        ans += (bpos.end() - tmp);
                    }
                }
                if(s[j] == 'B'){
                    tmp = upper_bound(ALL(gpos), j);
                    same_distance = binary_search(ALL(gpos), j+(j-i));
                    if( (gpos.end()-tmp) == 0){continue;}
                    if(same_distance){
                        ans += (gpos.end() - tmp)-1;
                    }else{
                        ans += (gpos.end() - tmp);
                    }

                }
            }
        }
/////// phase G
        if(s[i] == 'G'){
            for(ll j=(i+1);j<(n-1); j++){
                vector<ll>::iterator tmp;
                bool same_distance = false;
                if(s[j] == 'R'){
                    tmp = upper_bound(ALL(bpos), j);
                    same_distance = binary_search(ALL(bpos), j+(j-i));
                    if( (bpos.end()-tmp) == 0){continue;}
                    if(same_distance){
                        ans += (bpos.end() - tmp)-1;
                    }else{
                        ans += (bpos.end() - tmp);
                    }
                }
                if(s[j] == 'B'){
                    tmp = upper_bound(ALL(rpos), j);
                    same_distance = binary_search(ALL(rpos), j+(j-i));
                    if( (rpos.end()-tmp) == 0){continue;}
                    if(same_distance){
                        ans += (rpos.end() - tmp)-1;
                    }else{
                        ans += (rpos.end() - tmp);
                    }
                }
            }
        }

/////// phase B
        if(s[i] == 'B'){
            for(ll j=(i+1);j<(n-1); j++){
                vector<ll>::iterator tmp;
                bool same_distance = false;
                if(s[j] == 'G'){
                    tmp = upper_bound(ALL(rpos), j);
                    same_distance = binary_search(ALL(rpos), j+(j-i));
                    if( (rpos.end()-tmp) == 0){continue;}
                    if(same_distance){
                        ans += (rpos.end() - tmp)-1;
                    }else{
                        ans += (rpos.end() - tmp);
                    }
                }
                if(s[j] == 'R'){
                    tmp = upper_bound(ALL(gpos), j);
                    same_distance = binary_search(ALL(gpos), j+(j-i));
                    if( (gpos.end()-tmp) == 0){continue;}
                    if(same_distance){
                        ans += (gpos.end() - tmp)-1;
                    }else{
                        ans += (gpos.end() - tmp);
                    }
                }
            }
        }
    }
/////// phase FOR
    cout << ans << endl;
    return 0;
}