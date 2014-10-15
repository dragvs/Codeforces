//
//  475D.cpp
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


// 475D - Dreamoon and sets
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
    
    int n, k;
}

int problem_475D(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> k;
    
    std::cout << (n*6-1)*k << std::endl;
    
    REP(i, n) {
        std::cout << (i*6+1)*k << " " << (i*6+2)*k << " " << (i*6+3)*k << " " << (i*6+5)*k << std::endl;
    }
    
    return 0;
}
