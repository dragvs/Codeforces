//
//  488B.cpp
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


// 488B -
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
    
    void printAns(bool possible, const std::vector<int>& ansVec) {
        if (possible) {
            cout << "YES" << endl;
            
            REP(i, ansVec.size()) {
                cout << ansVec[i] << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    
    bool check(vi& vec) {
        assert(vec.size() == 4);
        sort(ALL(vec));
        
        double sum = vec[0] + vec[1] + vec[2] + vec[3];
        double medD = vec[1] + vec[2];
        
        double avg = sum / 4;
        double med = medD / 2;
        double interval = vec[3] - vec[0];
        
        return (abs(avg - med) < 0.000001 && abs(interval - med) < 0.000001);
    }
    
    int n;
    int a[4];
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    memset(a, 0, sizeof a);
    cin >> n;
    
    REP(i, n) {
        cin >> a[i];
    }
    
    vi vec;
    vec.resize(4, 0);
    
    if (n == 0) {
        printAns(true, { 1, 1, 3, 3 });
    } else if (n == 1) {
//        x1 = x4 / 3
//        x2 = (4*x4 - 3*x3) / 3
        int x1 = a[0];
        int x4 = 3*x1;
        int eq = x4 - x1;
        int x2 = eq;
        int x3 = eq;
        
        printAns(true, {x2, x3, x4});
    } else if (n == 2) {
//        x1 = x4 / 3
//        x2 = 4*x1 - x3
        int x1 = min(a[0], a[1]);
        int x2 = max(a[0], a[1]);
        
        if (x1*3 == x2) {
            // 1 ? ? 2
            int x4 = x1*3;
            int eq = x4 - x1;
            x2 = eq;
            int x3 = eq;
            printAns(true, { x2, x3 });
            return 0;
        } else {
            if (x1*3 > x2) {
                // 1 2 ? ?
                // 1 ? 2 ?
                // ? 1 2 ? _
                // ? 1 ? 2 _
                // ? ? 1 2 _ _
                int x4 = x1*3;
                int eq = x4 - x1;
                int x3 = 2*eq - x2;
                printAns(true, { x3, x4 });
                return 0;
            }
        }
        printAns(false, {});
    } else if (n == 3) {
        vi tmp = { a[0], a[1], a[2], 0 };
        
        for (int i = 1; i <= 1000000; ++i) {
            vec = tmp;
            vec[3] = i;
            
            if (check(vec)) {
                printAns(true, {i});
                return 0;
            }
        }
        printAns(false, {});
    } else if (n == 4) {
        vec = { a[0], a[1], a[2], a[3] };
        printAns(check(vec), {});
    }
    
    return 0;
}
