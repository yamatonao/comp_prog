
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
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
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
 #include <codecvt>
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
 
 #if __cplusplus >= 201402L
 #include <shared_mutex>
 #endif
 
 #if __cplusplus >= 201703L
 #include <any>
 #include <charconv>
 // #include <execution>
 #include <filesystem>
 #include <optional>
 #include <memory_resource>
 #include <string_view>
 #include <variant>
 #endif
 
 #if __cplusplus > 201703L
 #include <barrier>
 #include <bit>
 #include <compare>
 #include <concepts>
 #if __cpp_impl_coroutine
 # include <coroutine>
 #endif
 #include <latch>
 #include <numbers>
 #include <ranges>
 #include <span>
 #include <stop_token>
 #include <semaphore>
 #include <source_location>
 #include <syncstream>
 #include <version>
 #endif

using namespace std;
typedef long long int ll;

unsigned char x[2000000];
unsigned char y[2000000];

 int main(void){
     string s;
     ll n;
     bool fliped = false;

     cin >> n;
     cin >> s;

     for(ll i=0; i<n ;i++){
         x[i] = s[i];
     }
     for(ll i=0; i<n ;i++){
         y[i] = s[i+n];
     }
     
    ll q;
    cin >> q;
    for(ll i=0; i<q ;i ++){
        ll t;
            ll a;
            ll b;
        cin >> t;
        cin >> a >> b;
        a--;
        b--;
        if(t == 1){
            unsigned char tmp1;
            unsigned char tmp2;
            if(fliped){

                if( a >= n){
                    tmp1 = x[a-n];
                }else{
                    tmp1 = y[a];
                }

                if( b >= n){
                    tmp2 = x[b-n];
                }else{
                    tmp2 = y[b];
                }

                if( a >= n){
                    x[a-n] = tmp2;
                }else{
                    y[a] = tmp2;
                }

                if( b >= n){
                    x[b-n] = tmp1;
                }else{
                    y[b] = tmp1;
                }


            }else{
                if( a >= n){
                    tmp1 = y[a-n];
                }else{
                    tmp1 = x[a];
                }

                if( b >= n){
                    tmp2 = y[b-n];
                }else{
                    tmp2 = x[b];
                }

                if( a >= n){
                    y[a-n] = tmp2;
                }else{
                    x[a] = tmp2;
                }

                if( b >= n){
                    y[b-n] = tmp1;
                }else{
                    x[b] = tmp1;
                }



            }
        }
        if(t == 2){
            if(fliped){
                fliped = false;
            }else{
                fliped = true;
            }
        }
    }


    if(fliped){
        for(ll i=0; i<n ;i++){
            cout << y[i];
        }
        for(ll i=0; i<n ;i++){
            cout << x[i];
        }

    }else{

        for(ll i=0; i<n ;i++){
            cout << x[i];
        }
        for(ll i=0; i<n ;i++){
            cout << y[i];
        }
    }
     
     cout << endl;
     return 0;
 }