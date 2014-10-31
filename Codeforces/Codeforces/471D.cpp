//
//  471D.cpp
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


// 471D - MUH and Cube Walls
// Method: Strings\KMP

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
    
    const int MAX_COUNT = 2 * 1e5;

    int n, w;
    int a[2*MAX_COUNT+10];
}

int problem_471D(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> n >> w;
    memset(a, 0, sizeof a);
    int val = 0, prevVal = 0;
    
    if (n == 1 || w == 1) {
        cout << (n/w) << endl;
        return 0;
    }
    
    REP(i, n) {
        cin >> val;
        
        if (i > 0) {
            a[(w - 1) + 1 + (i - 1)] = (val - prevVal);
        }
        prevVal = val;
    }
    REP(i, w) {
        cin >> val;
        
        if (i > 0) {
            a[i - 1] = (val - prevVal);
        }
        prevVal = val;
    }
    a[w - 1] = INF + 999;
    
    // KMP
    int len = (w - 1) + 1 + (n - 1);
    vi pi(len, 0);
    
    for (int i = 1; i < len; ++i) {
        int j = pi[i - 1];
        
        while (j > 0 && a[i] != a[j]) {
            j = pi[j - 1];
        }
        if (a[i] == a[j])
            ++j;
        pi[i] = j;
    }
    
    int ans = 0;
    for (int i = (w - 1) + 1; i < len; ++i) {
        assert(pi[i] <= (w - 1));
        
        if (pi[i] == (w - 1))
            ++ans;
    }
    
    cout << ans << endl;
    return 0;
}
