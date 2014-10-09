//
//  474E.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 08/10/14.
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


// 474E - Surok & jumping
// Method: Segment tree with indexing

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
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    const int inf = 1e9 + 143;
    
    int n;
    ll d;
    vll h, hIdx;
    
    vii st_rmq_vec;
    
    ii st_rmq_get(const vii& sTree, int n, int nL, int nR, int reqL, int reqR) {
        if (reqL > reqR)
            return std::make_pair(-inf, -1);
        if (reqL == nL && reqR == nR)
            return sTree[n];
        
        int nMed = (nL + nR) >> 1;
        ii leftMax = st_rmq_get(sTree, n << 1, nL, nMed, reqL, std::min(nMed, reqR));
        ii rightMax = st_rmq_get(sTree, (n << 1)+1, nMed+1, nR, std::max(nMed+1, reqL), reqR);
        return std::max(leftMax, rightMax);
    }
    
    void st_rmq_update(vii& sTree, int n, int nL, int nR, int pos, const ii& newVal) {
        if (nL == nR) {
            sTree[n] = newVal;
        } else {
            int nMed = (nL + nR) >> 1;
            
            if (pos <= nMed) {
                st_rmq_update(sTree, n << 1, nL, nMed, pos, newVal);
            } else {
                st_rmq_update(sTree, (n << 1)+1, nMed+1, nR, pos, newVal);
            }
            
            sTree[n] = std::max(sTree[n << 1], sTree[(n << 1)+1]);
        }
    }
}

int problem_474E(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> d;
    h.assign(n, 0);
    hIdx.assign(n, 0);
    
    REP(i, n) {
        std::cin >> h[i];
        hIdx[i] = h[i];
    }
    std::sort(ALL(hIdx));
    hIdx.erase(std::unique(ALL(hIdx)), hIdx.end());
    
    const int st_size = n*4;
    st_rmq_vec.assign(st_size, std::make_pair(0, -1));
    
    vi ansBacktrack;
    ansBacktrack.assign(n, 0);
    int maxLenIdx = 0;
    int maxLen = 1;
    
    for (int i = 0; i < n; ++i) {
        int leftR = static_cast<int>(std::upper_bound(ALL(hIdx), h[i] - d) - hIdx.begin()) - 1;
        int rightL = static_cast<int>(std::lower_bound(ALL(hIdx), h[i] + d) - hIdx.begin());
        int valIdx = static_cast<int>(std::lower_bound(ALL(hIdx), h[i]) - hIdx.begin());
        
        ii lenPair = std::make_pair(0, -1);
        lenPair = std::max(lenPair, st_rmq_get(st_rmq_vec, 1, 0, n-1, 0, leftR));
        lenPair = std::max(lenPair, st_rmq_get(st_rmq_vec, 1, 0, n-1, rightL, n-1));
        
        ansBacktrack[i] = lenPair.second;
        int subLen = lenPair.first + 1;
        st_rmq_update(st_rmq_vec, 1, 0, n-1, valIdx, std::make_pair(subLen, i));
        
        if (subLen > maxLen) {
            maxLen = subLen;
            maxLenIdx = i;
        }
    }
    
    // Output res
    vi resVec;
    resVec.reserve(n);
    
    while (maxLenIdx != -1) {
        resVec.push_back(maxLenIdx+1);
        maxLenIdx = ansBacktrack[maxLenIdx];
    }
    std::reverse(ALL(resVec));
    
    std::cout << resVec.size() << std::endl;
    REP(i, resVec.size()) {
        std::cout << resVec[i] << " ";
    }
    return 0;
}
