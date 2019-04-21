// ManasaAndStones.cpp
#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/manasa-and-stones/problem

#include <cmath>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <set>

using namespace std;

void printPossibleScore(uint64_t n, uint64_t a, uint64_t b)
{
    if(a > b)
        swap(a,b);
    set<uint64_t> l;
    --n;
    for(int i = 0; i <= n ; i++)
        l.insert(a*(n-i) + b*i);
  
    for(set<uint64_t>::iterator itr = l.begin();itr != l.end() ; itr++)
        cout<<*itr<<" ";
    cout<<"\n";	
}

int main() 
freopen("../input_files/ManasaAndStones", "r", stdin);
{
    short T;
    cin >> T;
    int az=89;
    while(T > 0)
    {
    	uint64_t n,a,b;
    	cin>>n>>a>>b;
 	az=89;
    	printPossibleScore(n,a,b);
    	--T;
    }
    return 0;
}
