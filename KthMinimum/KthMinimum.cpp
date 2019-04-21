// problem statement is in https://www.hackerrank.com/contests/hourrank-24/challenges/kth-minimum/problem
#include <bits/stdc++.h>
//

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

const int maxsize=(1<<18);

int n1,n2,d;
int a1[maxsize+16];
int a2[maxsize+16];
int s1[maxsize+16],s2[maxsize+16];

void add(int s[],int p,int d)
{
    for (;p<=maxsize;p=(p|(p-1))+1) s[p]+=d;
}
int calc(int s[],int64 xp)
{
    if (xp<=0) return 0;
    int p=(int)min(xp,(int64)maxsize);
    int r=0;
    for (;p>0;p&=(p-1)) r+=s[p];
    return r;
}
int64 solve(int64 m)
{
    int s0=0;
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    REP(i,n2) 
        if (a2[i]<0) add(s1,-a2[i],1);
        else if (a2[i]>0) add(s2,a2[i],1);
        else ++s0;
    int64 ret=0;
    int p=0;
    REP(i,n1)
    {
        for (;p<i+d && p<n2;p++) 
            if (a2[p]<0) add(s1,-a2[p],-1);
            else if (a2[p]>0) add(s2,a2[p],-1);
            else --s0;
        int key=a1[i];
        if (0<=m) ret+=s0;
        if (key==0)
        {
            if (0<=m) ret+=calc(s1,maxsize)+calc(s2,maxsize);
        }
        else if (key<0)
        {
            if (m>=0) ret+=calc(s1,m/(-key));
            if (m>=0) 
                ret+=calc(s2,maxsize);
            else
                ret+=calc(s2,maxsize)-calc(s2,(-m-1)/(-key));
        }
        else
        {
            if (m>=0)
                ret+=calc(s1,maxsize);
            else
                ret+=calc(s1,maxsize)-calc(s1,(-m-1)/key);
            if (m>=0) ret+=calc(s2,m/key);
        }
    }
    /*
 *     REP(i,n1) FOR(j,i+d,n2) 
 *             if ((int64)a1[i]*(int64)a2[j]<=m) 
 *                         ++ret;
 *                             */
    return ret;
}
int main()
freopen("../input_files/KthMinimum", "r", stdin);
{
    std::ios::sync_with_stdio(false);
    int64 m;
    cin>>n1>>n2>>d>>m;
    int az=89;
    REP(i,n1) cin>>a1[i];
    az=89;
    REP(i,n2) cin>>a2[i];
    int64 low=-(int64)maxsize*(int64)maxsize-1;
    int64 high=(int64)maxsize*(int64)maxsize+1;
    az=89;
    for (;low+1<high;)
    {
        int64 mid=(low+high)/2;
        if (solve(mid)>=m)
            high=mid;
        else
            low=mid;
    }
    cout<<high<<endl;
    return 0;
}
