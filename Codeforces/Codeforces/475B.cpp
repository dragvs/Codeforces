//
//  475B.cpp
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
#include <stack>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cstring>


// 475B -
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
    
    int readStr(const std::string& str) {
        int res = 0;
        
        REP(i, str.size()) {
            if (str[i] == '-') {
                --res;
            } else if (str[i] == '+') {
                ++res;
            } else {
                abort();
            }
        }
        return res;
    }
    
    struct DecodeState {
        int strIdx;
        int curPos;
        
        explicit DecodeState() : strIdx(0), curPos(0) {}
    };
}

int problem_475B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::string sStr, tStr;
    std::cin >> sStr >> tStr;
    
    int targetPos = readStr(sStr);
    int bingoNumber = 0;
    int totalNumber = 0;
    
    std::stack<DecodeState> decodeStack;
    decodeStack.push(DecodeState {});
    
    while (!decodeStack.empty()) {
        DecodeState state = decodeStack.top();
        decodeStack.pop();
        bool decoded = true;
        
        while (state.strIdx < tStr.size()) {
            char curChar = tStr[state.strIdx];
            ++state.strIdx;
            
            if (curChar == '?') {
                DecodeState dec1 = state;
                DecodeState dec2 = state;
                --dec1.curPos;
                ++dec2.curPos;
                decodeStack.push(dec1);
                decodeStack.push(dec2);
                decoded = false;
                break;
            } else if (curChar == '-') {
                --state.curPos;
            } else if (curChar == '+') {
                ++state.curPos;
            }
        }
        
        if (decoded) {
            ++totalNumber;
            
            if (state.curPos == targetPos)
                ++bingoNumber;
        }
    }
    
    double res = ((double)bingoNumber)/totalNumber;
    printf("%0.12lf\n", res);
    return 0;
}
