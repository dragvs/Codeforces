//
//  378B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 31/10/14.
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


// 378B -
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
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    int n;
}

int problem_378B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    vii resVec;
    int a = 0, b = 0;
    
    REP(i, n) {
        cin >> a >> b;
        resVec.push_back(mpair(a, 0));
        resVec.push_back(mpair(b, 1));
    }
    std::sort(ALL(resVec));
    
    int maxA = n/2, maxB = n/2;
    int aIdx = 0, bIdx = 0;
    
    REP(i, n) {
        ii& p = resVec[i];
        
        if (p.second == 0) {
            ++aIdx;
            maxA = max(maxA, aIdx);
        } else if (p.second == 1) {
            ++bIdx;
            maxB = max(maxB, bIdx);
        }
    }
    
    REP(i, n) {
        bool ok = (i + 1) <= maxA;
        cout << (ok ? "1" : "0");
    }
    cout << endl;
    
    REP(i, n) {
        bool ok = (i + 1) <= maxB;
        cout << (ok ? "1" : "0");
    }
    cout << endl;
    return 0;
}
