//
//  451B.cpp
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


// 451B -
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
    
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vi aVec;
    aVec.resize(n, 0);
    
    REP(i, n) {
        cin >> aVec[i];
    }
    
    int lIdx = -1, rIdx = -1;
    
    for (int i = 1; i < n; ++i) {
        if (aVec[i] < aVec[i-1]) {
            lIdx = i - 1;
            break;
        }
    }
    for (int i = n-1; i > 0; --i) {
        if (aVec[i] < aVec[i-1]) {
            rIdx = i;
            break;
        }
    }
    
    // -1; -1 - already sorted
    // 0; n-1 - reverse sorted
    if (lIdx == -1 && rIdx == -1) {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
    } else {
        bool possible = true;
        
        if (possible && lIdx > 0 && aVec[rIdx] < aVec[lIdx-1]) {
            possible  = false;
        }
        
        if (possible && rIdx < n-1 && aVec[lIdx] > aVec[rIdx+1]) {
            possible = false;
        }
        
        if (possible) {
            for (int i = lIdx; i < rIdx; ++i) {
                if (aVec[i] < aVec[i+1]) {
                    possible = false;
                    break;
                }
            }
        }
        
        if (possible) {
            cout << "yes" << endl;
            cout << lIdx+1 << " " << rIdx+1 << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
