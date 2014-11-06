//
//  469B.cpp
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


// 469B -
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
    
    bool intersect(const ii& a, const ii& b) {
        return (a.first >= b.first && a.first <= b.second) ||
                (b.first >= a.first && b.first <= a.second);
    }
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    
    vii pVec, qVec;
    
    REP(i, p) {
        ii interval;
        cin >> interval.first >> interval.second;
        pVec.push_back(interval);
    }
    REP(i, q) {
        ii interval;
        cin >> interval.first >> interval.second;
        qVec.push_back(interval);
    }
    
    int ans = 0;
    
    for (int i = l; i <= r; ++i) {
        bool match = false;
        
        REP(qIdx, q) {
            ii orig = qVec[qIdx];
            ii shift = mpair(orig.first + i, orig.second + i);
            
            REP(pIdx, p) {
                if (intersect(pVec[pIdx], shift)) {
                    match = true;
                    break;
                }
            }
            
            if (match)
                break;
        }
        
        if (match)
            ++ans;
    }
    
    cout << ans << endl;
    return 0;
}
