//
//  381B.cpp
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


// 381B -
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
    
    int m;
    int cnt[5000+10];
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> m;
    
    int k = 0;
    int maxK = 0, ans = 0;
    memset(cnt, 0, sizeof cnt);
    
    REP(i, m) {
        cin >> k;
        maxK = max(maxK, k);
        ++cnt[k];
        
        if (cnt[k] <= 2)
            ++ans;
    }
    
    if (cnt[maxK] > 1)
        --ans;
    
    cout << ans << endl;
    
    for (int i = 1; i <= maxK; ++i) {
        if (cnt[i] > 0)
            cout << i << " ";
    }
    cnt[maxK] = 0;
    for (int i = maxK; i > 0; --i) {
        if (cnt[i] > 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}
