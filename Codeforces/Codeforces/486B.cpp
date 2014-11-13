//
//  486B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 11/11/14.
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


// 486B -
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
    
    const int MAX_COUNT = 110;
    int m, n;
    int B[MAX_COUNT][MAX_COUNT];
    int A[MAX_COUNT][MAX_COUNT];
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    memset(B, 0, sizeof B);
    std::fill_n(&A[0][0], sizeof(A)/sizeof(int), 1);
    
    cin >> m >> n;
    REP(i, m) {
        REP(j, n) {
            cin >> B[i][j];
        }
    }
    
    REP(i, m) {
        REP(j, n) {
            if (B[i][j] == 0) {
                REP(k, m) {
                    A[k][j] = 0;
                }
                REP(k, n) {
                    A[i][k] = 0;
                }
            }
        }
    }
    
    bool possible = true;
    
    REP(i, m) {
        REP(j, n) {
            if (B[i][j] == 1) {
                bool foundInRow = false;
                bool foundInCol = false;
                
                REP(k, m) {
                    if (A[k][j] == 1) {
                        foundInCol = true;
                        break;
                    }
                }
                REP(k, n) {
                    if (A[i][k] == 1) {
                        foundInRow = true;
                    }
                }
                if (!(foundInRow || foundInCol)) {
                    possible = false;
                }
            }
        }
        if (!possible)
            break;
    }
    
    cout << (possible ? "YES" : "NO") << endl;
    
    if (possible) {
        REP(i, m) {
            REP(j, n) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
