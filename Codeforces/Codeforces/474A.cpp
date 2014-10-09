//
//  474A.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 06/10/14.
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
//#include <string>


// 474A - Krot i lapki
// Method: Implementation

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

    std::vector<std::string> strVec = { "qwertyuiop", "asdfghjkl;", "zxcvbnm,./" };
    
    std::string chooseStr(char c) {
        for (auto str : strVec) {
            if (str.find(c) != string::npos)
                return str;
        }
        std::abort();
    }
}

int problem_474A(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(false);
    
    std::string shiftStr;
    std::getline(std::cin, shiftStr);
    
    int shift = 0;
    if (shiftStr[0] == 'L')
        shift = 1;
    if (shiftStr[0] == 'R')
        shift = -1;

    std::string encText;
    std::getline(std::cin, encText);
    std::string text;
    
    REP(i, encText.size()) {
        string str = chooseStr(encText[i]);
        
        int idx = str.find(encText[i]);
        idx += shift;
        if (idx < 0 || idx >= str.size()) {
            text += "*";
        } else {
            text += str[idx];
        }
    }
    std::cout << text << std::endl;
    return 0;
}
