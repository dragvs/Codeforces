//
//  486C.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 11/11/14.
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


// 486C -
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
    
#define ACTIVE
    
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
    
    int n, p;
    string str;
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> n >> p;
    cin >> str;
    
    // a - 1, z - 26
    ll switchCnt = 0;
    int leftIdx = -1, rightIdx = -1;
    
    for (int i = 0; i < n/2; ++i) {
        int a = str[i] - 'a';
        int b = str[n - 1 - i] - 'a';
        
        int dist = abs(a - b);
        if (dist > 13)
            dist = 26 - dist;
        switchCnt += dist;
            
        if (dist != 0) {
            if (leftIdx == -1)
                leftIdx = i;
            rightIdx = i;
        }
    }
    
    int pos = p;
    if (pos > n/2) {
        pos = n - p + 1;
    }
    --pos;
    
    ll ans = switchCnt;

    if (leftIdx != -1) {
        int rightSteps = max(rightIdx - pos, 0);
        int leftSteps = max(pos - leftIdx, 0);
        
        ans += min(leftSteps, rightSteps) * 2;
        ans += max(leftSteps, rightSteps);
    }
    
    cout << ans << endl;
    return 0;
}
