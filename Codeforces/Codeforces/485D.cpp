//
//  485D.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 06/11/14.
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


// 485D -
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

// TODO SOLVE!
RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    
    vi vec;
    vec.resize(n, 0);
    REP(i, n) {
        cin >> vec[i];
    }
    sort(ALL(vec), greater<int>());
    
    int ans = -1;
    
    for (int i = 0; i < n; ++i) {
        int curVal = vec[i];
        
        for (int j = 1; j <= curVal; ++j) {
            int tt = curVal/j;
            if (j > 1 && j < curVal)
                ++tt;
            
            if (tt < ans)
                break;
            
            auto it = lower_bound(vec.rbegin(), vec.rend(), tt);
            int lowVal = *it;
            
//            assert(curVal >= lowVal);
            int temp = curVal % lowVal;
            if (temp > ans)
                ans = temp;
        }
    }
    
    ans = max(0, ans);
    cout << ans << endl;
    return 0;
}
