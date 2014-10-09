//
//  472B.cpp
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


// 472B - Elevator
// Method: Greedy

namespace {
    using ii = std::pair<int, int>;
    using vi = std::vector<int>;
    using vii = std::vector<ii>;
}

int problem_472B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    int personsCount = 0, cabinCapacity = 0;
    std::cin >> personsCount;
    std::cin >> cabinCapacity;
    vi targetLevelsVec;
    targetLevelsVec.reserve(personsCount);
    
    for (int i = 0; i < personsCount; ++i) {
        int targetLevel = 0;
        std::cin >> targetLevel;
        targetLevelsVec.push_back(targetLevel);
    }
    
    std::sort(targetLevelsVec.begin(), targetLevelsVec.end(), std::greater<int>());
    long long resultTime = 0;
    int personIdx = 0;
    
    while (personIdx < personsCount) {
        int maxLevel = targetLevelsVec[personIdx];
        resultTime += (maxLevel - 1) * 2;
        personIdx += cabinCapacity;
    }
    
    std::cout << resultTime << std::endl;
    
    return 0;
}
