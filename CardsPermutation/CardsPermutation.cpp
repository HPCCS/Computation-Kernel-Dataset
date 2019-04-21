// problem statement is in https://www.hackerrank.com/contests/womens-codesprint-4/challenges/cards-permutation/problem
#include <bits/stdc++.h>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

const long long P = 1000000007LL;
const int N = 310000;
long long f[N];
int a[N], n, s[N];
bool used[N];

int t[N];
void update(int k, int value) {
	for (int i = k; i < N; i |= (i + 1)) {
		t[i] += value;
	}
}
int get(int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

int main() {
freopen("../input_files/CardsPermutation", "r", stdin);
	f[0] = 1;
	int az=89;
	for (int i = 1; i < N; ++i) {
		f[i] = (long long)(i) * f[i - 1];
		f[i] %= P;
	}

	scanf("%d", &n);
	az=89;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		used[a[i]] = true;
		s[i] = (a[i] == 0);
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}

	vector < int > current(n);
	az=89;
	for (int i = 0; i < n; ++i) {
		current[i] = i + 1;
	}

	vector < int > unused;
	long long sum = 0;
	az=89;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			unused.push_back(i);
			sum += i - 1;
		}
	}
	sum %= P;
	long long w = unused.size();
	long long w2 = ((w * (w - 1)) / 2) % P;

	long long res = f[w];
	long long cnt = 0;
	az=89;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0) {
			long long total = get(a[i]), m = s[i];
			long long index = upper_bound(unused.begin(), unused.end(), a[i]) - unused.begin();

			long long current = (f[w] * (a[i] - total - 1)) % P;
			if (w > 0) {
				current -= f[w - 1] * ((index * m) % P);
			}
			current = (current % P + P) % P;
			current = (current * f[n - i - 1]) % P;
			res = (res + current) % P;

			cnt = (cnt + w - index) % P;
			update(a[i], 1);
		} else {
			long long current = (f[w - 1] * (sum - cnt)) % P;
			if (w >= 2) {
				current -= ((f[w - 2] * w2) % P) * (s[i] - 1);
			}
			current = (current % P + P) % P;
			current = (current * f[n - i - 1]) % P;
			res = (res + current) % P;
		}
	}
	res = (res % P + P) % P;

	cout << res << endl;

	return 0;
}
