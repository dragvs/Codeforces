//
//  471A.cpp
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


// 471A - MUH and Sticks

namespace {
    enum class AnimalType {
        Elephant, Bear, Alien
    };
    
    std::ostream& operator<<(std::ostream& os, AnimalType animalType)
    {
        switch (animalType) {
            case AnimalType::Elephant: os << "Elephant"; break;
            case AnimalType::Bear: os << "Bear"; break;
            case AnimalType::Alien: os << "Alien"; break;
            default : os.setstate(std::ios_base::failbit);
        }
        return os;
    }
    
    AnimalType detectAnimal(std::vector<int>& sticksVec) {
        if (sticksVec.size() != 6)
            return AnimalType::Alien;
        
        std::map<int, int> stickToCountMap;
        
        for (auto stickLen : sticksVec) {
            ++stickToCountMap[stickLen];
        }
        
        AnimalType animal = AnimalType::Alien;
        bool foundLegs = false;
        bool foundElephantBody = false;
        bool foundBearBody = false;
        
        for (auto stickSet : stickToCountMap) {
            // 1 - possible bear
            // 2 - possible elephant
            // 3 - alien
            // 4 - bear/elephant
            // 5 - bear
            // 6 - elephant
            if (stickSet.second == 6) {
                animal = AnimalType::Elephant;
                break;
            } else if (stickSet.second == 5) {
                animal = AnimalType::Bear;
                break;
            } else if (stickSet.second == 4) {
                foundLegs = true;
            } else if (stickSet.second == 3) {
                break;
            } else if (stickSet.second == 2) {
                foundElephantBody = true;
            } else if (stickSet.second == 1) {
                foundBearBody = true;
            }
        }
        
        if (animal == AnimalType::Alien) {
            if (foundLegs && foundBearBody) {
                animal = AnimalType::Bear;
            } else if (foundLegs && foundElephantBody) {
                animal = AnimalType::Elephant;
            }
        }
        
        return animal;
    }
}


int problem_471A(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::vector<int> sticksVec;
    sticksVec.resize(6);
    
    for (int i = 0; i < 6; ++i) {
        std::cin >> sticksVec[i];
    }
    
    auto animal = detectAnimal(sticksVec);
    std::cout << animal << std::endl;
    return 0;
}
