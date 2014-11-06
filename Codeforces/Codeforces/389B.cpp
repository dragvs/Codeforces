//
//  389B.cpp
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


// 389B -
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
    
    const int MAX_COUNT = 110;
    int n;
    int a[MAX_COUNT][MAX_COUNT];
    
    bool check(int i, int j) {
        return a[i][j] &&
            a[i-1][j] && a[i+1][j] &&
            a[i][j-1] && a[i][j+1];
    }
    
    void reset(int i, int j) {
        a[i][j-1] = 0;
        a[i][j] = 0;
        a[i][j+1] = 0;
        a[i-1][j] = 0;
        a[i+1][j] = 0;
    }
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    memset(a, 0, sizeof a);
    cin >> n;
    int cnt = 0;
    
    REP(i, n) {
        REP(j, n) {
            char c;
            cin >> c;
            
            if (c == '#') {
                a[i][j] = 1;
                ++cnt;
            }
        }
    }
    
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if (check(i, j)) {
                cnt -= 5;
                reset(i, j);
            }
        }
    }
    assert(cnt >= 0);
    cout << (cnt == 0 ? "YES" : "NO") << endl;
    return 0;
}
