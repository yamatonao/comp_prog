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
    multiset<ll> kindergarten[200010];
    //multiset<ll> kindergarten[20];
    multiset<ll> strongest_infants;
    vector<pair<ll, ll> > infants_info;

    ll n;
    ll q;
    cin >> n >> q;
    REP(i,n){
        ll rate;
        ll start_kindergarten;
        cin >> rate >> start_kindergarten;
        infants_info.push_back(make_pair(rate, start_kindergarten));
        kindergarten[start_kindergarten].insert(rate);
    }
    REP(i,200010){
    //REP(i,20){
        if(! kindergarten[i].empty() ){
            strongest_infants.insert( *(--kindergarten[i].end()) );
        }
    }


        cout << " " << endl;

    REP(i,q){
        ll no;
        ll to;
        cin >> no >> to ;

        no--;
        strongest_infants.erase( strongest_infants.find(*(--kindergarten[infants_info[no].second].end())));
        kindergarten[infants_info[no].second].erase( kindergarten[infants_info[no].second].find(infants_info[no].first));
        if(! kindergarten[infants_info[no].second].empty() ){
            strongest_infants.insert(*(--kindergarten[infants_info[no].second].end()) );
        }

        infants_info[no].second = to;
        if(! kindergarten[infants_info[no].second].empty() ){
            const auto &itr = strongest_infants.find( *(--kindergarten[infants_info[no].second].end()) );
            if( itr != strongest_infants.end()){
                strongest_infants.erase( itr );
            }
        }
        kindergarten[infants_info[no].second].insert( infants_info[no].first );
        strongest_infants.insert( *(--kindergarten[infants_info[no].second].end()) );

        cout << *strongest_infants.begin() << endl;
    }


    return 0;
}