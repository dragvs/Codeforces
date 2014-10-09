//
//  474F.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 09/10/14.
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


// 474F - Mole & ant genocide
// Method: Segment tree & gcd

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
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    int n;
    vll s;
    int t;
    
    using rmq_t = std::pair<ll, int>;   // min(s[i]) -> count
    using rmq_v = std::vector<rmq_t>;
    rmq_v st_min_vec;
    rmq_v st_gcd_vec; // segment tree for gcd
    
    template<bool IsGcd>
    inline rmq_t combine(const rmq_t& left, const rmq_t& right) {
        if (IsGcd) {
            ll newGcd = gcd(left.first, right.first);
            return std::make_pair(newGcd, 1);
        } else {
            if (left.first < right.first) {
                return left;
            } else if (left.first > right.first) {
                return right;
            }
            return std::make_pair(left.first, left.second + right.second);
        }
    }
    
    template<bool IsGcd>
    void st_min_build(const vll& src, rmq_v& sTree, int n, int nL, int nR) {
        if (nL == nR)
            sTree[n] = std::make_pair(src[nL], 1);
        else {
            int nMed = (nL + nR) >> 1;
            st_min_build<IsGcd>(src, sTree, n << 1, nL, nMed);
            st_min_build<IsGcd>(src, sTree, (n << 1)+1, nMed+1, nR);
            sTree[n] = combine<IsGcd>(sTree[n << 1], sTree[(n << 1)+1]);
        }
    }
    
    template<bool IsGcd>
    rmq_t st_min_get(const rmq_v& sTree, int n, int nL, int nR, int reqL, int reqR) {
        if (reqL > reqR)
            return IsGcd ? std::make_pair(0, 0) : std::make_pair(INF, 0);
        if (reqL == nL && reqR == nR)
            return sTree[n];
        
        int nMed = (nL + nR) >> 1;
        rmq_t leftMin = st_min_get<IsGcd>(sTree, n << 1, nL, nMed, reqL, std::min(nMed, reqR));
        rmq_t rightMin = st_min_get<IsGcd>(sTree, (n << 1)+1, nMed+1, nR, std::max(nMed+1, reqL), reqR);
        return combine<IsGcd>(leftMin, rightMin);
    }
    
    void preprocess() {
        st_min_vec.assign(n*4, std::make_pair(INF, 0));
        st_min_build<false>(s, st_min_vec, 1, 0, (int)s.size()-1);
        
        st_gcd_vec.assign(n*4, std::make_pair(0, 0));
        st_min_build<true>(s, st_gcd_vec, 1, 0, (int)s.size()-1);
    }
    
    int solve(int l, int r) {
        auto minPair = st_min_get<false>(st_min_vec, 1, 0, (int)s.size()-1, l ,r);
        auto gcdPair = st_min_get<true>(st_gcd_vec, 1, 0, (int)s.size()-1, l ,r);
        
        int eaten = r - l + 1;
        if (minPair.first == gcdPair.first) {
            eaten -= minPair.second;
        }
        return eaten;
    }
}

int problem_474F(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    s.assign(n, 0);
    REP(i, n) {
        std::cin >> s[i];
    }
    
    preprocess();
    
    std::cin >> t;
    REP(i, t) {
        int l = 0, r = 0;
        std::cin >> l >> r;
        
        std::cout << solve(l-1, r-1) << std::endl;
    }
    
    return 0;
}
