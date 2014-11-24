//
//  405B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 14/11/14.
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


// 405B -
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

    int n;
    string str;
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> n >> str;

    int prevLeftIdx = -1;
    int prevRightIdx = -1;
    int ans = 0;
    
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'L') {
            if (prevRightIdx == - 1) {
                // before this idx all fall
            } else {
                int between = i - prevRightIdx - 1;
                if (between % 2 == 1) {
                    ++ans; // one between will stay
                }
            }
            
            prevLeftIdx = i;
        }
        else if (str[i] == 'R') {
            if (prevLeftIdx == -1) {
                // before idx this all will stay
                ans += i;
            } else {
                // between last left and this idx all will stay
                int between = i - prevLeftIdx - 1;
                ans += between;
            }
            
            prevRightIdx = i;
        }
    }
    
    if (prevLeftIdx == -1 && prevRightIdx == -1) {
        ans = (int)str.size();
    }
    else if (prevLeftIdx > prevRightIdx) {
        int last = (int)str.size() - prevLeftIdx - 1;
        ans += last;
    }
    
    cout << ans << endl;
    return 0;
}
