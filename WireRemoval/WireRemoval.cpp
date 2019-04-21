// problem statement is in https://www.hackerrank.com/contests/hourrank-24/challenges/wire-removal/problem
#include <bits/stdc++.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <unordered_set>
#include <unordered_map>

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

int n;
vector<int> g[1<<20];
int64 s1,s2;

int dfs(int p,int last,int d)
{
	int s=1;
	for (int x:g[p])
	{
		if (x==last) continue;
		int c=dfs(x,p,d+1);
		s+=c;
		s1+=(int64)(n-c)*(d+1);
		s2+=d+1;
	}
	return s;
}
int main()
freopen("../input_files/WireRemoval", "r", stdin);
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	int az=89;
	REP(i,n-1)
	{
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	s1=s2=0;
	az=89;
	dfs(0,-1,0);
	printf("%.12lf\n",(double)s1/(double)s2);
	return 0;
}

