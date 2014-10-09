//
//  UVa562.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 30/09/14.
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


// 562 - Dividing coins
// Method: DP, knapsack 0-1

namespace {
    using namespace std;
    using ll = long long;
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    
    using ss = std::pair<std::string, std::string>;
    using vss = std::vector<ss>;
    
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ALL(a) begin(a), end(a)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define D(a) cout << #a ": " << a << endl;
}

static int solveKnapsack(const vi& coinsVec, int capacity) {
    std::vector<int> dpStateVec;
    dpStateVec.resize(capacity+1, 0);
    
    int costOfTakenCoins = 0;
    
    for (int i = 0; i < coinsVec.size(); ++i) {
        int coinValue = coinsVec[i];
        
        for (int j = static_cast<int>(dpStateVec.size())-1; j >= 0; --j) {
            if (dpStateVec[j] > 0) {
                int newSum = j + coinValue;
                
                if (newSum <= capacity) {
                    dpStateVec[newSum] = 1;
                    
                    if (newSum > costOfTakenCoins)
                        costOfTakenCoins = newSum;
                }
            } else if (dpStateVec[j] == 0) {
                if (coinValue == j) {
                    dpStateVec[j] = 1;
                    
                    if (coinValue > costOfTakenCoins)
                        costOfTakenCoins = coinValue;
                }
            }
        }
    }
    return costOfTakenCoins;
}

int problem_UVa562(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    int problemsCount = 0;
    std::cin >> problemsCount;
    vi answersVec;
    answersVec.reserve(problemsCount);
    
    while (problemsCount > 0) {
        int bagCoinsCount = 0;
        std::cin >> bagCoinsCount;
        vi coinsVec;
        coinsVec.reserve(bagCoinsCount);
        int coinsTotalCost = 0;
        
        for (int i = 0; i < bagCoinsCount; ++i) {
            int coinValue;
            std::cin >> coinValue;
            
            coinsVec.push_back(coinValue);
            coinsTotalCost += coinValue;
        }
        
        int takenCoinsAmount = solveKnapsack(coinsVec, coinsTotalCost/2);
        int answer = coinsTotalCost - 2*takenCoinsAmount;
        answersVec.push_back(answer);
        
        --problemsCount;
    }
    
    for (int answer : answersVec)
        std::cout << answer << std::endl;
    
    return 0;
}
