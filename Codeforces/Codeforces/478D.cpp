//
//  478D.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 17/10/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>


// 478D - Red-green towers
// Method: bottom-up DP

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
    
    int r = 0, g = 0;
    const int LimitH = 900;
    
    const int MAX_COUNT = 2*1e5 + 100;
    int dp[2][MAX_COUNT];
    
    ll getVars(int H) {
        int prevIdx = 0, curIdx = 1;
        if (g > 0) dp[prevIdx][0] = 1; // 1 green used initially
        if (r > 0) dp[prevIdx][1] = 1; // 1 red used initially

        for (int i = 2, blocksN = 3; i <= H; ++i, blocksN += i) {
            int lineW = i;
            bool built = false;

            for (int j = MAX_COUNT-1; j >= 0; --j) {
                dp[curIdx][j] = 0;
                
                if (dp[prevIdx][j] > 0) {
                    // trying to add red line
                    int redLeft = r - (j + lineW);
                    if (redLeft >= 0) {
                        dp[curIdx][(j + lineW)] = (dp[curIdx][(j + lineW)] + dp[prevIdx][j]) % MOD;
                        built = true;
                    }
                    
                    // trying to add green line
                    int greenUsed = (blocksN - lineW) - j;
                    int greenLeft = g - (greenUsed + lineW);
                    if (greenLeft >= 0) {
                        dp[curIdx][j] = (dp[curIdx][j] + dp[prevIdx][j]) % MOD;
                        built = true;
                    }
                }
            }
            if (!built)
                break;
            std::swap(prevIdx, curIdx);
        }
        
        // check prev idx
        ll res = 0;
        
        REP(i, MAX_COUNT) {
            if (dp[prevIdx][i] > 0)
                res = (res + dp[prevIdx][i]) % MOD;
        }
        return res;
    }
}

int problem_478D(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> r >> g;
    
    memset(dp, 0, sizeof dp);
    ll vars = getVars(LimitH);
    
    std::cout << vars << std::endl;
    return 0;
}
