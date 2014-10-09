//
//  UVa10616.cpp
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


// 10616 - Divisible Group Sums
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

    
//    naive: 2^N combinations, O(N)? per combination?
//    
//    maxSum = 200 | = ~D*M
//    state(number, toChoose, sum) -> groups count	| total states = N*M*M*D, O(1) per state
//
//    count(number, 0, sum) = (sum/D == 0)?
//    count(N, toChoose, sum) = 0
//    count(number, toChoose, sum) = count(number+1, toChoose, sum) + count(number+1, toChoose-1, sum+N[number])
    
    int divisor = 1;
    ll countMemo[210][15][200];
    
    ll countGroups(const vi& remaindersVec, int number, int toChoose, ll sum) {
        if (countMemo[number][toChoose][sum] != -1)
            return countMemo[number][toChoose][sum];
        
        if (toChoose == 0) {
            return sum%divisor == 0 ? 1 : 0;
        }
        else if (number == remaindersVec.size()) {
            return 0;
        }
        countMemo[number][toChoose][sum] = countGroups(remaindersVec, number+1, toChoose, sum) +
                                        countGroups(remaindersVec, number+1, toChoose-1, sum+remaindersVec[number]);
        return countMemo[number][toChoose][sum];
    }
}

int problem_UVa10616(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::vector<vll> setsAnswerVec;
    setsAnswerVec.reserve(10);
    
    while (true) {
        int numbersCount = 0, queriesCount = 0;
        std::cin >> numbersCount >> queriesCount;
        
        if (numbersCount == 0 && queriesCount == 0)
            break;
        
        vi numbersVec;
        numbersVec.resize(numbersCount, 0);
        vii queriesVec;
        queriesVec.reserve(queriesCount);
        
        REP(i, numbersCount) {
            std::cin >> numbersVec[i];
        }
        REP(i, queriesCount) {
            ii queryPair;
            std::cin >> queryPair.first >> queryPair.second;
            queriesVec.push_back(queryPair);
        }
        
        vll setResultsVec;
        setResultsVec.reserve(queriesCount);
        
        for (auto& queryPair : queriesVec) {
            vi remaindersVec;
            remaindersVec.resize(numbersCount, 0);
            
            REP(i, numbersCount) {
                remaindersVec[i] = numbersVec[i]%queryPair.first;
            }
            
            divisor = queryPair.first;
            memset(countMemo, -1, sizeof countMemo);
            setResultsVec.push_back(countGroups(remaindersVec, 0, queryPair.second, 0));
        }
        setsAnswerVec.push_back(setResultsVec);
    }
    
    REP(setIdx, setsAnswerVec.size()) {
        std::cout << "SET " << (setIdx+1) << ":" << std::endl;
        
        REP(queryIdx, setsAnswerVec[setIdx].size()) {
            std::cout << "QUERY " << (queryIdx+1) << ": " << setsAnswerVec[setIdx][queryIdx] << std::endl;
        }
    }

    return 0;
}
