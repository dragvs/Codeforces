//
//  463C.cpp
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


// 463C - Cargari and Bishops
// Method: Impl

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
    
    const int MAX_COUNT = 2000;
    int n = 0;
    int a[MAX_COUNT][MAX_COUNT];
    ll diag1[2*MAX_COUNT];
    ll diag2[2*MAX_COUNT];
    
    inline int diag1Idx(int i, int j) {
        return i + j;
    }
    inline int diag2Idx(int i, int j) {
        return n - i - 1 + j;
    }
    
    inline bool isBlack(int i, int j) {
        bool isBlack = false;
        if ((i + 1) % 2 == 1 && (j + 1) % 2 == 1)
            isBlack = true;
        if ((i + 1) % 2 == 0 && (j + 1) % 2 == 0)
            isBlack  = true;
        return isBlack;
    }
}

int problem_463C(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    memset(a, 0, sizeof a);
    memset(diag1, 0, sizeof diag1);
    memset(diag2, 0, sizeof diag2);
    
    cin >> n;
    
    REP(i, n) {
        REP(j, n) {
            cin >> a[i][j];
            
            int d1Idx = diag1Idx(i, j);
            int d2Idx = diag2Idx(i, j);
            diag1[d1Idx] += a[i][j];
            diag2[d2Idx] += a[i][j];
        }
    }
    
    vector<ll> ansV { 0LL, 0LL };
    vii ansPairV { mpair(1, 1), mpair(1, 2) };
    
    REP(i, n) {
        REP(j, n) {
            int d1Idx = diag1Idx(i, j);
            int d2Idx = diag2Idx(i, j);
            ll d1 = diag1[d1Idx];
            ll d2 = diag2[d2Idx];
            ll value = d1 + d2 - a[i][j];
            
            int idx = isBlack(i, j) ? 0 : 1;
            
            if (value > ansV[idx]) {
                ansV[idx] = value;
                ansPairV[idx] = mpair(i + 1, j + 1);
            }
        }
    }
    
    cout << ansV[0] + ansV[1] << endl;
    cout << ansPairV[0].first << " " << ansPairV[0].second <<  " "
         << ansPairV[1].first << " " << ansPairV[1].second << endl;
    return 0;
}
