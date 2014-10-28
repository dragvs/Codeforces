//
//  466B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 27/10/14.
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


// 466B - Magic room
// Method: Impl\Math

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
    
}

int problem_466B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    ll n = 0, a = 0, b = 0;
    cin >> n >> a >> b;

    ll s = n * 6;
    if (a * b >= s) {
        cout << (a * b) << endl;
        cout << a << " " << b << endl;
        return 0;
    }

    ll maxLen = sqrt(s);
    ll minSide = min(a, b), maxSide = max(a, b);
    ll newA = minSide;
    
    pair<ll, ll> ansPair;
    ll ansS = ((ll)INF)*INF;
    
    while (newA <= maxLen) {
        ll newB = s % newA ? (s / newA) + 1 : s / newA;
        ll newS = newA * newB;
        
        if (newB >= maxSide && newS < ansS) {
            ansS = newS;
            ansPair = mpair(newA, newB);
        }
        
        ++newA;
    }
    
    if (b < a)
        swap(ansPair.first, ansPair.second);
    
    cout << ansS << endl;
    cout << ansPair.first << " " << ansPair.second << endl;
    return 0;
}
