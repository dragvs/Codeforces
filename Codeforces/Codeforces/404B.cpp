//
//  404B.cpp
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


// 404B -
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
    
    double a, d;
    int n;
    cin >> a >> d >> n;
    
    for (int i = 1; i <= n; ++i) {
        double val = i * d;
        double rem = fmod(val, 4 * a);
        
        double x = 0.0, y = 0.0;
        
        if (rem <= a) {
            x = rem;
            y = 0.0;
        } else if (rem <= 2*a) {
            x = a;
            y = rem - a;
        } else if (rem <= 3*a) {
            x = 3*a - rem;
            y = a;
        } else {
            x = 0.0;
            y = 4 * a - rem;
        }
        
//        cout << std::fixed << std::setprecision(10) << x << " " << y << endl;
        printf("%0.10lf %0.10lf\n", x, y);
    }
    
    return 0;
}
