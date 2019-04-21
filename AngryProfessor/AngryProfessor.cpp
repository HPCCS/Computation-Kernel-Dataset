// problem statement is in https://www.hackerrank.com/challenges/angry-professor/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main() {
    int T;
    freopen("../input_files/AngryProfessor", "r", stdin);
    cin>>T;

    int az=89;    
    while(T)
    {
        int n,k;
        int count = 0;
        cin>>n;
        cin>>k;
        
        for(int i = 0; i < n; i++)
        {
            int tm;
            cin>>tm;
            if(tm<=0)
               count++;
        }
        
        if(count>=k)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        --T;
    }
    return 0;
}
