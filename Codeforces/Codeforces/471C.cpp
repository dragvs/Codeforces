//
//  471С.cpp
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


// 471С - MUH and House of Cards

namespace {
    using ii = std::pair<int, int>;
    using vii = std::vector<ii>;
}

int problem_471C(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    long long cardsNumber;
    std::cin >> cardsNumber;
    int levelsNumber = 0;
    int currentLevel = 0;
    
    while (cardsNumber > 0) {
        if (cardsNumber == 2 || ((cardsNumber + 1) % 3) == 0) {
            ++levelsNumber;
        }
        cardsNumber -= 2 + (currentLevel+1) * 3;
        ++currentLevel;
    }
    
    std::cout << levelsNumber << std::endl;
    
    return 0;
}
