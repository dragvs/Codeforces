//
//  UVa10819.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 03/10/14.
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


// 10819 - Trouble of 13-Dots
// Method: DP, bottom-up knapsack 0-1 with memory saving

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
    

//    naive: 2^N combinations, O(N)? per combination?
//
//    favour(item, moneyLeft) -> max favour | total states = N*M, O(1) per state
//
//    favour(N, moneyLeft) = 0
//    favour(item, moneyLeft>MaxMoney) = 0
//    favour(item, moneyLeft) = max(Fav[item] + favour(item+1, moneyLeft+Price[item]), favour(item+1, moneyLeft))
    
    const int Refund = 200;
    const int MaxMoney = 10000+Refund+100;
    int favourMemo[2][MaxMoney];
    
    int getMaxFavour(const vii& itemsVec, const int moneyAmount) {
        if (moneyAmount == 0 || itemsVec.size() == 0)
            return 0;
        
        memset(favourMemo, 0, sizeof favourMemo);

        int prevCol = 0;
        int currentCol = 1;
        if (itemsVec[0].first <= moneyAmount || (itemsVec[0].first > 2000 && itemsVec[0].first-Refund <= moneyAmount))
            favourMemo[0][itemsVec[0].first] = itemsVec[0].second;
        
        FOR(itemIdx, 1, itemsVec.size()) {
            auto& item = itemsVec[itemIdx];
            if (item.first <= moneyAmount || (item.first > 2000 && item.first-Refund <= moneyAmount))
                favourMemo[currentCol][item.first] = item.second;
            
            for (int i = 0; i <= moneyAmount+Refund; ++i) {
                int prevFavour = favourMemo[prevCol][i];
                
                if (prevFavour > 0) {
                    favourMemo[currentCol][i] = std::max(prevFavour, favourMemo[currentCol][i]);
                    int moneyNeeded = i + item.first;
                    
                    if (moneyNeeded <= moneyAmount || (moneyNeeded > 2000 && moneyNeeded-Refund <= moneyAmount))
                    {
                        int newFavour = prevFavour + item.second;
                        favourMemo[currentCol][moneyNeeded] = std::max(favourMemo[currentCol][moneyNeeded], newFavour);
                    }
                }
            }
            std::swap(prevCol, currentCol);
        }
        int maxFavour = 0;
        REP(i, moneyAmount+Refund+1) {
            if (favourMemo[prevCol][i] > maxFavour)
                maxFavour = favourMemo[prevCol][i];
        }
        return maxFavour;
    }
}

int problem_UVa10819(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    vi caseAnswersVec;
    int moneyAmount = 0, itemsNumber = 0;
    
    while (std::cin >> moneyAmount >> itemsNumber) {
//        if (moneyAmount == 0 && itemsNumber == 0)
//            break;
        vii itemsVec;
        itemsVec.reserve(itemsNumber);
        
        REP(i, itemsNumber) {
            ii itemPair;
            std::cin >> itemPair.first >> itemPair.second;
            itemsVec.push_back(itemPair);
        }
        
        caseAnswersVec.push_back(getMaxFavour(itemsVec, moneyAmount));
    }
    
    for (int caseAnswer : caseAnswersVec) {
        std::cout << caseAnswer << std::endl;
    }
    
    return 0;
}
