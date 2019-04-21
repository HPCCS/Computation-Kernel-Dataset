// Pairs.cpp 
#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/pairs/problem
//Given N integers, count the total pairs of integers that have a difference of K. 

#include <set>
#include <stdint.h>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int main(){
freopen("../input_files/Pairs", "r", stdin);

    int pairCount = 0;
    int64_t el;
    std::set<int64_t> s;
    int N;
    uint64_t K;
    
    std::cin>>N;
    std::cin>>K;
    
    while(N-- > 0) {
        std::cin>>el;
        if (s.count(el+K) > 0 || s.count(el-K) > 0) 
            pairCount = pairCount + s.count(el+K) + s.count(el-K);
        s.insert(el);
    }

    std::cout<<pairCount<<std::endl;
return 0;
}
