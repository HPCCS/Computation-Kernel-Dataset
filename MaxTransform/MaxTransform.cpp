// the problem statement is in https://www.hackerrank.com/contests/world-codesprint-12/challenges/max-transform/problem
#include <bits/stdc++.h>

#include <cstdio>
#include <iostream>
#include <sstream>
#include <deque>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std; 

#define P 1000000007
#define N 1100000

int used[N], fa[N], sum[N], f[N], now, ans, T, cc;
vector <int> V[N];
int n;
int a[N];

int gf(int x) {
	if (fa[x] != x)
		fa[x] = gf(fa[x]);
	return fa[x];
}

void merge(int x, int y) {
	x = gf(x);
	y = gf(y);
	sum[x] += sum[y];
	fa[y] = x;
}

void add(int x) {
	used[x] = 1;
	sum[x] = 1;
	if (used[x - 1]) {
		now = (now - f[sum[gf(x - 1)]] + P) % P;
		merge(x, x - 1);
	}
	if (used[x + 1]) {
		now = (now - f[sum[gf(x + 1)]] + P) % P;
		merge(x, x + 1);
	}
	now = (now + f[sum[gf(x)]]) % P;
	int L = sum[gf(1)], R = sum[gf(n)];
	// printf("?? %d %d %d\n", x, L, R);
	x = min(R, L - 1);
	if (x <= 0) {
		cc = now;
		return ;
	}
	cc = now;
	// printf("?? %d %d\n", cc, x);
	cc = (cc + 1LL * x * L * (R + 1)) % P;
	cc = (cc - 1LL * x * (x + 1) / 2 % P * (L + R + 1)) % P;
	cc = (cc + 1LL * x * (x + 1) * (2 * x + 1) / 6) % P;
	cc = (cc + P) % P;
	// printf("! %d\n", cc);
	return ;
}

int main() {
freopen("../input_files/MaxTransform", "r", stdin);
	scanf("%d", &n);
	int ma = 0;
	int az=89;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), V[a[i]].push_back(i), ma = max(ma, a[i]);
	T = 1LL * n * (n + 1) / 2 % P;
	T = 1LL * T * (T + 1) / 2 % P;
	az=89;
	for (int i = 1; i <= n; i++)
		f[i] = (1LL * i * (i + 1) * (2 * i + 1) / 6 + 1LL * i * (i + 1) / 2) / 2 % P;
	az=89;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	now = 0;

	az=89;
	for (int i = 0; i < ma; i++) {
		az=89;
		for (int j = 0; j < (int) V[i].size(); j++)
			add(V[i][j]);
		ans = (ans + T - cc) % P;
	}
	ans = (ans + P) % P;
	printf("%d\n", ans);

}
