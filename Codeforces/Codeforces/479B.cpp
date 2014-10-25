//
//  479B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 20/10/14.
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


// 479A - Towers
// Method: Impl/Greedy

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
    
    const int MAX_COUNT = 100 + 10;
    int n = 0, k = 0;
    vii a;
}

int problem_479B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    vii a;
    std::cin >> n >> k;
    
    REP(i, n) {
        a.push_back(mpair(0, i));
        std::cin >> a.back().first;
    }
    std::sort(ALL(a));

    vii moveVec;
    moveVec.reserve(k);
    int currentK = 0;
    
    auto minIt = std::min_element(ALL(a));
    auto maxIt = std::max_element(ALL(a));
    int diff = maxIt->first - minIt->first;
    
    while (diff > 1 && currentK < k) {
        ++currentK;
        ++minIt->first;
        --maxIt->first;
        moveVec.push_back(mpair(maxIt->second, minIt->second));
        
        minIt = std::min_element(ALL(a));
        maxIt = std::max_element(ALL(a));
        diff = maxIt->first - minIt->first;
    }
    
    std::cout << diff << " " << currentK << std::endl;
    REP(i, moveVec.size()) {
        std::cout << moveVec[i].first+1 << " " << moveVec[i].second+1 << std::endl;
    }
    
    return 0;
}
