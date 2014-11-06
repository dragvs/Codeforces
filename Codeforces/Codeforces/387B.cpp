//
//  387B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 01/11/14.
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


// 385B -
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
    
//    #define ACTIVE
    
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
    
    const int MAX_COUNT = 3010;
    int a[MAX_COUNT];
    int b[MAX_COUNT];
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    REP(i, n) {
        cin >> a[i];
    }
    REP(i, m) {
        cin >> b[i];
    }
    
    int ans = 0;
    int i = n - 1;
    int j = m - 1;
    
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            --j;
        } else {
            ++ans;
        }
        
        --i;
    }
    if (i >= 0)
        ans += (i + 1);
    
    cout << ans << endl;
    return 0;
}
