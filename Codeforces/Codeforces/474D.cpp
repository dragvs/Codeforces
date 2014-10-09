//
//  474D.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 06/10/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cstring>


// 474D - Surok & flowers
// Method: DP, top-down, cumulative sum

namespace {
    using namespace std;
    using ll = long long;
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    using vll = std::vector<ll>;
    
    using ss = std::pair<std::string, std::string>;
    using vss = std::vector<ss>;
    
    const int INF = 1e9;
    const int MAX_COUNT = 1e5;
    const int MOD = 1e9 + 7;
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
//    naive: 2^N combinations, O(N) per combination?
//
//    dpState(idx) -> count     | total states = N, O(1) per state
//
//    dpState(0)    = 1
//    dpState(<0)   = 0f
//    dpState(idx)	= dpState(idx+1) + dpState(idx+wLen)
    
    const int MaxIdx = MAX_COUNT + 1000;

    int wLen = 0;
    ll cumSum[MaxIdx];
    int lastSum = 0;
    
    ll memo[MaxIdx];
    
    ll getVarNumber(int idx) {
        if (idx == 0) {
            return 1;
        } else if (idx < 0) {
            return 0;
        }
        
        ll* memoPtr = &memo[idx];
        if (*memoPtr != -1)
            return *memoPtr;
        
        ll res = getVarNumber(idx-1);
        res = (res + getVarNumber(idx-wLen)) % MOD;
        return *memoPtr = res;
    }
}

int problem_474D(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    int testN = 0;
    std::cin >> testN >> wLen;
    
    memset(memo, -1, sizeof memo);
    memset(cumSum, -1, sizeof cumSum);
    cumSum[lastSum] = 0;
    
    REP(i, testN) {
        int minA = 0, maxB = 0;
        std::cin >> minA >> maxB;
        
        if (lastSum < maxB) {
            ll sum = cumSum[lastSum];
            
            FOR(j, lastSum+1, maxB+1) {
                ll varN = getVarNumber(j);
                sum = (sum + varN) % MOD;
                cumSum[j] = sum;
            }
            lastSum = maxB;
        }
        
        ll ans = cumSum[maxB] - cumSum[minA-1];
        if (ans < 0)
            ans += MOD;
        std::cout << ans << std::endl;
    }
    return 0;
}
