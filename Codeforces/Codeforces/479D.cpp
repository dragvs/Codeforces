//
//  479D.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 22/10/14.
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


// 479D - Long jumps
// Method: Impl, binary search

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
    
    ll n, l, x, y;
    vll a;
    
    bool exists(const vll::iterator& fromIt, ll value) {
        if (value < 0 || value > l)
            return false;
        
        auto iter = std::lower_bound(fromIt, a.end(), value);
        return iter != a.end() && *iter == value;
    }
    
    bool r_exists(const vll::iterator& toIt, ll value) {
        if (value < 0 || value > l)
            return false;
        
        auto iter = std::lower_bound(a.begin(), toIt, value);
        return iter != toIt && *iter == value;
    }
    
    void output(ll value) {
        std::cout << "1" << std::endl;
        std::cout << value << std::endl;
    }
    void output(ll value1, ll value2) {
        std::cout << "2" << std::endl;
        std::cout << value1 << " " << value2 << std::endl;
    }
}

int problem_479D(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> l >> x >> y;
    
    a.resize(n, 0);
    REP(i, n) {
        std::cin >> a[i];
    }
    
    //
    bool xExists = false, yExists = false;
    
    for (auto it = a.begin(); it != a.end(); ++it) {
        xExists = xExists || exists(it, *it+x);
        yExists = yExists || exists(it, *it+y);
        
        if (xExists && yExists)
            break;
    }
    
    if (xExists && yExists) {
        std::cout << "0" << std::endl;
    } else if (xExists) {
        output(y);
    } else if (yExists) {
        output(x);
    }
    if (xExists || yExists)
        return 0;

    for (auto it = a.begin(); it != a.end(); ++it) {
        if ((*it+y <= l && exists(it, *it+y-x)) || exists(it, *it+y+x)) {
            output(*it+y);
            return 0;
        }
        if ((*it-y >= 0 && r_exists(it, *it-y+x)) || r_exists(it, *it-y-x)) {
            output(*it-y);
            return 0;
        }
    }
    
    output(x, y);
    return 0;
}
