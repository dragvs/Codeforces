//
//  448B.cpp
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


// 448B -
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
    
    string A;
    string B;
    
    bool checkArray() {
        string aTmp(A);
        string bTmp(B);
        sort(ALL(aTmp));
        sort(ALL(bTmp));
        return aTmp == bTmp;
    }
    
    bool checkAuto() {
        int i = 0, j = 0;
        
        while (i < A.size() && j < B.size()) {
            if (A[i] == B[j]) {
                ++j;
            }
            ++i;
        }
        return j == B.size();
    }
    
    bool checkBoth() {
        string aTmp(A);
        
        REP(i, B.size()) {
            auto it = find(ALL(aTmp), B[i]);
            
            if (it == aTmp.end()) {
                return false;
            } else {
                *it = '_';
            }
        }
        
        return true;
    }
}

RUN_PROBLEM
{
    std::ios_base::sync_with_stdio(false);
    
    cin >> A >> B;
    
    string ans("need tree");

//    array - equal len && same letters
//    automaton - O(n^2) A contains B letters in order
//
//    both - A contains B letters
//
//    else: need tree
    if (checkArray()) {
        ans = "array";
    } else if (checkAuto()) {
        ans = "automaton";
    } else if (checkBoth()) {
        ans = "both";
    }
    cout << ans << endl;
    return 0;
}
