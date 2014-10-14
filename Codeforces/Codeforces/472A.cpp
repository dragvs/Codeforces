//
//  472A.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 13/10/14.
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


// 472A - Tasks from math
// Method: Math

namespace {
    using namespace std;
    using ll = long long;
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    using vll = std::vector<ll>;
    
    using ss = std::pair<std::string, std::string>;
    using vss = std::vector<ss>;
    
    const int INF = 1e9;
    const int MAX_COUNT = 1e5;
    const int MOD = 1e9 + 7;
    
    template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
    template<typename T, typename U> inline std::pair<T, U> mpair(T a, U b) { return std::make_pair(a, b); }
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    int n;
}

int problem_472A(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    
    int x = 0, y = 0;
    x = (n % 2 == 0) ? 4 : 9;
    y = n - x;
    std::cout << x << " " << y << std::endl;
    return 0;
}
