//
//  471B.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 26/09/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>


// 471B - MUH and Important Things

namespace {
    using ii = std::pair<int, int>;
    using vii = std::vector<ii>;

    void outputTasksSet(vii& tasksVec) {
        for (auto taskPair : tasksVec) {
//            std::cout << taskPair.second+1 << "(" << taskPair.first << ")" << " ";
            std::cout << taskPair.second+1 << " ";
        }
        std::cout << std::endl;
    }
}

int problem_471B(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    int tasksNum;
    std::cin >> tasksNum;
    
    vii tasksVec;
    tasksVec.reserve(tasksNum);
    
    for (int i = 0; i < tasksNum; ++i) {
        int taskDifficulty;
        std::cin >> taskDifficulty;
        tasksVec.push_back(std::make_pair(taskDifficulty, i));
    }
    
    auto diffCompareLt = [](const ii& pair1, const ii& pair2) {
        return pair1.first < pair2.first;
    };
    auto diffCompareEq = [](const ii& pair1, const ii& pair2) {
        return pair1.first == pair2.first;
    };
    
    std::sort(tasksVec.begin(), tasksVec.end(), diffCompareLt);

    auto iter = std::adjacent_find(tasksVec.begin(), tasksVec.end(), diffCompareEq);
    std::vector<vii> variants;
    
    if (iter != tasksVec.end()) {
        variants.push_back(vii{ tasksVec.begin(), tasksVec.end() });
        
        std::swap(*iter, *(iter+1));
        variants.push_back(vii{ tasksVec.begin(), tasksVec.end() });
        
        iter = std::adjacent_find(++iter, tasksVec.end(), diffCompareEq);
        
        if (iter != tasksVec.end()) {
            std::swap(*iter, *(iter+1));
            variants.push_back(vii{ tasksVec.begin(), tasksVec.end() });
        }
    }
    
    if (variants.size() == 3) {
        std::cout << "YES" << std::endl;
        
        for (auto variant : variants) {
            outputTasksSet(variant);
        }
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}
