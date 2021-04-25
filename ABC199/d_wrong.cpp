
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

bool is_visited[100];
ll used_color[100];
#define RED 0x01
#define BLUE 0x02
#define GREEN 0x04

ll ans=1;

 int main(void){
    ll n;
    ll m;
    cin >> n;
    cin >> m;
    vector<vector <ll>> graph(n);

    for(ll i=0; i< m; i++){
        ll a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    for(ll i=0; i<n ; i++){ // 始点設定
        queue<pair< ll, ll>> next;
        ll length = 1;
        ll pos = i;
        if(is_visited[pos] ){
            continue;
        }
        is_visited[pos] =true; // 仮に赤使用とする
        used_color[pos] |=RED; // 仮に赤使用とする

        for( ll j =0; j< graph[i].size(); j++){
            next.push(pair(graph.at(i).at(j), used_color[pos]));
        }

        while( next.size()!= 0){
            pair <ll, ll> p_tmp;
            p_tmp = next.front();
            pos = p_tmp.first;
             next.pop();
            ll moto_color = p_tmp.second;
            ll pos_color = used_color[pos];
            if( is_visited[p_tmp.first]  ){
                continue; // 訪問済み
            }
            length++;
            is_visited[pos] = true;

            // 周り見て自分の色を決める
            ll forbid_color = 0;
            // 周りを見る
            for(ll k=0; k< graph[pos].size(); k++){
                ll look_color = graph.at(pos).at(k);
                forbid_color |= used_color[look_color];
            }
            //すべてNGならもうダメです。
            if(forbid_color == (RED | BLUE | GREEN) ){
                ans = 0;
                break;
            }

            if(forbid_color ==RED|| forbid_color ==(GREEN|BLUE)){
                used_color[pos] = BLUE;
            }else if(forbid_color ==BLUE || forbid_color ==(RED|BLUE)) {
                used_color[pos] = GREEN;
            }else if(forbid_color ==GREEN || forbid_color ==(GREEN|BLUE) ) {
                used_color[pos] = RED;
            }else{
                used_color[pos] = BLUE;
            }

            //次をくべる
            for( ll k =0; k< graph[i].size(); k++){
                next.push(pair(graph.at(pos).at(k), used_color[pos]));
            }
        }

        if(length == 1){
            ans *= 3;
        }else{
            ans *= 6;

        }
        if(ans == 0){
            break;
        }

    }
    cout << ans <<endl;
    return 0;
 }