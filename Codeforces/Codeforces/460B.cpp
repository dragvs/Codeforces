//
//  460B.cpp
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


// 460B -
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
    
    ll poww(ll base, ll pow) {
        ll res = 1;
        
        while (pow-- > 0) {
            res *= base;
        }
        return res;
    }
    
    int sumDecDigits(ll val) {
        int sum = 0;
        
        while (val > 0) {
            sum += (val % 10);
            val /= 10;
        }
        return sum;
    }
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    ll a, b, c;
    cin >> a >> b >> c;
    
    vi ansVec;
    
    for (int i = 1; i <= 81; ++i) {
        ll tmp = b * poww(i, a) + c;
        
        if (tmp > 0 && tmp < 1e9) {
            int sum = sumDecDigits(tmp);
            
            if (sum == i) {
                ansVec.push_back((int)tmp);
            }
        }
    }
    std::sort(ALL(ansVec));
    
    cout << ansVec.size() << endl;
    
    REP(i, ansVec.size()) {
        cout << ansVec[i] << " ";
    }
    cout << endl;
    return 0;
}
