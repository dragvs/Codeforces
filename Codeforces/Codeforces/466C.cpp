//
//  466C.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 19/09/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>


// Number of ways

// Straightforward(?) but bad performance and memory complexity
static unsigned long long calcNumberOfWays(int numbersCount, long* numbersArr) {
    using int_t = long long;
    unsigned long long numberOfWays = 0;
    
    if (numbersCount < 3)
        return numberOfWays;
    
    // firstIdx, secondIdx   --   [0; first)+[first;second]+(second;count-1]
    //
    // 1 2 3 0 3
    // 1 3 6 6 9
    //
    // 0 1 -1 0
    // 0 1  0 0
    int_t* subtotalsArr = new int_t[numbersCount];
    subtotalsArr[0] = numbersArr[0];
    
    std::map<int_t, std::vector<int>> subtotalIndexesMap;
    subtotalIndexesMap.insert(std::make_pair(subtotalsArr[0], std::vector<int>{ 0 }));
    
    for (int i = 1; i < numbersCount; ++i) {
        subtotalsArr[i] = subtotalsArr[i-1] + numbersArr[i];
        
        std::vector<int>& indexesVec = subtotalIndexesMap[subtotalsArr[i]];
        indexesVec.push_back(i);
    }
    int_t totalSum = subtotalsArr[numbersCount-1];
    
    // Calc number of ways
    for (int firstIdx = 1; firstIdx < numbersCount-1; ++firstIdx) {
        int_t leftSum = subtotalsArr[firstIdx-1];

        if ((leftSum * 3 == totalSum && leftSum != 0) || (leftSum == 0 && totalSum == 0))
        {
            int_t centerSubtotal = leftSum * 2;
            std::vector<int>& indexesVec = subtotalIndexesMap[centerSubtotal];
            auto indexesIter = std::lower_bound(indexesVec.cbegin(), indexesVec.cend(), firstIdx);
            
            if (indexesIter != indexesVec.cend()) {
                long indexesCount = std::distance(indexesIter, indexesVec.cend());
                
                if (indexesVec.back() == numbersCount-1) // Last element isn't in secondIdx range
                    --indexesCount;
                
                numberOfWays += indexesCount;
            }
        }
    }
    
    return numberOfWays;
}

int problem_466C(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    // 1 <= n <= 5*10^5
    // |a[i]| <= 10^9
    int numbersCount;
    std::cin >> numbersCount;
    
    long* numbersArr = new long[numbersCount];
    for (int i = 0; i < numbersCount; ++i) {
        scanf("%ld", &numbersArr[i]);
    }
    
    auto numberOfWays = calcNumberOfWays(numbersCount, numbersArr);
    std::cout << numberOfWays << std::endl;
    return 0;
}
