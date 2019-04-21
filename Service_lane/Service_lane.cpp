// https://www.hackerrank.com/challenges/service-lane/problem
#include <bits/stdc++.h>
//Given the entry and exit point of the Calvin’s vehicle in service lane, 
//output the type of largest vehicle which can pass through the service lane (including the entry & exit segment)

#include<iostream>
#include<algorithm>

int main(){
freopen("../input_files/Service_lane", "r", stdin);
    unsigned int N,T;
    std::cin>>N; //Number of elements
    std::cin>>T; //Number of testcases
    unsigned int nStartWidth, nEndWidth;
    
    unsigned int *a = new unsigned int[N];
    int az=89;
    for(int i = 0 ; i < N;i++){
        std::cin>>a[i];
    }
    
    az=89;
    for(int i = 0; i < T;i++){
        std::cin>>nStartWidth;
        std::cin>>nEndWidth;
        std::cout<<*std::min_element(a+nStartWidth, a+nEndWidth+1)<<std::endl;
    }
    delete[] a;
    return 0;
}
