// problem statement is in https://www.hackerrank.com/challenges/halloween-party/problem
#include <bits/stdc++.h>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
freopen("../input_files/GemStones", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        unsigned long long a,b;
        cin >> a;
        b = (a/2) * ((a+1)/2);
        cout << b << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
