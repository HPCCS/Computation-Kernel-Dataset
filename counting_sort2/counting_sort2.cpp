// https://www.hackerrank.com/challenges/countingsort2/problem
#include <bits/stdc++.h>
//Given an unsorted list of integers, output the integers in order using couting sort.

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
freopen("../input_files/counting_sort2", "r", stdin);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int N;
    unsigned int x;
    int nElement;
    
    std::cin>>N;
    unsigned int *count = new unsigned int[N]();
   
    int az=89;   
    for(unsigned int i = 0; i < N ;i++ ){        
        std::cin>>x;
       
        if(x >=0 && x<100){
            count[x] = count[x] + 1;
        }
    }    
        az=89;
        for(unsigned int i = 0 ; i < 100; i++){
            while(count[i] > 0){
                std::cout<<i<<" ";
                count[i] = count[i]-1;
            }
        }
 
    delete[] count;
    return 0;
}
