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
// Method: Segment tree & gcd, binary search

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
    
    int n;
    vi s;
    int t;
    
    using rmq_t = int;     // gcd
    using rmq_v = std::vector<rmq_t>;
    rmq_v st_gcd_vec; // segment tree for gcd
    
    inline rmq_t combine(const rmq_t& left, const rmq_t& right) {
        return gcd(left, right);
    }
    
    void st_build(const vi& src, rmq_v& sTree, int n, int nL, int nR) {
        if (nL == nR)
            sTree[n] = src[nL];
        else {
            int nMed = (nL + nR) >> 1;
            st_build(src, sTree, n << 1, nL, nMed);
            st_build(src, sTree, (n << 1)+1, nMed+1, nR);
            sTree[n] = combine(sTree[n << 1], sTree[(n << 1)+1]);
        }
    }
    
    rmq_t st_get(const rmq_v& sTree, int n, int nL, int nR, int reqL, int reqR) {
        if (reqL > reqR)
            return 0;
        if (reqL == nL && reqR == nR)
            return sTree[n];
        
        int nMed = (nL + nR) >> 1;
        rmq_t left = st_get(sTree, n << 1, nL, nMed, reqL, std::min(nMed, reqR));
        rmq_t right = st_get(sTree, (n << 1)+1, nMed+1, nR, std::max(nMed+1, reqL), reqR);
        return combine(left, right);
    }
    
    vii min_bindex;
    
    void preprocess() {
        min_bindex.assign(n, mpair(0, 0));
        REP(i, s.size()) {
            min_bindex[i] = mpair(s[i], i);
        }
        std::sort(ALL(min_bindex));
        
        st_gcd_vec.assign(n*4, 0);
        st_build(s, st_gcd_vec, 1, 0, (int)s.size()-1);
    }
    
    int solve(int l, int r) {
        auto gcd = st_get(st_gcd_vec, 1, 0, (int)s.size()-1, l ,r);

        // [leftMinIdx;rightMinIdx]
        int leftMinIdx = (int)(std::lower_bound(ALL(min_bindex), mpair(gcd, l)) - min_bindex.begin());
        int rightMinIdx = (int)(std::upper_bound(ALL(min_bindex), mpair(gcd, r)) - min_bindex.begin()) - 1;
        
        int eaten = r - l + 1;
        if (min_bindex[leftMinIdx].first == gcd) {
            eaten -= (rightMinIdx - leftMinIdx + 1);
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
