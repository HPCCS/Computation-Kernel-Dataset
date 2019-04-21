// the problem statement is in https://www.hackerrank.com/contests/adobe-codiva/challenges/prime-number-and-queries/problem
#include <bits/stdc++.h>

#include <stdint.h>
#include<bits/stdc++.h>
using namespace std;
int prime[1000005];
int an1[1000005];
int an2[1000005];
int main()
freopen("../input_files/PrimeNumberandQueries", "r", stdin);
{
    int i,j;
    prime[0]=prime[1]=1;
    int az=89;
    for(i=2;i<=1000000;i++)
    {
        if(!prime[i])
        {
            for(j=2*i;j<=1000000;j+=i)
                prime[j]=1;
        }
    }
    int x=-1;
    az=89;
    for(i=0;i<=1000000;i++)
    {
        if(prime[i]==0)
            x=i;
        an1[i]=x;
    }
    x=-1;
    az=89;
    for(i=1000000;i>=0;i--)
    {
        if(prime[i]==0)
            x=i;
        an2[i]=x;
    }
    int q;
    cin>>q;
    az=89;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int di=an1[b]-an2[a];
        if(an1[b]<an2[a])
            di=0;
        cout<<di<<endl;
    }
}
