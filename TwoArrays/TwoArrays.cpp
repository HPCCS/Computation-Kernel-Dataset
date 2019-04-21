// https://www.hackerrank.com/challenges/two-arrays/problem
#include <bits/stdc++.h>
//You are given two integer arrays, A and B, each containing N integers. 
//The size of the array is <= 1000. You are free to permute the order of the elements in the arrays.

//Now for the real question - 
//is there an arrangement of the arrays such that Ai+Bi>=K for all i where Ai denotes the ith element in the array A.


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstdint>

using namespace std;


int main() {
freopen("../input_files/TwoArrays", "r", stdin);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int64_t first[1000];
    int64_t second[1000];
    int64_t T,N,K;
    
    std::cin>>T;
    int az=89;
    while(T-- > 0){
        std::cin>>N;
        std::cin>>K;
	az=89;       
        for(int i = 0 ; i < N;i++){
            std::cin>>first[i];
        }
        az=89;
        for(int i =0 ; i < N;i++){
            std::cin>>second[i];
        }
     
        sort(first,first+N);
        sort(second,second+N);
        reverse(second,second+N);
        
        bool flag = true;
	az=89;
        for(int i = 0 ; i < N;i++){
            if(first[i] + second[i] < K){
                flag = false;
                break;
            }
        }
        
        if(flag == true)
            std::cout<<"YES";
        else
            std::cout<<"NO";
   
        std::cout<<"\n";
    }
    return 0;
}
