//
//  490B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 23/11/14.
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


// 490B -
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
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> n;
    vii leftVec;
    vii rightVec;
    
    REP(i, n) {
        int left = 0, right = 0;
        cin >> left >> right;
        leftVec.push_back(mpair(left, right));
        rightVec.push_back(mpair(right, left));
    }
    
    sort(ALL(leftVec));
    sort(ALL(rightVec));
    
    vi ansVec;
    ansVec.resize(n, 0);

    // Mark evens
    auto cur = leftVec[0];
    int idx = 2;
    
    while (idx <= n) {
        ansVec[idx-1] = cur.second;
        
        auto it = lower_bound(ALL(leftVec), mpair(cur.second, 0));
        if (it == leftVec.end() || it->first != cur.second)
            break;
        cur = *it;
        
        idx += 2;
    }
    
    // Evens set odds numbers
    ii evenStart;
    
    REP(i, leftVec.size()) {
        auto pair = leftVec[i];
        if (pair.first == 0)
            continue;
        
        auto it = lower_bound(ALL(rightVec), mpair(pair.first, 0));
        if (it == rightVec.end() || it->first != pair.first) {
            evenStart = pair;
            break;
        }
    }
    
    ansVec[0] = evenStart.first;
    idx = 3;
    cur = evenStart;
    
    while (idx <= n) {
        ansVec[idx-1] = cur.second;
        
        auto it = lower_bound(ALL(leftVec), mpair(cur.second, 0));
        if (it == leftVec.end() || it->first != cur.second)
            break;
        cur = *it;
        
        idx += 2;
    }
    
    REP(i, n) {
        cout << ansVec[i] << " ";
    }
    cout << endl;
    return 0;
}
