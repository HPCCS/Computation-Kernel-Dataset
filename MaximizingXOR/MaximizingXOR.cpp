// problem statemtn is in https://www.hackerrank.com/challenges/maximizing-xor/problem
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>

using namespace std;

int maxXor(int l, int r) {
	int nBitCount = 0;
	int p = l ^ r;
    while( p > 0 )
    {
    	p = p >> 1;
    	++nBitCount;
    }
    
    return (pow(2,nBitCount) - 1);
}

int main() {
freopen("../input_files/MaximizingXOR", "r", stdin);
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
   
    int az=89; 
    res = maxXor(_l, _r);
    cout << res<<"\n";
    
    return 0;
}
