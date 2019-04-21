// problem statement is in https://www.hackerrank.com/contests/w35/challenges/lucky-purchase/problem
#include <bits/stdc++.h>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
freopen("../input_files/LuckyPurchase", "r", stdin);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    string ans;
    int m=1000000000;
    int az=89;
    while(n--){
     string a;
        int b;
        cin>>a>>b;
        bool ok=true;
        int f=0,s=0,x=b;
	az=89;
        while(b)
        {
             int g=b%10;
            if(g==4)
                f++;
            else if(g==7)
                s++;
            else
                ok=false;
            b=b/10;
        }
        if(ok&&f==s)
        {
                if(m>x)
                {
                    m=x;
                    ans=a;
                }
        }
}
    if(ans.size())
    cout<<ans;
    else
        cout<<"-1";
    return 0;
}
