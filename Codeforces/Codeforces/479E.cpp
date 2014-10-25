//
//  479E.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 24/10/14.
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


// 479E - Riding the elevator
// Method: DP

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

    const int MAX_COUNT = 5010;
    int n, a, b, k;
    ll dp[2][MAX_COUNT];
    
    ll solve() {
        int prevIdx = 0;
        int curIdx = 1;
        dp[prevIdx][a] = 1;
        
        REP(i, k) {
            for (int j = 2; j <= b; ++j) {
                dp[prevIdx][j] += dp[prevIdx][j-1];
            }
            for (int j = 0; j <= b; ++j) {
                dp[curIdx][j] = 0;
            }
            
            for (int j = 1; j < b; ++j) {
                int minX = 1;
                int halfCeil = (b - j + 1)/2;
                int maxDist = halfCeil - 1;
                int maxX = j + maxDist;

                ll prevFloorsSum = dp[prevIdx][maxX] - dp[prevIdx][minX -1];
                prevFloorsSum -= (dp[prevIdx][j] - dp[prevIdx][j - 1]); // exclude current floor
                dp[curIdx][j] = prevFloorsSum % MOD;
            }
            
            std::swap(prevIdx, curIdx);
        }
        
        ll res = 0;
        
        for (int i = 1; i < b; ++i) {
            if (dp[prevIdx][i] > 0)
                res = (res + dp[prevIdx][i]) % MOD;
        }
        return res;
    }
}

int problem_479E(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> a >> b >> k;
    
    if (a > b) { // invert system
        a = n - a + 1;
        b = n - b + 1;
    }
    
    memset(dp, 0, sizeof dp);
    
    ll res = solve();
    std::cout << res << std::endl;
    
    return 0;
}
