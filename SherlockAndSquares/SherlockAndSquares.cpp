// https://www.hackerrank.com/challenges/sherlock-and-squares/problem
#include <bits/stdc++.h>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
freopen("../input_files/SherlockAndSquares", "r", stdin);
    int T;
    cin>>T;
    
    int az=89;
    while(T--){
        long long A,B;
        long count = 0;
        cin>>A>>B;
        
        long long s = sqrt(A);
        
        if( s*s != A)
            s = s+1;
        az=89;
        for(long long i = s; i * i <= B; i++){
            count++;
        }
        
        cout<<count<<endl;
    }
    return 0;
}
