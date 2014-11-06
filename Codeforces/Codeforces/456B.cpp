//
//  456B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 04/11/14.
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


// 456B -
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
    
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    int len = 0;
    char c;
    int last = 0, preLast = 0;
    
    while (cin >> c) {
        int dig = c - '0';
        ++len;
        
        preLast = last;
        last = dig;
    }
    
    if (len == 1 && last == 0) {
        cout << "4" << endl;
        return 0;
    }
        
    bool isOdd = last % 2 == 1;
    bool is4Div = (preLast * 10 + last) % 4 == 0;
   
    int tmp = 1;
        
    if (isOdd) {
        tmp += 5;
        tmp += 4;
    } else {
        if (is4Div) {
            tmp += 6;
            tmp += 1;
        } else {
            tmp += 4;
            tmp += 9;
        }
        
        tmp += 6;
    }
    
    int ans = tmp % 5;
    cout << ans << endl;
    return 0;
}
