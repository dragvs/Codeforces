//
//  401B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 03/11/14.
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


// 401B -
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
    
    int x, k;
    cin >> x >> k;

    vi rVec;
    rVec.push_back(x);
    
    REP(i, k) {
        int type = 0, num1 = 0, num2 = 0;
        cin >> type >> num2;
        rVec.push_back(num2);
        
        if (type == 1) {
            cin >> num1;
            rVec.push_back(num1);
        }
    }
    
    std::sort(ALL(rVec));
    
    int last = 0;
    int ansMin = 0, ansMax = 0;
    
    REP(i, rVec.size()) {
        int cur = rVec[i];
        int diff = cur - last - 1;
        
        if (diff > 0) {
            ansMax += diff;
            ansMin += (diff/2);
            if (diff % 2 > 0) ++ansMin;
        }
        last = cur;
    }
    
    cout << ansMin << " " << ansMax << endl;
    return 0;
}
