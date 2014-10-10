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
    template<typename T, typename U> inline std::pair<T, U> mpair(T a, U b) { return std::make_pair(a, b); }
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
    
    int n;
    vi s;
    int t;
    
    struct Node {
        int min, minCount, gcd;
        
        explicit Node(int min = INF, int minCount = 0, int gcd = 0) : min(min), minCount(minCount), gcd(gcd) {}
    };
    using rmq_t = Node;     // min(s[i]) -> count; gcd
    using rmq_v = std::vector<rmq_t>;
    rmq_v st_min_vec; // segment tree
    
    inline rmq_t combine(const rmq_t& left, const rmq_t& right) {
        rmq_t comb;
        comb.gcd = gcd(left.gcd, right.gcd);
        comb.min = std::min(left.min, right.min);
        if (comb.min == left.min) comb.minCount += left.minCount;
        if (comb.min == right.min) comb.minCount += right.minCount;
        return comb;
    }
    
    void st_min_build(const vi& src, rmq_v& sTree, int n, int nL, int nR) {
        if (nL == nR)
            sTree[n] = Node { src[nL], 1, src[nL] };
        else {
            int nMed = (nL + nR) >> 1;
            st_min_build(src, sTree, n << 1, nL, nMed);
            st_min_build(src, sTree, (n << 1)+1, nMed+1, nR);
            sTree[n] = combine(sTree[n << 1], sTree[(n << 1)+1]);
        }
    }
    
    rmq_t st_min_get(const rmq_v& sTree, int n, int nL, int nR, int reqL, int reqR) {
        if (reqL > reqR)
            return Node{};
        if (reqL == nL && reqR == nR)
            return sTree[n];
        
        int nMed = (nL + nR) >> 1;
        rmq_t left = st_min_get(sTree, n << 1, nL, nMed, reqL, std::min(nMed, reqR));
        rmq_t right = st_min_get(sTree, (n << 1)+1, nMed+1, nR, std::max(nMed+1, reqL), reqR);
        return combine(left, right);
    }
    
    void preprocess() {
        st_min_vec.assign(n*4, Node{});
        st_min_build(s, st_min_vec, 1, 0, (int)s.size()-1);
    }
    
    int solve(int l, int r) {
        auto node = st_min_get(st_min_vec, 1, 0, (int)s.size()-1, l ,r);
        
        int eaten = r - l + 1;
        if (node.min == node.gcd) {
            eaten -= node.minCount;
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
