//
//  408B.cpp
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


// 408B -
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
    
    string nStr;
    string mStr;
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> nStr >> mStr;
    
    vi gotCntVec, reqCntVec;
    gotCntVec.resize(26, 0);
    reqCntVec.resize(26, 0);
    
    REP(i, nStr.size()) {
        int idx = nStr[i] - 'a';
        ++gotCntVec[idx];
    }
    REP(i, mStr.size()) {
        int idx = mStr[i] - 'a';
        ++reqCntVec[idx];
    }
    
    int ans = 0;
    
    for (int i = 0; i < 26; ++i) {
        int require = reqCntVec[i];
        int got = gotCntVec[i];
        
        if (require > 0) {
            if (got == 0) {
                ans = -1;
                break;
            } else {
                ans += min(got, require);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
