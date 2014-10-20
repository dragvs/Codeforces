//
//  478B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 16/10/14.
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


// 478B - Random teams
// Method: Math

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
    
    ll n = 0, m = 0;
}

inline ll pairs(ll n) {
    return n * (n - 1)/2;
}

int problem_478B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> m;
    
    // min
    ll minBaseSize = n/m;
    ll minExtGroupsN = n % m;
    ll minBasePairs = pairs(minBaseSize);
    ll minExtPairs = pairs(minBaseSize + 1);
    ll kMin = minBasePairs * (m - minExtGroupsN) + minExtPairs * minExtGroupsN;
    
    // max
    ll bigComN = n - (m - 1);
    ll kMax = pairs(bigComN);
    
    std::cout << kMin << " " << kMax << std::endl;
    
    return 0;
}
