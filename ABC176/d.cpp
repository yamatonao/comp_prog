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

//h w

char field[1010][1010];
ll cost[1010][1010];
bool visited[1010][1010];

int main(void){
    typedef tuple<ll, ll, ll > P; // shortest cost / field

    ll ans = 0;
    ll h;
    ll w;
    ll start_h, start_w;
    ll goal_h, goal_w;
    cin >> h;
    cin >> w;
    cin >> start_h >> start_w;
    cin >> goal_h >> goal_w;

    priority_queue<P, vector<P>,  greater< P > > pque;

    //一個ずらす
    start_h--;
    start_w--;
    goal_h--;
    goal_w--;

    REP(i, h){
        REP(j, w){
            cost[i][j]=INF;
        }
    }
    cost[start_h][start_w]=0;

    REP(i, h){
        REP(j, w){
            char tmp;
            cin >> tmp;
            field[i][j] = tmp;
        }
    }

    //pque.push( {cost[start_h][start_w], cost[start_h][start_w], start_h, start_w} );
    pque.push({ cost[start_h][start_w], start_h, start_w });

    while(!pque.empty()){
        P p_tmp = pque.top();
        pque.pop();
        ll now_h = get<1>(p_tmp);
        ll now_w = get<2>(p_tmp);
        ll now_cost = get<0>(p_tmp);

        if(cost[now_h][now_w] < now_cost ){continue;}
        if(visited[now_h][now_w]){continue;}else{visited[now_h][now_w] = 1;}

        //今の配置のコスト更新
        cost[now_h][now_w] = now_cost;

        if( ! ((now_h-1)<0) && (field[now_h-1][now_w]!='#' ) ){pque.push({ now_cost, now_h-1, now_w   });}
        if( ! ((now_w-1)<0) && (field[now_h][now_w-1]!='#' ) ){pque.push({ now_cost, now_h,   now_w-1 });}
        if( ! ((now_h+1)>=h) && (field[now_h+1][now_w]!='#' )){pque.push({ now_cost, now_h+1, now_w   });}
        if( ! ((now_w+1)>=w) && (field[now_h][now_w+1]!='#' ) ){pque.push({ now_cost, now_h,   now_w+1 });}

        if( ! ((now_h-2)<0) && !((now_w-2)<0) && (field[now_h-2][now_w-2]!='#' )){pque.push({ now_cost+1, now_h-2, now_w-2 });}
        if( ! ((now_h-2)<0) && !((now_w-1)<0) && (field[now_h-2][now_w-1]!='#' )){pque.push({ now_cost+1, now_h-2, now_w-1 });}
        if( ! ((now_h-2)<0) && !((now_w-0)<0) && (field[now_h-2][now_w-0]!='#' )){pque.push({ now_cost+1, now_h-2, now_w-0 });}
        if( ! ((now_h-2)<0) && !((now_w+1)>=w) && (field[now_h-2][now_w+1]!='#' )){pque.push({ now_cost+1, now_h-2, now_w+1 });}
        if( ! ((now_h-2)<0) && !((now_w+2)>=w) && (field[now_h-2][now_w+2]!='#' )){pque.push({ now_cost+1, now_h-2, now_w+2 });}

        if( ! ((now_h-1)<0) && !((now_w-2)<0) && (field[now_h-1][now_w-2]!='#' )){pque.push({ now_cost+1, now_h-1, now_w-2 });}
        if( ! ((now_h-2)<0) && !((now_w-1)<0) && (field[now_h-1][now_w-1]!='#' )){pque.push({ now_cost+1, now_h-1, now_w-1 });}
        if( ! ((now_h-2)<0) && !((now_w-0)<0) && (field[now_h-1][now_w-0]!='#' )){pque.push({ now_cost+1, now_h-1, now_w-0 });}
        if( ! ((now_h-2)<0) && !((now_w+1)>=w) && (field[now_h-1][now_w+1]!='#' )){pque.push({ now_cost+1, now_h-1, now_w+1 });}
        if( ! ((now_h-2)<0) && !((now_w+2)>=w) && (field[now_h-1][now_w+2]!='#' )){pque.push({ now_cost+1, now_h-1, now_w+2 });}


        if( ! ((now_h-0)<0) && !((now_w-2)<0) && (field[now_h-0][now_w-2]!='#' )){pque.push({ now_cost+1, now_h-0, now_w-2 });}
        if( ! ((now_h-0)<0) && !((now_w-1)<0) && (field[now_h-0][now_w-1]!='#' )){pque.push({ now_cost+1, now_h-0, now_w-1 });}
        //if( ! ((now_h-0)<0) && !((now_w-0)<0) ){pque.push({ now_cost+1, now_h-0, now_w-0 });}
        if( ! ((now_h-0)<0) && !((now_w+1)>=w) && (field[now_h-0][now_w+1]!='#' )){pque.push({ now_cost+1, now_h-0, now_w+1 });}
        if( ! ((now_h-0)<0) && !((now_w+2)>=w) && (field[now_h-0][now_w+2]!='#' )){pque.push({ now_cost+1, now_h-0, now_w+2 });}


        if( ! ((now_h+1)>=h) && !((now_w-2)<0) && (field[now_h+1][now_w-2]!='#' )){pque.push({ now_cost+1, now_h+1, now_w-2 });}
        if( ! ((now_h+1)>=h) && !((now_w-1)<0) && (field[now_h+1][now_w-1]!='#' )){pque.push({ now_cost+1, now_h+1, now_w-1 });}
        if( ! ((now_h+1)>=h) && !((now_w-0)<0) && (field[now_h+1][now_w-0]!='#' )){pque.push({ now_cost+1, now_h+1, now_w-0 });}
        if( ! ((now_h+1)>=h) && !((now_w+1)>=w) && (field[now_h+1][now_w+1]!='#' )){pque.push({ now_cost+1, now_h+1, now_w+1 });}
        if( ! ((now_h+1)>=h) && !((now_w+2)>=w) && (field[now_h+1][now_w+2]!='#' )){pque.push({ now_cost+1, now_h+1, now_w+2 });}

        if( ! ((now_h+2)>=h) && !((now_w-2)<0) && (field[now_h+2][now_w-2]!='#' )){pque.push({ now_cost+1, now_h+2, now_w-2 });}
        if( ! ((now_h+2)>=h) && !((now_w-1)<0) && (field[now_h+2][now_w-1]!='#' )){pque.push({ now_cost+1, now_h+2, now_w-1 });}
        if( ! ((now_h+2)>=h) && !((now_w-0)<0) && (field[now_h+2][now_w-0]!='#' )){pque.push({ now_cost+1, now_h+2, now_w-0 });}
        if( ! ((now_h+2)>=h) && !((now_w+1)>=w) && (field[now_h+2][now_w+1]!='#' )){pque.push({ now_cost+1, now_h+2, now_w+1 });}
        if( ! ((now_h+2)>=h) && !((now_w+2)>=w) && (field[now_h+2][now_w+2]!='#' )){pque.push({ now_cost+1, now_h+2, now_w+2 });}

    }

    if(cost[goal_h][goal_w] == INF){
        cout << -1 << endl;
    }else{
        cout << cost[goal_h][goal_w] << endl;
    }
    return 0;
}

/*
    vector<vector< ToEdge > > graph(v);    // 要注目 (n)はベクターの要素数
    priority_queue<P, vector<P>, greater<P> > pque;

    pque.push( make_pair(all_cost[r],r) );

    while(!pque.empty()){
        P p_tmp = pque.top();
        pque.pop();

        ll now_node = p_tmp.second;

        if(all_cost[now_node] < p_tmp.first){continue;}

        for(ll i=0; i<graph[now_node].size(); i++){
            ToEdge next_edge = graph[now_node][i];
            if( all_cost[next_edge.first] > (all_cost[now_node]+ next_edge.second) ){
                all_cost[next_edge.first] = (all_cost[now_node]+ next_edge.second);
                                        // 次の頂点までの最短コスト    次の頂点
                pque.push(make_pair( all_cost[next_edge.first], next_edge.first));
            }
        }
    }


    REP(i,v){
        if( all_cost[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << all_cost[i] << endl;
        }
    }
    */
