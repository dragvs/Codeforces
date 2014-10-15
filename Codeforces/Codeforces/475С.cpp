//
//  475С.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 14/10/14.
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


// 475C - Dreamoon and sums
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
    
    ll a, b;
}

int problem_475C(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> a >> b;
    
    ll left = (a * (a + 1)/2) % MOD;
    left = (left * b) % MOD;
    left = (left + a) % MOD;
    ll right = (b * (b - 1)/2) % MOD;
    ll res = (left * right) % MOD;
    std::cout << res << std::endl;
    
    return 0;
}
