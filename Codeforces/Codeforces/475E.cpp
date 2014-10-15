//
//  475E.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 13/10/14.
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


// 475E - Dreamoon and strings
// Method: Strings and DP

namespace {
    using namespace std;
    using ll = long long;
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    using vll = std::vector<ll>;
    
    const int INF = 1e9;
    const int MAX_COUNT = 1e5;
    const int MOD = 1e9 + 7;
    
    template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
    template<typename T, typename U> inline std::pair<T, U> mpair(T a, U b) { return std::make_pair(a, b); }
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    char sStr[2100], tStr[600];
    int sSize = 0, tSize = 0;
    
    int A[2100];
    int DP[2100][2100];
    
    int solveTopDown(int idx, int removalLeft) {
//        - At (Idx;R) Take max:
//            - Remove current -> take value from (Idx+1; R-1)
//            - Do not remove current/skip it -> take value from (Idx+1; R)
//            - If possible - Start subseq at current idx -> sum 1 with value at (Idx+Len(p);R-A[Idx])
        if (idx > sSize || (removalLeft > 0 && idx == sSize) || removalLeft < 0)
            return -INF;
        if (idx == sSize)
            return 0;
        
        if (DP[idx][removalLeft] != -1)
            return DP[idx][removalLeft];
        
        int removeRes = solveTopDown(idx+1, removalLeft-1);
        int skipRes = solveTopDown(idx+1, removalLeft);
        int res = std::max(removeRes, skipRes);
        
        if (A[idx] > 0) {
            int delNumber = A[idx] - tSize;
            int startSeqRes = solveTopDown(idx + A[idx], removalLeft - delNumber);
            res = std::max(res, startSeqRes+1);
        }
        DP[idx][removalLeft] = res;
        return res;
    }
}

int problem_475E(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> sStr >> tStr;
    sSize = (int)strlen(sStr);
    tSize = (int)strlen(tStr);
    
    for (int i = 0; i < sSize; ++i) {
        bool possible = true;
        int srcI = i;
        
        for (int j = 0; j < tSize;) {
            if (sStr[srcI] == tStr[j]) {
                ++j;
            }
            ++srcI;
            if (srcI >= sSize && j != tSize) {
                possible = false;
                break;
            }
        }
        A[i] = possible ? srcI-i : -1;
    }
    
    std::fill_n(&DP[0][0], 2100*2100, -1);
    
    for (int k = 0; k <= sSize; ++k) {
        int res = solveTopDown(0, k);
        std::cout << res << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
