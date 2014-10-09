//
//  474C.cpp
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


// 474C - Surok captain
// Method: Complete search

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
    
    int n;
    int posX[4], posY[4];
    int baseX[4], baseY[4];
    
    ll sqrLen(ll x1, ll x2, ll y1, ll y2) {
        return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
    }
    
    ll pointsSqlLen(int p1, int p2) {
        return sqrLen(posX[p1] + baseX[p1], posX[p2] + baseX[p2],
                      posY[p1] + baseY[p1], posY[p2] + baseY[p2]);
    }
    
    bool isCompact() {
        vll lenVec;
        lenVec.push_back(pointsSqlLen(0, 1));
        lenVec.push_back(pointsSqlLen(0, 2));
        lenVec.push_back(pointsSqlLen(0, 3));
        lenVec.push_back(pointsSqlLen(1, 2));
        lenVec.push_back(pointsSqlLen(1, 3));
        lenVec.push_back(pointsSqlLen(2, 3));
        std::sort(ALL(lenVec));
        return (lenVec[0] == lenVec[3]) && (lenVec[3] < lenVec[4]) && (lenVec[4] == lenVec[5]);
    }
    
    void rotateLeft(int idx) {
        int tmp = posX[idx];
        posX[idx] = -posY[idx];
        posY[idx] = tmp;
    }
    
    int getMinSteps() {
        int minSteps = INF;
        
        REP(p1, 4) {
            REP(p2, 4) {
                REP(p3, 4) {
                    REP(p4, 4) {
                        if (isCompact())
                            minSteps = std::min(minSteps, p1 + p2 + p3 + p4);
                        rotateLeft(3);
                    }
                    rotateLeft(2);
                }
                rotateLeft(1);
            }
            rotateLeft(0);
        }
        return minSteps == INF ? -1 : minSteps;
    }
}

int problem_474C(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    REP(i, n) {
        REP(j, 4) {
            std::cin >> posX[j] >> posY[j] >> baseX[j] >> baseY[j];
            posX[j] -= baseX[j];
            posY[j] -= baseY[j];
        }
        
        std::cout << getMinSteps() << std::endl;
    }
    
    return 0;
}
