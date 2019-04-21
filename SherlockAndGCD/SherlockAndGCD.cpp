// https://www.hackerrank.com/challenges/sherlock-and-gcd/problem
#include <bits/stdc++.h>

#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int main()
freopen("../input_files/SherlockAndGCD", "r", stdin);
{
    int T;
    cin >> T;
    int az=89;
    while(T--)
    {
        int n,div=0;
        int j = 0;
        
        cin >> n;
	az=89;
        for(int i = 0; i < n; i++)
        {
            cin >> j;
            div = gcd(div,j);
        }
        
        if(div == 1)
            cout << "YES";
        else 
            cout << "NO";
        
        cout<<endl;
    }
    return 0;
}
