//
//  475A.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 12/10/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cstring>


// 475A -
// Method:

namespace {
    using namespace std;
    using ll = long long;
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    using vll = std::vector<ll>;
    
    using ss = std::pair<std::string, std::string>;
    using vss = std::vector<ss>;
    
    const int INF = 1e9;
    const int MAX_COUNT = 1e5;
    const int MOD = 1e9 + 7;
    
    template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
    template<typename T, typename U> inline std::pair<T, U> mpair(T a, U b) { return std::make_pair(a, b); }
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    int n, m;
}

int problem_475A(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> m;
    
    int ans = -1;
    
    if (n >= m) {
        ans = n / 2 + n % 2;
        
        while (true) {
            if (ans % m == 0)
                break;
            ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
