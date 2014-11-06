//
//  393B.cpp
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
#include <iomanip>
#include <ios>


// 393B -
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
    
    const int MAX_COUNT = 200;
    int n;
    int w[MAX_COUNT][MAX_COUNT];
    float a[MAX_COUNT][MAX_COUNT];
    float b[MAX_COUNT][MAX_COUNT];
    
    void print(float m[MAX_COUNT][MAX_COUNT]) {
        REP(i, n) {
            REP(j, n) {
                cout << std::fixed << std::setprecision(8) << m[i][j] << " ";
            }
            cout << endl;
        }
    }
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> n;
    REP(i, n) {
        REP(j, n) {
            cin >> w[i][j];
            a[i][j] = 0.0f;
            b[i][j] = 0.0f;
        }
    }
    
//    B31 = (W31 - W13)/2
//    B13 = -B31
//    (A13 = A31) = W13 - B13
    
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                a[i][j] = w[i][j];
                b[i][j] = 0.0f;
                continue;
            }
            float diff = w[j][i] - w[i][j];
            b[j][i] = diff/2;
            b[i][j] = -b[j][i];
            float aTmp = w[i][j] - b[i][j];
            a[i][j] = a[j][i] = aTmp;
        }
    }
    
    print(a);
    print(b);
    return 0;
}
