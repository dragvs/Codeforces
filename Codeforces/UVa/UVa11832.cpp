//
//  UVa11832.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 06/10/14.
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


// 11832 - Acoount Book
// Method: DP, top-down knapsack 0-1

namespace {
    using namespace std;
    using ll = long long;
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    using vll = std::vector<ll>;
    
    using ss = std::pair<std::string, std::string>;
    using vss = std::vector<ss>;
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    
//    naive: 2^N combinations, O(N) per combination?
//
//    dpState(trans, subTotal) -> is possible | total states = N*|F|, O(1) per state
//
//    dpState(N, subTotal) 	= subTotal == cashFlow
//    dpState(i, subTotal)	= dpState(trans+1, subTotal-T[i]) || dpState(trans+1, subTotal+T[i])
    
    vi transVec;
    int totalFlow = 0;
    std::vector<int> resVec;
    
    const int MaxN = 50;
    const int MaxF = 40000;
    int memo[MaxN][MaxF];
    
    char descibeState(int state) {
        switch (state) {
            case 1:
                return '-';
            case 2:
                return '+';
            case 3:
                return '?';
            default:
                return '*';
        }
    }
    
    int updateState(int state, bool minusRes, bool plusRes) {
        if (minusRes) {
            state |= 1;
        }
        if (plusRes) {
            state |= (1 << 1);
        }
        return state;
    }
    
    bool isPossible(int n, int subflow) {
        if (n >= transVec.size()) {
            return subflow == totalFlow;
        }
        
        int* memoPtr = &memo[n][20000+subflow];
        if (*memoPtr != -1)
            return *memoPtr == 0 ? false : true;
        
        bool minusRes = isPossible(n+1, subflow - transVec[n]);
        bool plusRes = isPossible(n+1, subflow + transVec[n]);
        bool possible = minusRes||plusRes;
        
        if (possible)
            resVec[n] = updateState(resVec[n], minusRes, plusRes);
        
        *memoPtr = possible ? 1 : 0;
        return possible;
    }
    
    std::string decodeTrans() {
        bool minusRes = isPossible(1, 0-transVec[0]);
        bool plusRes = isPossible(1, 0+transVec[0]);
        resVec[0] = updateState(0, minusRes, plusRes);
        
        std::string decoded;
        
        REP(i, transVec.size()) {
            if (!resVec[i])
                return "*";
                
            decoded += descibeState(resVec[i]);
        }
        return decoded;
    }
}

int problem_UVa11832(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    int transNumber = 0;
    
    while (std::cin >> transNumber >> totalFlow) {
        if (transNumber == 0 && totalFlow == 0)
            break;
        memset(memo, -1, sizeof memo);
        transVec.assign(transNumber, 0);
        
        REP(i, transNumber) {
            std::cin >> transVec[i];
        }

        resVec.assign(transNumber, 0);
        std::string tt = decodeTrans();
        std::cout << tt << std::endl;
    }
    
    return 0;
}
