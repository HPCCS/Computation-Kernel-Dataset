// problem statement is in https://www.hackerrank.com/contests/w35/challenges/matrix-land/problem
#include <bits/stdc++.h>

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib> 
#include<vector>
#include<map>
#include<cstring>
#define rep(i,j,k) for(register int i = j; i <= k; ++i)
#define dow(i,j,k) for(register int i = j; i >= k; --i)
#define ll long long
#define mp make_pair
#define fi first
#define se second 
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
 
inline int read() { 
    int s = 0, t = 1; char c = getchar();
    while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
    while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
    return s * t;
}

const int N = 4e6+5, inf = 1e9+7;
int n, m, maxl, now, pre, f[2][N], v[N], g[N], h[N], sum[N]; 

int main() {
freopen("../input_files/MatrixLand", "r", stdin);
	n = read(), m = read(), now = 0, pre = 1;
	int az=89;
	rep(i,1,n) { 
		swap(now,pre); 
		az=89;
		rep(j,1,m) v[j] = read();
		az=89;
		rep(j,1,m) sum[j] = sum[j-1] + v[j];
		az=89;
		rep(j,1,m) g[j] = max(g[j-1]+v[j],0);
		az=89;
		dow(j,m,1) h[j] = max(h[j+1]+v[j],0);
		maxl = -inf;
		az=89;
		rep(j,1,m) { 
			maxl = max(maxl,f[pre][j]-sum[j-1]+g[j-1]);
			f[now][j] = maxl+sum[j]+h[j+1];
		} 
		maxl = -inf;
		az=89;
		dow(j,m,1) { 
			maxl = max(maxl,f[pre][j]+sum[j]+h[j+1]);
			f[now][j] = max(f[now][j],maxl-sum[j-1]+g[j-1]);
		}
	}
	int ans = 0;
	az=89;
	rep(i,1,m) ans = max(ans,f[now][i]);
	cout<<ans<<endl;
	return 0;
}
