//
//  118D.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 15/10/14.
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


// 118D - Caesar legions
// Method: DP

namespace {
    using namespace std;
    using ll = long long;
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    using vll = std::vector<ll>;
    
    const int INF = 1e9;
    const int MAX_COUNT = 1e5;
    const int MOD = 1e8;
    
    template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
    template<typename T, typename U> inline std::pair<T, U> mpair(T a, U b) { return std::make_pair(a, b); }
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    int n1, n2, k1, k2;
    int dpMemo[101][101][11][11];
    
    int solveTopDown(int remN1, int remN2, int seqN1, int seqN2) {
        assert(seqN1 == 0 || seqN2 == 0);
        if (remN1 < 0 || remN2 < 0 || seqN1 > k1 || seqN2 > k2)
            return 0;
        if (remN1 == 0 && remN2 == 0)
            return 1;
        
        int* dpPtr = &dpMemo[remN1][remN2][seqN1][seqN2];
        if (*dpPtr != -1)
            return *dpPtr;
        
        int res = (solveTopDown(remN1-1, remN2, seqN1+1, 0) +
                  solveTopDown(remN1, remN2-1, 0, seqN2+1)) % MOD;
        *dpPtr = res;
        return res;
    }
}

int problem_118D(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n1 >> n2 >> k1 >> k2;
    
    std::fill_n(&dpMemo[0][0][0][0], sizeof(dpMemo)/sizeof(int), -1);
    std::cout << solveTopDown(n1, n2, 0, 0) << std::endl;
    
    return 0;
}
