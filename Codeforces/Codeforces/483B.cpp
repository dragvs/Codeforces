//
//  483B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 24/10/14.
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


// 483B - Friends and Presents
// Method: Binary search

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
    
    ll cnt1, cnt2, x, y;
    
    bool contains(ll value) {
        ll xDivs = value / x;
        ll yDivs = value / y;
        ll xyDivs = value / (x * y);
        ll remX = cnt1;
        ll remY = cnt2;
        
        ll xSpec = yDivs - xyDivs;
        ll ySpec = xDivs - xyDivs;
        remX = std::max(0LL, remX - xSpec);
        remY = std::max(0LL, remY - ySpec);
        ll remV = value - xDivs - yDivs + xyDivs;
        return remV >= (remX + remY);
    }
}

int problem_483B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> cnt1 >> cnt2 >> x >> y;
    
    ll min = cnt1;
    ll max = 2 * (cnt1 + cnt2);
//    assert(!contains(min));
//    assert(contains(max));
    
    while ((max - min) > 1) {
        ll avg = (max + min) / 2;
        
        if (contains(avg)) {
            max = avg;
        } else {
            min = avg;
        }
    }
    
    std::cout << max << std::endl;
    return 0;
}
