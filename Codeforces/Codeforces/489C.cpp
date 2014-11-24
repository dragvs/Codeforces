//
//  489C.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 17/11/14.
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


// 489C -
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

    int len, sum;
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> len >> sum;
    
    bool possible = true;
    vi min;
    vi max;
    min.resize(len, 0);
    max.resize(len, 0);
    
    if (sum == 0 && len > 1) {
        cout << "-1 -1" << endl;
        return 0;
    }
    
    int rem = sum;
    int lastDig = 0;
    
    for (int i = 0; i < len; ++i) {
        if (rem == 0) {
            if (i == len - 1) {
                min[i] = lastDig;
            } else {
                min[i] = 0;
            }
        } else if (rem < 10 && rem != 0) {
            if (i == len - 1) {
                min[i] = rem;
            } else {
                lastDig = 1;
                min[i] = rem - 1;
            }
            rem = 0;
        } else {
            int dig = 9;
            rem -= dig;
            min[i] = dig;
        }
    }
    
    if (rem != 0)
        possible = false;
        
    if (possible) {
        rem = sum;
        
        for (int i = 0; i < len; ++i) {
            if (rem < 10) {
                max[i] = rem;
                rem = 0;
                break;
            } else {
                int dig = 9;
                rem -= dig;
                max[i] = dig;
            }
        }
        
        if (rem != 0)
            possible = false;
    }
    
    if (possible) {
        reverse(ALL(min));
        
        REP(i, len) {
            cout << min[i];
        }
        cout << " ";
        REP(i, len) {
            cout << max[i];
        }
    } else {
        cout << "-1 -1";
    }
    cout << endl;
    return 0;
}
