//
//  463D.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 29/10/14.
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


// 463D - Cargari and Permutations
// Method: DP\Graphs

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
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    const int MAX_COUNT = 1000;
    int n, k;
    int pos[5][MAX_COUNT+1];
    
    using t_adj_list = vector<vii>;
    t_adj_list adjList;
    
    int depth[MAX_COUNT+10];
    
    int dfs(int v) {
        if (depth[v])
            return depth[v];
        
        int curD = 1;
        
        for (int i = 0; i < adjList[v].size(); ++i) {
            ii adj = adjList[v][i];
            curD = std::max(curD, dfs(adj.first) + 1);
        }
        depth[v] = curD;
        return curD;
    }
}

int problem_463D(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);

    fill_n(&pos[0][0], sizeof(pos)/sizeof(int), INF);
    cin >> n >> k;
    
    REP(i, k) {
        REP(j, n) {
            int val = 0;
            cin >> val;
            pos[i][val] = j;
        }
    }
    
    adjList.resize(n+1, vii{});
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j)
                continue;
            
            int cnt = 0;
            
            REP(seq, k) {
                int iPos = pos[seq][i];
                int jPos = pos[seq][j];
                
                if (iPos == INF || jPos == INF)
                    continue;
                
                if (iPos < jPos) {
                    ++cnt;
//                    printf("[SEQ %d] %d -> %d\n", seq, i, j);
                }
            }
            
            if (cnt == k) {
//                printf("[ALL SEQ] %d -> %d\n", i, j);
                adjList[i].push_back(mpair(j, 1));
            }
        }
    }
    
    int ans = 0;
    memset(depth, 0, sizeof depth);
    
    for (int i = 1; i <= n; ++i) {
        int tmpD = dfs(i);
        ans = std::max(ans, tmpD);
    }
    
    cout << ans << endl;
    return 0;
}
