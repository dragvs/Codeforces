//
//  463A.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 28/10/14.
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


// 463A - Caisa and Sugar
// Method: Impl

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
    
    int n, s;
}

int problem_463A(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> n >> s;
    int ans = -1;
    
    REP(i, n) {
        int x = 0, y = 0;
        cin >> x >> y;
        
        if (x == s && y == 0) {
            if (0 > ans)
                ans = 0;
        } else if (x < s) {
            int dd = 100 - y;
            
            if (dd == 100) {
                if (0 > ans)
                    ans = 0;
            }
            else if (dd > 0) {
                if (dd > ans)
                    ans = dd;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
