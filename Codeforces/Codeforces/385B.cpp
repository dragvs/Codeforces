//
//  385B.cpp
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


// 385B -
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
    
    std::string str;
    cin >> str;
    
    if (str.size() < 4) {
        cout << 0 << endl;
        return 0;
    }
    
    vi idxVec;
    for (int i = 0; i < str.size()-3; ++i) {
        if (str[i] == 'b' && str[i+1] == 'e' && str[i+2] == 'a' && str[i+3] == 'r')
            idxVec.push_back(i);
    }
    
    ll ans = 0;
    
    // is 'bear' in [i; j]
    for (int i = 0; i < str.size()-3; ++i) {
        bool contains = false;
        
        for (int j = i+3; j < str.size(); ++j) {
            if (!contains) {
                auto it = std::lower_bound(ALL(idxVec), i);
                
                if (it != idxVec.end()) {
                    int idx = *it;
                    int rIdx = idx + 3;
                    
                    contains = rIdx <= j;
                }
            }
            
            if (contains) {
//                cout << (i + 1) << " " << (j + 1) << endl;
                ++ans;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
