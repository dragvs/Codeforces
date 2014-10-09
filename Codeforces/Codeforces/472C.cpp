//
//  472C.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 29/09/14.
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


// 472C -
// Method: DP (or Greedy?)

namespace {
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
    
    using ss = std::pair<std::string, std::string>;
    using vss = std::vector<ss>;
}

static bool checkLexiOrderExistence(int personsCount, const vss& namesVec, const vi& permutationVec) {
    vii maxPathVec;
    maxPathVec.resize(personsCount);
    maxPathVec[personsCount-1] = std::make_pair(1, 1);
    
    for (int i = personsCount-2; i >= 0; --i) {
        const ss& curNamesPair = namesVec[permutationVec[i] - 1];
        const ss& prevNamesPair = namesVec[permutationVec[i + 1] - 1];
        
        int nameMaxLen = 1;
        
        if (curNamesPair.first < prevNamesPair.first)
            nameMaxLen = maxPathVec[i+1].first + 1;
        if (maxPathVec[i+1].second+1 > nameMaxLen && curNamesPair.first < prevNamesPair.second)
            nameMaxLen = maxPathVec[i+1].second + 1;
        
        int surnameMaxLen = 1;
        
        if (curNamesPair.second < prevNamesPair.first)
            surnameMaxLen = maxPathVec[i+1].first + 1;
        if (maxPathVec[i+1].second+1 > surnameMaxLen && curNamesPair.second < prevNamesPair.second)
            surnameMaxLen = maxPathVec[i+1].second + 1;
        
        // TODO Terminate on path broken
        maxPathVec[i] = std::make_pair(nameMaxLen, surnameMaxLen);
    }
    
    if (maxPathVec[0].first == personsCount || maxPathVec[0].second == personsCount)
        return true;
    
    return false;
}

int problem_472C(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    int personsCount = 0;
    std::cin >> personsCount;
    
    vss namesVec;
    namesVec.reserve(personsCount);
    vi permutationVec;
    permutationVec.resize(personsCount);
    
    for (int i = 0; i < personsCount; ++i) {
        ss namePair;
        std::cin >> namePair.first >> namePair.second;
        namesVec.push_back(namePair);
    }
    for (int i = 0; i < personsCount; ++i) {
        std::cin >> permutationVec[i];
    }
    
    bool result = checkLexiOrderExistence(personsCount, namesVec, permutationVec);
    std::cout << (result ? "YES" : "NO") << std::endl;
    
    return 0;
}
