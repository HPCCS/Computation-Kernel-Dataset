// the problem statement is in https://www.hackerrank.com/contests/infinitum18/challenges/pythagorean-triple/problem
#include <bits/stdc++.h>
//
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
typedef long long int lli;
long long int n,i,j,k;
#define FOR(i,k,n) for (i = k; i < (int)(n); i++)
using namespace std;
int main()
freopen("../input_files/PythagoreanTriple", "r", stdin);
{
    cin>>n;
    cout<<n<<" ";
    if (n==1 || n==2)
    {
        cout<<-1;
        return 0;
    }
    if (n%2) {
        cout<<(n*n)/2<<" "<<1+((n*n)/2);
    }
    
    else
    {
        k=n/2;
        if (n%4==0) {
            cout<<(3*n)/4<<" "<<(5*n)/4;
        }
        else
        {
            i = (k*k)/2;
            j = i+1;
            cout<<(2*i)<<" "<<2*j;
        }
    }
    return 0;
}
