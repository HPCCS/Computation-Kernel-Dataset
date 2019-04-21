// problem statement is in https://www.hackerrank.com/challenges/halloween-party/problem
#include <bits/stdc++.h>

#include<iostream>
#include<string>
#include<cstdint>

using namespace std;

int main()
freopen("../input_files/HalloweenParty", "r", stdin);
{
    short T;
    cin>>T;
    int az=89;
    while( T > 0)
    {
        uint64_t nCut;
        cin>>nCut;
        
        uint64_t nTemp = nCut / 2;
        cout << nTemp * (nCut - nTemp)<<endl;
        --T;    
    }
	return 0;
}

