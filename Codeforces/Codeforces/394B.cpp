//
//  394B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 02/11/14.
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


// 394B -
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
    
    const int MAX_COUNT = 1e6;

    int n, k;
    int a[MAX_COUNT];
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    memset(a, 0, sizeof a);
    cin >> n >> k;
    bool found = false;
    
//    142857
//    int x = 1;
//    int w = 4;

//    while (true) {
//        while (true) {
    for (int x = 1; x < 10; ++x) {
        REP(w, 10) {
            a[0] = x;
            a[n-1] = w;
            int cur = w;
            int rem = 0;
            
            for (int t = n-1; t >= 2; --t) {
                int nxt = (cur * k + rem) % 10;
                rem = (cur * k + rem) / 10;
                
                a[t - 1] = nxt;
                cur = nxt;
            }
            
            int tmpX = (cur * k + rem) % 10;
            rem = (cur * k + rem) / 10;
            
            int tmpW = (a[0] * k + rem) % 10;
            rem = (a[0] * k + rem) / 10;
            
            if (rem == 0 && tmpX == x && tmpW == w) {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    
    if (found) {
        REP(i, n) {
            cout << a[i];
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
