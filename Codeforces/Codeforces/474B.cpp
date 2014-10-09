//
//  474B.cpp
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


// 474B - Krot & worms
// Method: Implementation

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
}

int problem_474B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    int hCount = 0;
    std::cin >> hCount;
    
    vll wormsVec;
    wormsVec.reserve(hCount+1);
    ll totalCount = 0;
    
    REP(i, hCount) {
        ll wCount = 0;
        std::cin >> wCount;
        totalCount += wCount;
        wormsVec.push_back(totalCount);
    }
    
    int gwCount = 0;
    std::cin >> gwCount;
    
    std::vector<std::pair<ll, int>> gWormsVec;
    gWormsVec.reserve(gwCount);
    
    vi ansVec;
    ansVec.assign(gwCount, 0);
    
    REP(i, gwCount) {
        std::pair<ll, int> pp;
        std::cin >> pp.first;
        pp.second = i;
        gWormsVec.push_back(pp);
    }
    std::sort(gWormsVec.begin(), gWormsVec.end());
    int hIdx = 0;
    
    for (auto pp : gWormsVec) {
        while (wormsVec[hIdx] < pp.first) {
            ++hIdx;
        }
        ansVec[pp.second] = hIdx+1;
    }

    for (int i : ansVec) {
        std::cout << i << std::endl;
    }
    return 0;
}
