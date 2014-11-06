//
//  445B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 04/11/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <iomanip>
#include <ios>


// 445B -
// Method:

namespace {
    using namespace std;
    using ll = long long;
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    using vll = std::vector<ll>;
    
    const int INF = 1e9;
    //    const int MAX_COUNT = 1e5;
    const int MOD = 1e9 + 7;
    
    template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
    template<typename T, typename U> inline std::pair<T, U> mpair(T a, U b) { return std::make_pair(a, b); }
    
//#define ACTIVE
    
#ifdef ONLINE_JUDGE
#   define RUN_PROBLEM int main(int argc, const char * argv[])
#elif defined(ACTIVE)
#   define RUN_PROBLEM int run(int argc, const char * argv[])
#else
#   define RUN_PROBLEM static int run(int argc, const char * argv[])
#endif
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    int adj_mtx[55][55];
    int n, m;
    
    static const int DFS_WHITE = 0;
    static const int DFS_BLACK = 1;
    int dfs_state[55];
    
    void dfsCC(int v, vi& connVec) {
        dfs_state[v] = DFS_BLACK;
        connVec.push_back(v);
        
        for (int i = 1; i <= n; ++i) {
            if (adj_mtx[v][i] == 1 && dfs_state[i] == DFS_WHITE)
                dfsCC(i, connVec);
        }
    }
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    memset(adj_mtx, 0, sizeof adj_mtx);
    memset(dfs_state, DFS_WHITE, sizeof dfs_state);
    cin >> n >> m;
    
    REP(i, m) {
        int x = 0, y = 0;
        cin >> x >> y;
        
        adj_mtx[x][y] = 1;
        adj_mtx[y][x] = 1;
    }
    
    ll ans = 1;
    
    for (int i = 1; i <= n; ++i) {
        if (dfs_state[i] == DFS_WHITE) {
            vi connVec;
            dfsCC(i, connVec);
            
            if (connVec.size() > 1) {
                REP(tt, connVec.size()-1) {
                    ans *= 2LL;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
